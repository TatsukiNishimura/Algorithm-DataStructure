#include <stdio.h>

void selection_sort(int a[], int n)
{
    int i, j, min, minkey, tmp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        minkey = a[i];
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < minkey)
            {
                min = j;
                minkey = a[j];
            }
        }

        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

int main(void)
{
    int i;
    int a[] = {3, 2, 4, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    selection_sort(a, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
