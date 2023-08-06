#include <stdio.h>

#define MAX_HEAP 100

// a[0]はつかわない
int a[MAX_HEAP + 1];

// ヒープに入っている要素の個数
int n = 10;

void downheap()
{
    int i, j;
    int val;
    val = a[1];

    i = 1;
    while (i <= n / 2)
    {
        j = i * 2;
        if (j + 1 <= n && a[j] > a[j + 1])
        {
            j++;
        }
        if (val <= a[j])
        {
            break;
        }
        a[i] = a[j];
        i = j;
    }
    a[i] = val;
}

int delete_min()
{
    int val;
    if (n < 1)
    {
        printf("error\n");
        return -1;
    }
    val = a[1];
    a[1] = a[n--];
    downheap();
    return val;
}