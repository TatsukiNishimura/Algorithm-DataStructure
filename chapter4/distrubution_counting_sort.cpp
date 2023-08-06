#include <stdio.h>

typedef struct
{
    int key;
    int other;
} DATA;

#define M 15

int count[M + 1];

// 結果は配列bに入れる
void dist_count_sort(DATA a[], DATA b[], int n)
{
    int i;

    for (i = 0; i <= M; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[a[i].key]++;
    }
    // 分布を表示
    for (i = 0; i <= M; i++)
    {
        printf("%d ", count[i]);
    }
    printf("\n");

    for (i = 0; i < M; i++)
    {
        count[i + 1] += count[i];
    }
    // 度数分布に従ってデータを配列aからbにコピーする
    for (i = n - 1; i >= 0; i--)
    {
        b[--count[a[i].key]] = a[i];
        printf("a[%d].key : %d, b[%d]  = a[%d]\n", i, a[i].key, count[a[i].key], i);
    }
}

int main(void)
{
    // 重複を許してデータリストを用意
    DATA a[] = {{1, 0}, {3, 0}, {2, 0}, {2, 0}, {1, 0}, {2, 0}, {3, 0}, {1, 0}, {2, 0}, {2, 0}};
    DATA b[10];
    int n = sizeof(a) / sizeof(a[0]);
    int i;

    dist_count_sort(a, b, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i].key);
    }
    printf("\n");

    return 0;
}