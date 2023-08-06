/**
 *基数ソート
 * 1. キーの値を数え上げる
 * 2. 累積度数分布を求める
 * 3. キーを配列bに移す
 * 4. 配列aに移す
 * 5. 1~4を繰り返す
 * 6. 終了
 * 計算量はO(n),領域計算量はO(n)
 */
#include <stdio.h>

#define M 15
#define MASK 0x0f
int count[M + 1];

void radix_sort(unsigned short a[], unsigned short b[], int n)
{
    int i, bit;

    // short型だから16bit
    // 4bitずつ整列を行う
    for (bit = 0; bit < 16; bit += 4)
    {
        for (i = 0; i <= M; i++)
        {
            count[i] = 0;
        }
        // キーの数え上げ
        for (i = 0; i < n; i++)
        {
            count[(a[i] >> bit) & MASK]++;
        }
        // 累積度数分布を求める
        for (i = 0; i < M; i++)
        {
            count[i + 1] += count[i];
        }
        // キーを配列bに移す
        for (i = n - 1; i >= 0; i--)
        {
            b[--count[(a[i] >> bit) & MASK]] = a[i];
        }
        // 配列aに移す
        for (i = 0; i < n; i++)
        {
            a[i] = b[i];
        }
    }
}

int main(void)
{
    unsigned short a[15] = {0x02, 0x0d, 0x43, 0xdf, 0xcc, 0x0a, 0x0f, 0x0c, 0x0b, 0x0e, 0x0d, 0x0a, 0x0f, 0x0c, 0x0b};
    unsigned short b[15];
    // 整列前
    for (int i = 0; i < 15; i++)
    {
        printf("%x ", a[i]);
    }
    printf("\n");
    radix_sort(a, b, 15);
    for (int i = 0; i < 15; i++)
    {
        printf("%x ", b[i]);
    }
    return 0;
}