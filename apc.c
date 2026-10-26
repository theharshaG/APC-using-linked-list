#include <stdio.h>
#include "apc.h"

// insert last
int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }

    return SUCCESS;
}

// insert first
int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*head)->prev = new;
        *head = new;
    }

    return SUCCESS;
}

// compare list function

int compare_list(Dlist *head1, Dlist *head2)
{
    int count1 = 0;
    int count2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    /* Count digits of number 1 */
    while (temp1)
    {
        count1++;
        temp1 = temp1->next;
    }

    /* Count digits of number 2 */
    while (temp2)
    {
        count2++;
        temp2 = temp2->next;
    }

    /* Different number of digits */
    if (count1 > count2)
        return 1;

    if (count1 < count2)
        return -1;

    /* Same number of digits */
    temp1 = head1;
    temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
            return 1;

        if (temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0;
}
// remove extra zeros
void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    /* Keep one zero if number is actually 0 */
    while (*head != NULL &&
           (*head)->data == 0 &&
           (*head)->next != NULL)
    {
        temp = *head;

        *head = (*head)->next;
        (*head)->prev = NULL;

        free(temp);
    }

    /* Update tail */
    if (*head == NULL)
    {
        *tail = NULL;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        *tail = temp;
    }
}

// valiidation
int validate_operand(char *str)
{
    int i = 0;

    /* Skip sign */
    if (str[0] == '+' || str[0] == '-')
        i++;

    /* There must be at least one digit */
    if (str[i] == '\0')
        return FAILURE;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return FAILURE;

        i++;
    }

    return SUCCESS;
}

// print list

void print_list(Dlist *head)
{
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}