/**
 * バブルソート
 * 1. 配列の末尾から隣り合う要素を比較する
 * 2. 左側の要素が右側の要素より大きければ交換する
 * 3. 1に戻る
 * 4. 1から3を配列の先頭まで繰り返す
 *
 * 計算量はO(n^2)
 * 安定なソート
 */
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