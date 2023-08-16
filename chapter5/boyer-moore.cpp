#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int bm_search(char *text, char *pattern)
{
    int i, j, k, t, p, skip[256];
    int t_len = strlen(text);
    int p_len = strlen(pattern);

    // スキップテーブルの作成
    for (i = 0; i < 256; i++)
    {
        skip[i] = p_len;
    }
    for (i = 0; i < p_len - 1; i++)
    {
        skip[pattern[i]] = p_len - i - 1;
    }

    // 探索
    i = p_len - 1;
    while (i < t_len)
    {
        t = i;
        p = p_len - 1;
        while (text[t] == pattern[p])
        {
            if (p == 0)
            {
                return t;
            }
            t--;
            p--;
        }
        i += max(skip[text[i]], p_len - p);
    }
    return -1;
}