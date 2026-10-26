#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1,
				   Dlist **head2, Dlist **tail2,
				   Dlist **headR, Dlist **tailR)
{
	Dlist *ptr2 = *tail2;

	int zeros = 0;

	while (ptr2)
	{
		Dlist *tempH = NULL;
		Dlist *tempT = NULL;

		Dlist *ptr1 = *tail1;
		int carry = 0;

		while (ptr1)
		{
			int prod = ptr1->data * ptr2->data + carry;

			carry = prod / 10;

			insert_first(&tempH, &tempT, prod % 10);

			ptr1 = ptr1->prev;
		}

		if (carry)
			insert_first(&tempH, &tempT, carry);

		/* append zeros */
		for (int i = 0; i < zeros; i++)
		{
			insert_last(&tempH, &tempT, 0);
		}

		/* first partial product */
		if (*headR == NULL)
		{
			*headR = tempH;
			*tailR = tempT;
		}
		else
		{
			Dlist *newH = NULL;
			Dlist *newT = NULL;

			addition(headR, tailR,
					 &tempH, &tempT,
					 &newH, &newT);

			*headR = newH;
			*tailR = newT;
		}

		zeros++;
		ptr2 = ptr2->prev;
	}

	return SUCCESS;
}