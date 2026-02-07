#include "header.h"

int print_list(APC *head)
{
    if (head == NULL)
    {
        printf("0");
        return LIST_EMPTY;
    }

    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
}
