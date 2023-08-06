#include <stdio.h>

int partition(int a[], int l, int r)
{
    int i, j, pivot, t;
    i = l - 1;
    j = r;
    pivot = a[r];
    for (;;)
    {
        // ポインタiをpivot以上の値のところまで進める
        while (a[++i] < pivot)
        {
            ;
        }
        // ポインタjがiよりも右にある前提のもと、pivotより小さい値のところまで進める
        while (i < --j && pivot < a[j])
        {
            ;
        }
        if (i >= j)
        {
            break;
        }
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[i];
    a[i] = a[r];
    a[r] = t;
    return i;
}

void quick_sort_1(int a[], int l, int r)
{
    int v;
    if (l >= r)
    {
        return;
    }
    v = partition(a, l, r);
    quick_sort_1(a, l, v - 1);
    quick_sort_1(a, v + 1, r);
}

void quick_sort(int a[], int n)
{
    quick_sort_1(a, 0, n - 1);
}

int main(void)
{
    int a[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
    int n = sizeof(a) / sizeof(a[0]);
    quick_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}