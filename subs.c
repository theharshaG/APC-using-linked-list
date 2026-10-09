#include <stdio.h>
#include "apc.h"

status subs(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int borrow = 0;

    while (temp1 != NULL)
    {
        int num1 = temp1->data - borrow;
        int num2 = 0;

        if (temp2 != NULL)
        {
            num2 = temp2->data;
        }

        if (num1 < num2)
        {
            num1 = num1 + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        int res = num1 - num2;

        if (insert_first(headR, tailR, res) == failure)
        {
            return failure;
        }

        temp1 = temp1->prev;

        if (temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
    }

    return success;
}