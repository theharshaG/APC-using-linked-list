#include<stdio.h>
#include "apc.h"
status addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1=tail1;
    Dlist *temp2=tail2;
    int carry=0;
    while(temp1!=NULL || temp2!=NULL)
    {
        int num1=0,num2=0;
        if(temp1!=NULL)
            num1=temp1->data;
        if(temp2!=NULL)
            num2=temp2->data;

        int sum=num1+num2+carry;
        int digit=sum%10;
        carry=sum/10;

        if((insert_first(headR,tailR,digit))==failure)
            return failure;

        if(temp1!=NULL)
            temp1=temp1->prev;
        if(temp2!=NULL)
            temp2=temp2->prev;
    }
    if(carry!=0)
    {
        if(insert_first(headR,tailR, carry) == failure)
            return failure;
    }
    return success;
}