#include "header.h"

/* Function to multiply two APC numbers (absolute values) */
int multiplication(APC *tail1, APC *tail2, APC **res_head, APC **res_tail)
{
    /* If either list is empty */
    if (tail1 == NULL || tail2 == NULL)
        return LIST_EMPTY;

    APC *t2 = tail2;
    int shift = 0;

    /* Traverse second number from LSD */
    while (t2)
    {
        APC *temp_head = NULL, *temp_tail = NULL;
        APC *t1 = tail1;
        int carry = 0;

        /* Multiply one digit of second number with first number */
        while (t1)
        {
            int prod = (t1->data * t2->data) + carry;
            carry = prod / 10;
            insert_at_first(&temp_head, &temp_tail, prod % 10);
            t1 = t1->prev;
        }

        /* Insert remaining carry */
        if (carry)
            insert_at_first(&temp_head, &temp_tail, carry);

        /* Add shift (zero padding) */
        for (int i = 0; i < shift; i++)
            insert_at_last(&temp_head, &temp_tail, 0);

        /* Add temp result to final result */
        APC *new_head = NULL, *new_tail = NULL;
        addition(*res_tail, temp_tail, &new_head, &new_tail);

        *res_head = new_head;
        *res_tail = new_tail;

        shift++;
        t2 = t2->prev;
    }

    return SUCCESS;
}
