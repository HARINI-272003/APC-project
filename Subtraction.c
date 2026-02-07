#include "header.h"

/* Function to subtract two APC numbers (absolute values)
   Assumes first number >= second number */
int subtraction(APC *tail1, APC *tail2, APC **res_head, APC **res_tail)
{
    /* If both lists are empty */
    if (tail1 == NULL && tail2 == NULL)
    {
        return LIST_EMPTY;
    }

    APC *temp1 = tail1;
    APC *temp2 = tail2;

    int diff = 0;
    int borrow = 0;

    /* Subtract digit by digit from LSD */
    while (temp1 || temp2)
    {
        diff = 0;

        if (temp1)
        {
            diff = temp1->data;
            temp1 = temp1->prev;
        }

        diff = diff - borrow;

        if (temp2)
        {
            diff = diff - temp2->data;
            temp2 = temp2->prev;
        }

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        /* Insert result digit at front */
        insert_at_first(res_head, res_tail, diff);
    }

    /* Remove leading zeros */
    while (*res_head && (*res_head)->data == 0 && (*res_head)->next)
    {
        APC *del = *res_head;
        *res_head = (*res_head)->next;
        (*res_head)->prev = NULL;
        free(del);
    }

    /* Update tail if single node */
    if (*res_head && (*res_head)->next == NULL)
        *res_tail = *res_head;

    return SUCCESS;
}
