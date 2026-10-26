#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	int sum = 0;
	int carry = 0;

	while (temp1 || temp2)
	{
		sum = carry;

		if (temp1)
		{
			sum += temp1->data;
			temp1 = temp1->prev;
		}

		if (temp2)
		{
			sum += temp2->data;
			temp2 = temp2->prev;
		}

		carry = sum / 10;

		insert_first(headR, tailR, sum % 10);
	}

	if (carry)
		insert_first(headR, tailR, carry);
}
