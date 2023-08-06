/**
 * ビンソートの性質
 * 1. キーの重複が許されない
 * 2. キーの値は0以上M以下の整数である
 * 3. 計算量はO(n)、領域計算量もO(n)
 */
#include <stdio.h>

typedef struct
{
    int key;
    int other;
} DATA;

#define M 100

DATA bin[M + 1];

void bin_sort(DATA a[], int n)
{
    int i, j;

    for (i = 0; i <= M; i++)
    {
        bin[i].key = -1;
    }

    // 配列aのデータを順番にビンに振り分ける
    for (i = 0; i < n; i++)
    {
        bin[a[i].key] = a[i];
        printf("bin[%d] = %d\n", a[i].key, a[i].other);
    }

    // データをビンから昇順に取り出して、配列aに戻す
    j = 0;
    for (i = 0; i <= M; i++)
    {
        if (bin[i].key != -1)
        {
            a[j++] = bin[i];
            printf("a[%d] = %d\n", j - 1, bin[i].other);
        }
    }
}

int main(void)
{
    // キーが重複しないようにデータリストを用意
    DATA a[] = {
        {3, 1},
        {5, 2},
        {1, 3},
        {2, 4},
        {4, 5},
        {0, 6},
        {6, 7},
        {7, 8},
        {8, 9},
        {9, 10},
    };
    int i, n = sizeof(a) / sizeof(a[0]);
    printf("n : %d\n", n);
    bin_sort(a, n);

    for (i = 0; i < n; i++)
    {
        printf("%d %d\n", a[i].key, a[i].other);
    }
    return 0;
}