#include <stdio.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1=NULL;
    Dlist *head2=NULL;
    Dlist *tail1=NULL;
    Dlist *tail2=NULL;

    Dlist *headR = NULL;
    Dlist *tailR = NULL;

    if(argc != 4)
    {
        printf("Enter valid format: ./a.out operand1 operator operand2\n");
        return 0;
    }

    if((check_operands(argv[1]))==failure)
    {
        printf("Enter valid number for operand 1\n");
        return 0;
    }

    if((check_operands(argv[3]))==failure)
    {
        printf("Enter valid number for operand 2\n");
        return 0;
    }

    if((check_operator(argv[2]))==failure)
    {
        printf("Enter valid operator (+,-,x,/)\n");
        return 0;
    }

    printf("Valid input\n");

    for(int i = 0; argv[1][i]; i++)
    {
        if((insert_last(&head1, &tail1, argv[1][i] - '0'))==failure)
        {
            return 0;
        }
    }

    for(int i = 0; argv[3][i]; i++)
    {
        if((insert_last(&head2, &tail2, argv[3][i] - '0'))==failure)
        {
            return 0;
        }
    }
    print_list(head1);
    print_list(head2);

    char oper = argv[2][0];

    switch(oper)
    {
        case '+':
            addition(tail1, tail2, &headR, &tailR);
            break;

        case '-':
            break;

        case 'x':
        case 'X':
            break;

        case '/':
            break;

        default:
	        printf("Invalid operator\n");
    }
    
    return 0;
}