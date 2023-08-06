/**
 * 選択ソート
 * 配列の先頭から順に、最小値を探して、先頭の要素と交換する。
 * その後、先頭を除いた残りの配列に対して、同様の処理を繰り返す。
 * 交換回数は最大でn-1回である。
 * 計算量はO(n^2)
 * 安定でないソート
 */
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
