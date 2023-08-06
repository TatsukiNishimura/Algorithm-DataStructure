/**
 * マージソート
 * 配列の中央を求め、それを境にして左右の配列に分割する
 * 分割した配列に対して再帰的にマージソートを行う
 * それぞれの配列の要素数が1になったら、それらをマージする
 * マージするときには、左右の配列の先頭要素を比較して小さい方を新しい配列に詰めていく
 * 計算量はO(nlogn)
 * 安定なソート
 */
#include <stdio.h>
#define MAX_ELEMENTS 10000
int b[MAX_ELEMENTS];

void merge_sort_array(int a[], int low, int high)
{
    int mid, i, j, k;
    if (low >= high)
    {
        return;
    }
    mid = (low + high) / 2;
    merge_sort_array(a, low, mid);
    merge_sort_array(a, mid + 1, high);
    for (i = low; i <= mid; i++)
    {
        b[i] = a[i];
    }
    // 後半の要素の最大値が中心に来ることで番兵の役割を果たす
    for (i = mid + 1, j = high; i <= high; i++, j--)
    {
        b[i] = a[j];
    }
    i = low;
    j = high;
    for (k = low; k <= high; k++)
    {
        if (b[i] <= b[j])
        {
            a[k] = b[i++];
        }
        else
        {
            a[k] = b[j--];
        }
    }
}

int main(void)
{
    int a[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
    int n = sizeof(a) / sizeof(a[0]);
    merge_sort_array(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}