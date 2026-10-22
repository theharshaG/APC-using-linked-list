#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

status multiplication(Dlist *tail1, Dlist *tail2,Dlist **headR, Dlist **tailR)
{
    if (tail1 == NULL || tail2 == NULL ||
        headR == NULL || tailR == NULL)
    {
        return failure;
    }

    int count1 = 0;
    int count2 = 0;

    Dlist *temp;

    // Count digits in the first number
    temp = tail1;
    while (temp != NULL)
    {
        count1++;
        temp = temp->prev;
    }

    // Count digits in the second number
    temp = tail2;
    while (temp != NULL)
    {
        count2++;
        temp = temp->prev;
    }

    // Create count1 + count2 zero nodes
    for (int i = 0; i < count1 + count2; i++)
    {
        if (insert_last(headR, tailR, 0) == failure)
        {
            return failure;
        }
    }

    Dlist *temp1 = tail1;
    Dlist *res1 = *tailR;

    while (temp1 != NULL)
    {
        Dlist *temp2 = tail2;
        Dlist *res2 = res1;

        int carry = 0;

        while (temp2 != NULL)
        {
            int product = temp1->data * temp2->data + res2->data + carry;

            res2->data = product % 10;
            carry = product / 10;

            temp2 = temp2->prev;
            res2 = res2->prev;
        }

        // Add any remaining carry
        while (carry != 0 && res2 != NULL)
        {
            int sum = res2->data + carry;

            res2->data = sum % 10;
            carry = sum / 10;

            res2 = res2->prev;
        }

        temp1 = temp1->prev;
        res1 = res1->prev;
    }

    // Remove leading zeros
    while (*headR != *tailR && (*headR)->data == 0)
    {
        Dlist *del = *headR;

        *headR = (*headR)->next;
        (*headR)->prev = NULL;

        free(del);
    }

    return success;
}