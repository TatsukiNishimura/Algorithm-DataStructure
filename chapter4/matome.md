# 整列

## 分類

- 内部整列
  主記憶上で整列を行うアルゴリズム
- 外部整列
  外部記憶上で整列を行うアルゴリズム

- 比較による整列
  キーの大小の比較によって交換するアルゴリズム
  最良計算量: O(nlogn)

- 比較によらない整列
  キーの大小の比較によらず、キーの値を直接参照するアルゴリズム
  最良計算量: O(n)
  ビンソートや分布数え上げソート、基数ソートなどがある

## 安定な整列

- 同じキーを持つレコードが 2 つ以上含まれている時それらの位置関係が整列後も変わらないこと

# 比較による整列

## 単純な整列アルゴリズム

- バブルソート
  安定な整列
  計算量は O(n^2)

```cpp
void bubble_sort(int a[], int n)
{
    int i,j,t;
    for(i = 0;i<n - 1;i++)
    {
        for(j = n - 1;j > i;j--)
        {
            if(a[j - 1] > a[j])
            {
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
        }
    }
}
```

- 選択ソート
  安定なアルゴリズムではない
  計算量は O(n^2)

```cpp
void selection_sort(int a[], int n)
{
    int i,j,t, lowest, lowkey;
    for(i=0;i<n-1;i++)
    {
        lowest = i;
        lowkey = a[i];
        for(j=i+1;j<n;j++)
        {
            if(a[j] < lowkey)
            {
                lowest = j;
                lowkey = a[j];
            }
        }
        t = a[i];
        a[i] = a[lowest];
        a[lowest] = t;
    }
}
```

- 挿入ソート
  安定なアルゴリズム
  計算量は O(n^2)

```cpp
void insertion_sort(int a[], int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        j = i;
        while(j>=1 && a[j-1] > a[j])
        {
            t = a[j];
            a[j] = a[j-1];
            a[j-1] = t;
            j--;
        }
    }
}
```
