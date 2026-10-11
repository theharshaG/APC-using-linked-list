#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

status check_operands(char *argv)
{
    int i=0;
    if(argv[0] == '-')
        i = 1;

    if(argv[i] == '\0')
        return failure;

    for( ;argv[i]; i++)
    {
        if(!(argv[i] >= '0' && argv[i] <= '9'))
        {
            return failure;
        }
    }

    return success;
}

status check_operator(char *argv)
{
    if(argv[0] == '+' || argv[0] == '-' ||
       argv[0] == 'x' || argv[0] == 'X' ||argv[0]=='/' )
    {
        return success;
    }

    return failure;
}

void print_list(Dlist *head)
{
    Dlist *temp = head;

    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

status insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        printf("Memory not allocated\n");
        return failure;
    }

    new->prev=*tail;
    new->data=data;
    new->next=NULL;

    if(*head==NULL && *tail==NULL)
    {
        *head=*tail=new;
    }
    else 
    {
        (*tail)->next=new;
        *tail=new;
    }
    return success;
}

status insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if(new == NULL)
    {
        printf("Memory not allocated\n");
        return failure;
    }

    new->prev = NULL;
    new->data = data;
    new->next = *head;

    if(*head == NULL && *tail == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*head)->prev = new;
        *head = new;
    }

    return success;
}