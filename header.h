#ifndef DLL_H
#define DLL_L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2

#define RED "\033[1;31m"
#define WHITE "\033[1;37m"
#define YELLOW "\033[1;93m"
#define PURPLE "\033[1;95m"
#define RESET "\033[0m"

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} APC;

int insert_at_last(APC **, APC **, int);
int insert_at_first(APC **, APC **, int);
int print_list(APC *);
int compare_lists(APC *, APC *);
int addition(APC *, APC *, APC **, APC **);
int subtraction(APC *, APC *, APC **, APC **);
int multiplication(APC *, APC *, APC **, APC **);
int division(APC *, APC *, APC *, APC *, APC **, APC **);
#endif