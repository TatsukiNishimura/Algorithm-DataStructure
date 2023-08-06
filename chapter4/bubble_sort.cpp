#include <stdio.h>

void bubble_sort(int a[], int n)
{
    int i, j, tmp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}

int main(void)
{
    int i;
    int a[] = {3, 2, 4, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    bubble_sort(a, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}