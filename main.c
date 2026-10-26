// APC PROJECT
// Name = HARSHA G
// 260151_015
// DATE = 

#include <stdio.h>
#include "apc.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
		return FAILURE;
	}

	if (validate_operand(argv[1]) == FAILURE ||
		validate_operand(argv[3]) == FAILURE)
	{
		printf("Invalid operand\n");
		return FAILURE;
	}

	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL, *tailR = NULL;

	int sign1;
	int sign2;

	char operator = argv[2][0];

	if (operator != '+' &&
		operator != '-' &&
		operator != 'x' &&
		operator != '*' &&
		operator != '/')
	{
		printf("Invalid operator\n");
		return FAILURE;
	}

	digit_to_list(&head1, &tail1,
				  &head2, &tail2,
				  argv,
				  &sign1, &sign2);

	switch (operator)
	{
	case '+':
	{
		printf("Addition Result = ");

		/*
		 * Same signs
		 */
		if (sign1 == sign2)
		{
			addition(&head1, &tail1,
					 &head2, &tail2,
					 &headR, &tailR);

			if (sign1 == -1)
				printf("-");

			print_list(headR);
		}

		/*
		 * Different signs
		 */
		else
		{
			int result = compare_list(head1, head2);

			if (result == 0)
			{
				printf("0\n");
			}
			else if (result > 0)
			{
				subtraction(&head1, &tail1,
							&head2, &tail2,
							&headR, &tailR);

				if (sign1 == -1)
					printf("-");

				print_list(headR);
			}
			else
			{
				subtraction(&head2, &tail2,
							&head1, &tail1,
							&headR, &tailR);

				if (sign2 == -1)
					printf("-");

				print_list(headR);
			}
		}

		break;
	}

	case '-':
	{
		printf("Subtraction Result = ");

		/*
		 * a - b
		 *
		 * If signs are different:
		 *
		 * (+a) - (-b) = a + b
		 * (-a) - (+b) = -(a + b)
		 */

		if (sign1 != sign2)
		{
			addition(&head1, &tail1,
					 &head2, &tail2,
					 &headR, &tailR);

			if (sign1 == -1)
				printf("-");

			print_list(headR);
		}

		/*
		 * Same signs
		 */
		else
		{
			int result = compare_list(head1, head2);

			if (result == 0)
			{
				printf("0\n");
			}
			else if (result > 0)
			{
				subtraction(&head1, &tail1,
							&head2, &tail2,
							&headR, &tailR);

				if (sign1 == 1)
					print_list(headR);
				else
				{
					printf("-");
					print_list(headR);
				}
			}
			else
			{
				subtraction(&head2, &tail2,
							&head1, &tail1,
							&headR, &tailR);

				if (sign1 == 1)
				{
					printf("-");
					print_list(headR);
				}
				else
				{
					print_list(headR);
				}
			}
		}

		break;
	}

	case '*':
	case 'x':
	{
		printf("Multiplication Result = ");

		multiplication(&head1, &tail1,
					   &head2, &tail2,
					   &headR, &tailR);

		if (sign1 != sign2)
			printf("-");

		print_list(headR);

		break;
	}

	case '/':
	{
		printf("Division Result = ");

		division(&head1, &tail1,
				 &head2, &tail2,
				 &headR, &tailR);

		if (sign1 != sign2)
			printf("-");

		print_list(headR);

		break;
	}

	default:
		printf("Invalid operator\n");
	}

	return SUCCESS;
}