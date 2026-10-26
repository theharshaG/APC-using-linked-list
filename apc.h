#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
} Dlist;

/* Store operands */
void digit_to_list(Dlist **head1, Dlist **tail1,
				   Dlist **head2, Dlist **tail2,
				   char *argv[],
				   int *sign1, int *sign2);

/* List functions */
int insert_first(Dlist **head, Dlist **tail, int data);
int insert_last(Dlist **head, Dlist **tail, int data);

int compare_list(Dlist *head1, Dlist *head2);

// remove leading zero
void remove_leading_zeros(Dlist **head, Dlist **tail);

void print_list(Dlist *head);

// validation
int validate_operand(char *str);

// void remove_leading_zeros(Dlist **head, Dlist **tail);

/* Arithmetic */
int addition(Dlist **head1, Dlist **tail1,
			 Dlist **head2, Dlist **tail2,
			 Dlist **headR, Dlist **tailR);

int subtraction(Dlist **head1, Dlist **tail1,
				Dlist **head2, Dlist **tail2,
				Dlist **headR, Dlist **tailR);

int multiplication(Dlist **head1, Dlist **tail1,
				   Dlist **head2, Dlist **tail2,
				   Dlist **headR, Dlist **tailR);

int division(Dlist **head1, Dlist **tail1,
			 Dlist **head2, Dlist **tail2,
			 Dlist **headR, Dlist **tailR);

#endif