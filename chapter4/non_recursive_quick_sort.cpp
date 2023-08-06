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

void quick_sort_2(int a[], int n)
{
    int l, r, v;
    int low[30], high[30];
    int sp;

    // スタックの初期化
    low[0] = 0;
    high[0] = n - 1;
    sp = 1;

    while (sp > 0)
    {
        // スタックから整列する範囲を取り出す
        sp--;
        l = low[sp];
        r = high[sp];

        // 整列する要素が１つなら何もしない
        if (l >= r)
        {
            continue;
        }
        else
        {
            v = partition(a, l, r);
            // 左右の配列のうち、短い方を先に処理する
            if (v - l < r - v)
            {
                low[sp] = v + 1;
                high[sp++] = r;
                low[sp] = l;
                high[sp++] = v - 1;
            }
            else
            {
                low[sp] = l;
                high[sp++] = v - 1;
                low[sp] = v + 1;
                high[sp++] = r;
            }
        }
    }
}

int main(void)
{
    int a[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
    int n = sizeof(a) / sizeof(a[0]);
    quick_sort_2(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}