#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20

int id_counter = 0;
/*
è dato il tipo dati contact_type, dovrebbe servire ad implementare una rubrica telefonica molto semplice:

#define NAME_LEN 64
#define PHONE_LEN 20

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

scrivere le seguenti funzioni:

// crea un oggetto di tipo contact_type e lo inizializza con name e phone
contact_type * create_contact(char * name, char * phone);

// scrive su stdout i contenuti dell'oggetto
void print_contact(contact_type * person);

.....

// utilizzare questa implementazione di main:

int main(int argc, char *argv[]) {

	contact_type * pino = create_contact("pino rossi", "+393331234567");

	if (pino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	contact_type * gino = create_contact("gino verdi", "+393487654321");

	if (gino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	print_contact(pino);

	print_contact(gino);

	return 0;
}


il risultato dell'esecuzione del programma sarà questo:

person: id=0, name='pino rossi', phone='+393331234567'
person: id=1, name='gino verdi', phone='+393487654321'

*/

typedef struct {
   int id; 						// id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; 	// nome della persona
   char phone[PHONE_LEN + 1]; 	// numero di telefono
} contact_type;


contact_type * create_contact(char * name, char * phone);
void print_contact(contact_type * person);


int main(int argc, char *argv[]) {

	contact_type * pino = create_contact("pino rossi", "+393331234567");

	if (pino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	contact_type * gino = create_contact("gino verdi", "+393487654321");

	if (gino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	print_contact(pino);

	print_contact(gino);

	return 0;
}

contact_type * create_contact(char * name, char * phone) {
	contact_type * new_contact;

	int dim_name = (int) sizeof(name) / sizeof(char);
	int dim_phone = (int) sizeof(phone) / sizeof(char);

	if (dim_name > NAME_LEN) {
		return NULL;
	} else {
		for (int i = 0; i < dim_name; i++)
			new_contact->name[i] = name[i];
	}



	if (dim_phone > PHONE_LEN) {
		return NULL;
	} else {
		for (int i = 0; i < dim_phone; i++)
			new_contact->phone[i] = phone[i];
		for (int i = 0; i < dim_phone; i++)
			printf("%c",new_contact->phone[i]);
	}

	new_contact->id = id_counter++;

	return new_contact;
}
// person: id=0, name='pino rossi', phone='+393331234567'
void print_contact(contact_type * person) {
	int dim_name = (int) sizeof(person->name) / sizeof(char);
	int dim_phone = (int) sizeof(person->phone) / sizeof(char);

	printf("\t person: id=%d, name='", person->id);
	for (int i = 0; i < dim_name; i++)
		printf("%c",person->name[i]);
}



