# ビンソート

```cpp
typedef struct
{
    int key;
    int other;
}DATA;

#define M 100

DATA bin[M+1];

void bin_sort(DATA a[], int n)
{
    int i,j;
    for(i = 0; i <= M; i++)
        bin[i].key = -1;
    for(i = 0; i < n; i++)
        bin[a[i].key] = a[i];
    j=0;
    for(i = 0; i <= M; i++)
        if(bin[i].key != -1)
            a[j++] = bin[i];
}
```

計算量　 O(n+m)

弱点

- キーの重複が許されない
- キーの取る値の範囲は事前にわかっている必要がある

# 分布数え上げソート

```cpp
typedef struct{
    int key;
    int other;
}DATA;

#define M 100
int count[M+1];

void dist_coun_sort(DATA a[], DATA b[], int n)
{
    int i;
    for(i = 0; i <= M; i++)
        count[i] = 0;
    for(i = 0; i < n; i++)
        count[a[i].key]++;
    for(i = 1; i <= M; i++)
        count[i+1] += count[i];
    for(i = n-1; i >= 0; i--)
        b[--count[a[i].key]] = a[i];
}
```

計算量 O(n+m)

# 基数ソート

```cpp
#define M 15
#define MASK 0b00001111
int count[M+1];

void radix_sort(unsigned short a[], unsigned short b[], int n)
{
    int i, bit;
    // 下位から上位に向かって４ビットずつ４回ループ実行する
    for(bit = 0;bit<16;bit+=4)
    {
        // カウンタをすべて０にする
        for(i = 0; i <= M; i++)
            count[i] = 0;
        // キーを数え上げる
        for(i = 0; i < n; i++)
            count[(a[i]>>bit) & MASK]++;
        // 数え上げたキーの累積度数分布を求める
        for(i = 1; i <= M; i++)
            count[i+1] += count[i];
        //　度数分布に従ってデータを配列aから配列bに移す
        for(i = n-1; i >= 0; i--)
            b[--count[(a[i]>>bit) & MASK]] = a[i];
        // 配列bの内容を配列aに戻す
        for(i = 0; i < n; i++)
            a[i] = b[i];
    }
}
```

計算量 O(n)
