#include <stdio.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *headR = NULL;
    Dlist *tailR = NULL;

    if(argc != 4)
    {
        printf("Usage: ./a.out operand1 operator operand2\n");
        return 0;
    }

    if(check_operands(argv[1]) == failure)
    {
        printf("Enter valid number for operand 1\n");
        return 0;
    }

    if(check_operands(argv[3]) == failure)
    {
        printf("Enter valid number for operand 2\n");
        return 0;
    }

    if(check_operator(argv[2]) == failure)
    {
        printf("Enter valid operator (+, -, x, /)\n");
        return 0;
    }

    int sign1 = 1;
    int sign2 = 1;

    if(argv[1][0] == '-')
        sign1 = -1;

    if(argv[3][0] == '-')
        sign2 = -1;

    int start1 = (argv[1][0] == '-') ? 1 : 0;
    int start2 = (argv[3][0] == '-') ? 1 : 0;

    for(int i = start1; argv[1][i]; i++)
    {
        if(insert_last(&head1, &tail1, argv[1][i] - '0') == failure)
            return 0;
    }

    for(int i = start2; argv[3][i]; i++)
    {
        if(insert_last(&head2, &tail2, argv[3][i] - '0') == failure)
            return 0;
    }

    char oper = argv[2][0];
    int result_sign = 1;
    int cmp;

    switch(oper)
    {
        case '+':
            if(sign1 == sign2)
            {
                if(addition(tail1, tail2, &headR, &tailR) == failure)
                {
                    printf("Addition failed\n");
                    return 0;
                }

                result_sign = sign1;
            }
            else
            {
                cmp = compare_lists(head1, head2);

                if(cmp == 0)
                {
                    insert_first(&headR, &tailR, 0);
                    result_sign = 1;
                }
                else if(cmp > 0)
                {
                    if(subs(tail1, tail2, &headR, &tailR) == failure)
                    {
                        printf("Subtraction failed\n");
                        return 0;
                    }

                    result_sign = sign1;
                }
                else
                {
                    if(subs(tail2, tail1, &headR, &tailR) == failure)
                    {
                        printf("Subtraction failed\n");
                        return 0;
                    }

                    result_sign = sign2;
                }
            }
            break;

        case '-':
            sign2 = -sign2;

            if(sign1 == sign2)
            {
                if(addition(tail1, tail2, &headR, &tailR) == failure)
                {
                    printf("Addition failed\n");
                    return 0;
                }

                result_sign = sign1;
            }
            else
            {
                cmp = compare_lists(head1, head2);

                if(cmp == 0)
                {
                    insert_first(&headR, &tailR, 0);
                    result_sign = 1;
                }
                else if(cmp > 0)
                {
                    if(subs(tail1, tail2, &headR, &tailR) == failure)
                    {
                        printf("Subtraction failed\n");
                        return 0;
                    }

                    result_sign = sign1;
                }
                else
                {
                    if(subs(tail2, tail1, &headR, &tailR) == failure)
                    {
                        printf("Subtraction failed\n");
                        return 0;
                    }

                    result_sign = sign2;
                }
            }
            break;

        case 'x':
        case 'X':
            printf("Multiplication not implemented yet\n");
            return 0;

        case '/':
            printf("Division not implemented yet\n");
            return 0;

        default:
            printf("Invalid operator\n");
            return 0;
    }

    if(result_sign == -1)
    {
        // Avoid printing negative zero.
        if(!(headR->data == 0 && headR->next == NULL))
            printf("-");
    }

    print_list(headR);

    return 0;
}