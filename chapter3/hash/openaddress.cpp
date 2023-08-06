#include <stdio.h>

#define KEY int
#define DATA int
#define EMPTY (KEY)0
#define DELETED (KEY)1
#define BUCKET_SIZE 10

typedef struct bucket
{
    KEY key;
    DATA data;
} BUCKET;

BUCKET table[BUCKET_SIZE];

int rehash(int h)
{
    return (h + 1) % BUCKET_SIZE;
}

int hash(KEY key)
{
    return key % BUCKET_SIZE;
}

bool keyequal(KEY a, KEY b)
{
    return a == b;
}

void init()
{
    int i;

    for (i = 0; i < BUCKET_SIZE; i++)
    {
        table[i].key = EMPTY;
    }
}

DATA *find(KEY key)
{
    int h, count;
    KEY k;

    count = 0;
    h = hash(key);
    while ((k = table[h].key) != EMPTY)
    {
        if (k != DELETED && keyequal(key, k))
        {
            return &table[h].data;
        }
        if (++count > BUCKET_SIZE)
        {
            return NULL;
        }
        h = rehash(h);
    }
    return NULL;
}

bool insert(KEY key, DATA *data)
{
    int h, count;
    KEY k;

    count = 0;
    h = hash(key);
    while ((k = table[h].key) != EMPTY && k != DELETED)
    {
        if (keyequal(key, k))
        {
            return false;
        }
        if (++count > BUCKET_SIZE)
        {
            return false;
        }
        h = rehash(h);
    }
    table[h].key = key;
    table[h].data = *data;
    return true;
}

bool delete_cell(KEY key)
{
    int h, count;
    KEY k;

    count = 0;
    h = hash(key);
    while ((k = table[h].key) != EMPTY)
    {
        if (k != DELETED && keyequal(key, k))
        {
            table[h].key = DELETED;
            return true;
        }
        if (++count > BUCKET_SIZE)
        {
            return false;
        }
        h = rehash(h);
    }
    return false;
}

int main(void)
{
    int i;
    KEY keys[] = {10, 13, 23, 20, 28};
    DATA datas[] = {10, 20, 30, 40, 50};

    init();
    for (i = 0; i < 5; i++)
    {
        printf("insert success %s\n", insert(keys[i], &datas[i]) ? "true" : "false");
    }
    for (i = 0; i < 5; i++)
    {
        DATA *p = find(keys[i]);
        printf("%d: %d\n", keys[i], *p);
    }
    delete_cell(13);
    if (find(13) == NULL)
    {
        printf("delete success\n");
    }
    else
    {
        printf("delete failed\n");
    }
    return 0;
}