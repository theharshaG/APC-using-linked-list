#include <stdio.h>
#include "apc.h"

int compare_lists(Dlist *head1, Dlist *head2)
{
    int len1 = 0;
    int len2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    while(temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }

    while(temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    if(len1 > len2)
        return 1;

    if(len1 < len2)
        return -1;

    temp1 = head1;
    temp2 = head2;

    while(temp1 != NULL)
    {
        if(temp1->data > temp2->data)
            return 1;

        if(temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0;
}