#include "header.h"

/* Function to divide two APC numbers (absolute values)
   Returns quotient only */
int division(APC *head1, APC *tail1,
             APC *head2, APC *tail2,
             APC **res_head, APC **res_tail)
{
    /* Divisor empty check */
    if (head2 == NULL)
        return FAILURE;

    /* Check divisor = 0 */
    APC *t = head2;
    while (t)
    {
        if (t->data != 0)
            break;
        t = t->next;
    }
    if (t == NULL)
        return FAILURE;

    APC *cur = head1;
    APC *temp_head = NULL, *temp_tail = NULL;

    /* Long division */
    while (cur)
    {
        /* Bring down digit */
        insert_at_last(&temp_head, &temp_tail, cur->data);

        int count = 0;

        while (1)
        {
            /* Compare temp and divisor */
            APC *a = temp_head;
            APC *b = head2;
            int la = 0, lb = 0;

            while (a)
            {
                la++;
                a = a->next;
            }
            while (b)
            {
                lb++;
                b = b->next;
            }

            if (la < lb)
                break;

            if (la == lb)
            {
                a = temp_head;
                b = head2;
                int smaller = 0;

                while (a)
                {
                    if (a->data < b->data)
                    {
                        smaller = 1;
                        break;
                    }
                    else if (a->data > b->data)
                        break;

                    a = a->next;
                    b = b->next;
                }
                if (smaller)
                    break;
            }

            /* temp = temp - divisor */
            APC *pa = temp_tail;
            APC *pb = tail2;
            int borrow = 0;

            while (pa)
            {
                int diff = pa->data - borrow - (pb ? pb->data : 0);

                if (diff < 0)
                {
                    diff += 10;
                    borrow = 1;
                }
                else
                {
                    borrow = 0;
                }

                pa->data = diff;
                pa = pa->prev;
                if (pb)
                    pb = pb->prev;
            }

            /* Remove leading zeros in temp */
            while (temp_head && temp_head->data == 0 &&
                   temp_head != temp_tail)
            {
                APC *del = temp_head;
                temp_head = temp_head->next;
                temp_head->prev = NULL;
                free(del);
            }

            count++;
        }

        /* Insert quotient digit */
        insert_at_last(res_head, res_tail, count);

        cur = cur->next;
    }

    /* Remove leading zeros in result */
    while (*res_head && (*res_head)->data == 0 &&
           *res_head != *res_tail)
    {
        APC *del = *res_head;
        *res_head = (*res_head)->next;
        (*res_head)->prev = NULL;
        free(del);
    }

    return SUCCESS;
}
