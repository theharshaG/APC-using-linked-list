#ifndef APC_H
#define APC_H

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}Dlist;

typedef enum
{
    success,
    failure
} status;

status check_operands(char *argv);
status check_operator(char *argv);
void print_list(Dlist *head);
status insert_last(Dlist **head, Dlist **tail, int data);
status addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
status insert_first(Dlist **head, Dlist **tail, int data);
status subs(Dlist *tail1,Dlist *tail2,Dlist **headR, Dlist **tailR);
int compare_lists(Dlist *head1, Dlist *head2);
status multiplication(Dlist *tail1, Dlist *tail2,Dlist **headR, Dlist **tailR);
status division(Dlist *head1, Dlist *head2,Dlist **headR, Dlist **tailR);



#endif
