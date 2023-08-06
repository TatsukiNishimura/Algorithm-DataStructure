# シェルソート

O(n^1.25)から O(n^1.5)の間
安定ではない

```cpp
void shell_sort(int a[], int n)
{
    int i,j,h,t;
    // hの初期値を決める
    // h = 3h-1かつh<n/9となる最大のh
    for(h = 1;h<n/9;h = h*3+1)
        ;
    for(;h>0;h/=3)
    {
        // 内側ではh-ソートを行う
        for(i=h;i<n;i++)
        {
            j = i;
            while(j>=h && a[j-h]>a[j])
            {
                t = a[j];
                a[j] = a[j-h];
                a[j-h] = t;
                j -= h;
            }
        }
    }
}
```

# クイックソート

安定ではない
計算量は O(nlogn)

```cpp
int parition(int a[], int l, int r)
{
    int i,j,pivot,t;
    i = l-1;
    j = r;
    pivot = a[r];
    for(;;)
    {
        while(a[++i] < pivot)
            ;
        while(i < --j && pivot < a[j])
            ;
        if(i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[i];
    a[i] = a[r];
    a[r] = t;
    return i;
}

void quick_sort_l(int a[], int l, int r)
{
    int v;
    if(l >= r)
        return;
    v = partition(a,l,r);
    quick_sort_l(a,l,v-1);
    quick_sort_l(a,v+1,r);
}

void quick_sort(int a[], int n)
{
    quick_sort_l(a,0,n-1);
}
```

もっとも高速に実行されるには、ピボットが中央値になるように選ぶ必要がある。

# マージソート

計算量は O(nlogn)
安定なソート

- マージとは
  整列済みの 2 つのデータ列を 1 つの整列されたデータ列に
  まとめる操作のこと

```
merge()
{
    列Cを空にしておく

    while(列Aと列Bの両方が空でない)
    {
        if(列Aの先頭の要素 <= 列Bの先頭の要素)
        {
            列Aの先頭の要素を列Cの末尾に移動
        }
        else
        {
            列Bの先頭の要素を列Cの末尾に移動
        }
    }

    if(列Aが空である)
    {
        列Bの残りの要素を列Cの末尾に移動
    }
    else
    {
        列Aの残りの要素を列Cの末尾に移動
    }
}
```

## 実装

```cpp
#define MAX_ELEMENTS 10000

int b[MAX_ELEMENTS];

void merge_sort_array(int a[], int low, int high)
{
    int mid, i, j, k;
    if(low >= high)
        return;
    // 列を分割する場所を決める
    mid = (low + high) / 2;
    merge_sort_array(a, low, mid);
    merge_sort_array(a, mid + 1, high);
    // 前半の要素をそのまま作業用配列Bにコピー
    for(i = low;i <= mid;i++)
        b[i] = a[i];
    // 後半の要素を逆順に作業用配列Bにコピー
    for(i = mid + 1, j = high;i <= high;i++, j--)
        b[i] = a[j];
    i = low;
    j = high;
    // 作業用配列Bの両端から取り出したデータをマージして配列Aに格納
    for(k = low;k <= high;k++)
    {
        if(b[i] <= b[j])
            a[k] = b[i++];
        else
            a[k] = b[j--];
    }
}
```

```

```
