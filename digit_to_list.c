#include "apc.h"

int get_sign(char *str)
{
    if (str[0] == '-')
        return -1;

    return 1;
}

void digit_to_list(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   char *argv[],
                   int *sign1, int *sign2)
{
    char *num1 = argv[1];
    char *num2 = argv[3];

    int i = 0;

    /* Get signs */
    *sign1 = get_sign(num1);
    *sign2 = get_sign(num2);

    /* Skip + or - */
    if (num1[0] == '+' || num1[0] == '-')
        num1++;

    if (num2[0] == '+' || num2[0] == '-')
        num2++;

    /* Store first number */
    while (num1[i])
    {
        insert_last(head1, tail1, num1[i] - '0');
        i++;
    }

    i = 0;

    /* Store second number */
    while (num2[i])
    {
        insert_last(head2, tail2, num2[i] - '0');
        i++;
    }
}