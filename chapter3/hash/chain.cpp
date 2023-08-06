#include <stdio.h>
#include <stdlib.h>

#define KEY int
#define DATA int
#define BUCKET_SIZE 50

typedef struct cell
{
    KEY key;
    DATA data;
    struct cell *next;
} CELL;

CELL *table[BUCKET_SIZE];

void init()
{
    int i;

    for (i = 0; i < BUCKET_SIZE; i++)
    {
        table[i] = NULL;
    }
}

int hash(KEY key)
{
    return key % BUCKET_SIZE;
}

bool keyequal(KEY a, KEY b)
{
    return a == b;
}

DATA *find(KEY key)
{
    CELL *p;
    int h;

    for (p = table[hash(key)]; p != NULL; p = p->next)
    {
        CELL *p;
        for (p = table[hash(key)]; p != NULL; p = p->next)
        {
            if (keyequal(key, p->key))
            {
                return &p->data;
            }
        }
    }
    return NULL;
}

bool insert(KEY key, DATA data)
{
    CELL *p;
    int h;

    if (find(key) != NULL)
    {
        return false;
    }
    if ((p = (CELL *)malloc(sizeof(CELL))) == NULL)
    {
        fprintf(stderr, "out of memory\n");
        exit(2);
    }
    h = hash(key);
    p->key = key;
    p->data = data;
    // 常に先頭に挿入する
    // （イメージ） [hash値] -> [D | ] -> [C | ] -> [B | ] -> [A |/]
    //                      ↑ここに挿入
    p->next = table[h];
    table[h] = p;
    return true;
}

bool delete_cell(KEY key)
{
    int h;
    CELL *p, *q;
    h = hash(key);
    if (table[h] == NULL)
    {
        return false;
    }
    if (keyequal(key, table[h]->key))
    {
        p = table[h];
        table[h] = p->next;
        free(p);
        return true;
    }
    for (q = table[h], p = q->next; p != NULL; q = p, p = p->next)
    {
        if (keyequal(key, p->key))
        {
            q->next = p->next;
            free(p);
            return true;
        }
    }
    return false;
}

int main(void)
{
    init();
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    insert(4, 40);
    insert(5, 50);
    insert(6, 60);
    DATA *p;
    p = find(1);
    printf("%d\n", *p);
    p = find(2);
    printf("%d\n", *p);
    p = find(3);
    printf("%d\n", *p);
    p = find(4);
}