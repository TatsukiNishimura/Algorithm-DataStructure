#include <stdio.h>

struct node
{
    int value;
    struct node *next;
};

struct node *merge_list(struct node *a, struct node *b)
{
    struct node head, *p;

    p = &head;
    while (a != NULL && b != NULL)
    {
        if (a->value < b->value)
        {
            p->next = a;
            a = a->next;
        }
        else
        {
            p->next = b;
            b = b->next;
        }
    }
}