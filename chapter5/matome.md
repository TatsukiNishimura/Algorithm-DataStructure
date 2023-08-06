# 文字列の探索

## 力任せのアルゴリズム

テキストの長さを n でパターンの長さを m とする。この時の計算量は O(nm)となる。

# 洗練されたアルゴリズム

## KMP 法

計算量は O(n)

## 力任せ法

```cpp
int brute_force_search(char *text, int text_len, char* pattern, int pat_len)
{
    int i,j;
    // テキストのポインタ
    i = 0;
    // パターンのポインタ
    j = 0;

    while(i < text_len && j < pat_len)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    return (j == pat_len) ? (i - j) : -1;
}
```

計算量

- 最悪の場合は O(nm)
- 実質的には O(n)

## KMP 法

計算量は O(n)になるよ

## BM 法

計算量は O(n)になるよ

```cpp
#define uchar unsigned char
#define max(a,b) ((a) > (b) ? (a) : (b))

int bm_search(uchar* text, int text_len, uchar* pattern, int pat_len)
{
    int i, j, skip[256];
    for(i = 0; i < 256; i++)
        skip[i] = pat_len;
    for(i = 0; i < pat_len - 1; i++)
        skip[pattern[i]] = pat_len - i - 1;
    while(i < text_len)
    {
        j = pat_len - 1;
        while(text[i] == pattern[j])
        {
            if(j == 0)
                return i;
            i--;
            j--;
        }
        i += max(skip[text[i]], pat_len - j);
    }
    return -1;
}
```
