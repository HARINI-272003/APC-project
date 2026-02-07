#include "header.h"

/* Function to add two APC numbers */
int addition(APC *tail1, APC *tail2, APC **res_head, APC **res_tail)
{
    /* If both lists are empty */
    if (tail1 == NULL && tail2 == NULL)
    {
        return LIST_EMPTY;
    }

    APC *temp1 = tail1;
    APC *temp2 = tail2;

    int sum = 0;
    int carry = 0;

    /* Add digits till both lists end */
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
        sum = sum % 10;

        /* Insert result digit at front */
        insert_at_first(res_head, res_tail, sum);
    }

    /* Insert remaining carry */
    if (carry)
    {
        insert_at_first(res_head, res_tail, carry);
    }

    return SUCCESS;
}
