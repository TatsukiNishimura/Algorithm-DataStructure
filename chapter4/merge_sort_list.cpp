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
            // 連結リストのaの先頭の要素を取り除いて、マージ済み連結リストの末尾に連結する
            p->next = a;
            p = a;
            a = a->next;
        }
        else
        {
            // 連結リストのbの先頭の要素を取り除いて、マージ済み連結リストの末尾に連結する
            p->next = b;
            p = b;
            b = b->next;
        }
    }
    // 残っている要素をマージ済みリストの最後尾に連結する
    if (a == NULL)
    {
        p->next = b;
    }
    else
    {
        p->next = a;
    }
    return head.next;
}

struct node *merge_sort_list(struct node *x)
{
    struct node *a, *b, *p;
    if (x == NULL || x->next == NULL)
    {
        return x;
    }
    a = NULL;
    b = NULL;
    p = NULL;

    a = x;
    b = x->next;
    if (b != NULL)
    {
        b = b->next;
    }

    while (b != NULL)
    {
        a = a->next;
        b = b->next;
        if (b != NULL)
        {
            b = b->next;
        }
    }
    p = a->next;
    a->next = NULL;
    return merge_list(merge_sort_list(x), merge_sort_list(p));
}

int main(void)
{
    struct node a, b, c, d, e, f, g, h, i;
    struct node *p;

    a.value = 1;
    b.value = 3;
    c.value = 5;
    d.value = 7;
    e.value = 9;
    f.value = 2;
    g.value = 4;
    h.value = 6;
    i.value = 8;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &h;
    h.next = &i;
    i.next = NULL;
    p = &a;
    printf("unsorted\n");
    while (p != NULL)
    {
        printf("%d\n", p->value);
        p = p->next;
    }
    printf("sorted\n");
    p = merge_sort_list(&a);
    while (p != NULL)
    {
        printf("%d\n", p->value);
        p = p->next;
    }
    return 0;
}