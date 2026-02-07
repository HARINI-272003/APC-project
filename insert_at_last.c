#include "header.h"

int insert_at_last(APC **head, APC **tail, int data)
{
    APC *new = malloc(sizeof(APC)); // Create Node
    if (new == NULL)                // Check if node is created or not
    {
        return FAILURE;
    }
    new->data = data; // Update data, head and tail to node
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL && *tail == NULL) // If single node need to be connected
    {
        *head = new;
        *tail = new;
    }
    else // Multiple nodes to be connected
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
    return SUCCESS;
}