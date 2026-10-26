#include "apc.h"

int division(Dlist **head1, Dlist **tail1,
			 Dlist **head2, Dlist **tail2,
			 Dlist **headR, Dlist **tailR)
{
	long long quotient = 0;

	long long num1 = 0;
	long long num2 = 0;

	Dlist *temp = *head1;

	while (temp)
	{
		num1 = num1 * 10 + temp->data;
		temp = temp->next;
	}

	temp = *head2;

	while (temp)
	{
		num2 = num2 * 10 + temp->data;
		temp = temp->next;
	}

	if (num2 == 0)
	{
		printf("Division by zero\n");
		return FAILURE;
	}

	quotient = num1 / num2;

	if (quotient == 0)
	{
		insert_first(headR, tailR, 0);
		return SUCCESS;
	}

	while (quotient)
	{
		insert_first(headR, tailR, quotient % 10);
		quotient /= 10;
	}

	return SUCCESS;
}