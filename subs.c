#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1,
				Dlist **head2, Dlist **tail2,
				Dlist **headR, Dlist **tailR)
{
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	int borrow = 0;
	int diff;

	while (temp1 || temp2)
	{
		int num1 = 0;
		int num2 = 0;

		if (temp1)
		{
			num1 = temp1->data;
			temp1 = temp1->prev;
		}

		if (temp2)
		{
			num2 = temp2->data;
			temp2 = temp2->prev;
		}

		diff = num1 - borrow - num2;

		if (diff < 0)
		{
			diff = diff + 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}

		insert_first(headR, tailR, diff);
	}

	remove_leading_zeros(headR, tailR);

	return SUCCESS;
}