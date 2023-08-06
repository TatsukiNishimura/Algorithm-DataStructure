/**
 * シェルソート
 * 増分hを設定して、h-ソートを行う
 * h-ソートとは、配列の要素をh個おきに取り出して挿入ソートを行うこと
 * h-ソートを行うことで、配列の要素がある程度整列される
 * 1. 増分hを決める
 * 2. h-ソートを行う
 * 3. hを1/3にする
 * 4. 2に戻る
 * 5. hが1になったら、最後に1-ソートを行う
 * 計算量はO(n^1.25)
 * 安定でないソート
 */
#include <stdio.h>

void shell_sort(int a[], int n)
{
    int h, i, j, t;
    // 増分hの初期値を設定
    // h_n = 3 * h_n-1 + 1
    // かつ、h_n < n/9
    for (h = 1; h < n / 9; h = h * 3 + 1)
    {
        ;
    }
    // 増分hを1/3ずつ小さくしていく
    for (; h > 0; h /= 3)
    {
        // h-ソート（挿入ソートのhずつ離れさせた版）
        for (i = h; i < n; i++)
        {
            j = i;
            while (j >= h && a[j - h] > a[j])
            {
                t = a[j];
                a[j] = a[j - h];
                a[j - h] = t;
                j -= h;
            }
        }
    }
}

int main(void)
{
    int a[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
    int n = sizeof(a) / sizeof(a[0]);
    shell_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}