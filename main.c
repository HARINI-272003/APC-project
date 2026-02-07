/*
Name : S HARINI
Date : 03-02-2026
Sample Input:   Two integer values
                An arithmetic operator (+, -, *, /)

Sample Output:  Result of the selected arithmetic operation
                Error message if division by zero is attempted

Description:    The ABC (Arithmetic Based Calculator) project performs basic arithmetic operations such as addition, subtraction, multiplication, and division.
                User inputs are processed using conditional statements, and the result is displayed accurately with proper validation.
*/

#include "header.h"
#include <string.h>

/* ---------- Compare two APC numbers (absolute value) ---------- */
int compare_lists(APC *h1, APC *h2)
{
    int l1 = 0, l2 = 0;
    APC *t;

    for (t = h1; t; t = t->next)
        l1++;
    for (t = h2; t; t = t->next)
        l2++;

    if (l1 > l2)
        return 1;
    if (l1 < l2)
        return -1;

    while (h1 && h2)
    {
        if (h1->data > h2->data)
            return 1;
        if (h1->data < h2->data)
            return -1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return 0;
}

/* ------------------------- MAIN ------------------------- */
int main(int argc, char *argv[])
{
    APC *head1 = NULL, *tail1 = NULL;
    APC *head2 = NULL, *tail2 = NULL;
    APC *result_head = NULL, *result_tail = NULL;

    printf(WHITE "\n-----------------------------------------------------\n" RESET);
    printf(PURPLE "\t::: Arbitrary Precision Calculator :::\n" RESET);
    printf(WHITE "-----------------------------------------------------\n" RESET);

    if (argc == 1)
    {
        printf(YELLOW "Opertions performed in APC are : \n\n" RESET WHITE "1] Addition\n2] Subtraction\n3] Multiplication\n4] Division\n\n" RESET);
        return SUCCESS;
    }
    else if (argc == 4)
    {
        int sign1 = 1, sign2 = 1, res_sign = 1;

        if (argv[1][0] == '-')
            sign1 = -1;
        if (argv[3][0] == '-')
            sign2 = -1;

        /* Create operand 1 list (absolute value only) */
        for (int i = (argv[1][0] == '-'); argv[1][i]; i++)
            insert_at_last(&head1, &tail1, argv[1][i] - '0');

        /* Create operand 2 list (absolute value only) */
        for (int i = (argv[3][0] == '-'); argv[3][i]; i++)
            insert_at_last(&head2, &tail2, argv[3][i] - '0');

        switch (argv[2][0])
        {
        /* ================= ADDITION ================= */
        case '+':
        {
            printf(YELLOW "Operation choosen is ADDITION (+)\n\n" RESET);

            if (sign1 == sign2)
            {
                addition(tail1, tail2, &result_head, &result_tail);
                res_sign = sign1;
            }
            else
            {
                int cmp = compare_lists(head1, head2);
                if (cmp >= 0)
                {
                    subtraction(tail1, tail2, &result_head, &result_tail);
                    res_sign = sign1;
                }
                else
                {
                    subtraction(tail2, tail1, &result_head, &result_tail);
                    res_sign = sign2;
                }
            }

            printf(WHITE "Operand 1 : %s\n" RESET, argv[1]);
            printf(WHITE "Operator  : +\n" RESET);
            printf(WHITE "Operand 2 : %s\n" RESET, argv[3]);

            printf(WHITE "Result    :" RESET PURPLE " ");
            if (res_sign == -1 &&
                !(result_head->data == 0 && result_head == result_tail))
                printf("-");
            print_list(result_head);
            printf("\n\n");
            break;
        }

        /* ================= SUBTRACTION ================= */
        case '-':
        {
            printf(YELLOW "Operation choosen is SUBTRACTION (-)\n\n" RESET);

            if (sign1 != sign2)
            {
                addition(tail1, tail2, &result_head, &result_tail);
                res_sign = sign1;
            }
            else
            {
                int cmp = compare_lists(head1, head2);
                if (cmp >= 0)
                {
                    subtraction(tail1, tail2, &result_head, &result_tail);
                    res_sign = sign1;
                }
                else
                {
                    subtraction(tail2, tail1, &result_head, &result_tail);
                    res_sign = -sign1;
                }
            }

            printf(WHITE "Operand 1 : %s\n" RESET, argv[1]);
            printf(WHITE "Operator  : -\n" RESET);
            printf(WHITE "Operand 2 : %s\n" RESET, argv[3]);

            printf(WHITE "Result    :" RESET PURPLE " ");
            if (res_sign == -1 &&
                !(result_head->data == 0 && result_head == result_tail))
                printf("-");
            print_list(result_head);
            printf("\n\n");
            break;
        }

        /* ================= MULTIPLICATION ================= */
        case 'x':
        {
            printf(YELLOW "Operation choosen is MULTIPLICATION (x)\n\n" RESET);

            multiplication(tail1, tail2, &result_head, &result_tail);
            res_sign = (sign1 == sign2) ? 1 : -1;

            printf(WHITE "Operand 1 : %s\n" RESET, argv[1]);
            printf(WHITE "Operator  : x\n" RESET);
            printf(WHITE "Operand 2 : %s\n" RESET, argv[3]);

            printf(WHITE "Result    :" RESET PURPLE " ");
            if (res_sign == -1 &&
                !(result_head->data == 0 && result_head == result_tail))
                printf("-");
            print_list(result_head);
            printf("\n\n");
            break;
        }

        /* ================= DIVISION ================= */
        case '/':
        {
            printf(YELLOW "Operation choosen is DIVISION (/)\n\n" RESET);

            if (division(head1, tail1, head2, tail2,
                         &result_head, &result_tail) != SUCCESS)
            {
                printf(RED "ERROR: Division Failed\n" RESET);
                return FAILURE;
            }

            res_sign = (sign1 == sign2) ? 1 : -1;

            printf(WHITE "Operand 1 : %s\n" RESET, argv[1]);
            printf(WHITE "Operator  : /\n" RESET);
            printf(WHITE "Operand 2 : %s\n" RESET, argv[3]);

            printf(WHITE "Result    :" RESET PURPLE " ");
            if (res_sign == -1 &&
                !(result_head->data == 0 && result_head == result_tail))
                printf("-");
            print_list(result_head);
            printf("\n\n");
            break;
        }

        default:
            printf(RED "ERROR: Invalid operator" RESET WHITE "Please enter Addition(+), Subtraction(-), Multiplication(x) and Division(/)\n" RESET);
            return FAILURE;
        }
    }
    else
    {
        printf(RED "ERROR: Invalid argument count!!!\n" RESET);
        printf(WHITE "Pass Command line arguments like --> [Operand_1] [Operator] [Operand_2]\n\n" RESET);
        return FAILURE;
    }

    return SUCCESS;
}
