[return to reading.md](reading.md)

## オープンアドレス法

衝突が発生したとき、別のハッシュ値にデータを格納する方法をオープンアドレス法という。

例: h_k(x) = (h(x) + k) mod m

## 実装

```cpp
typedef struct bucket
{
    KEY key;
    DATA data;
}BUCKET;
```

## rehash

```cpp
int rehash(KEY h)
{
    return (h+1) % BUCKET_SIZE;
}
```

## 探索

```cpp
DATA *find(KEY key)
{
    int h, count;
    KEY k;
    count = 0;
    h = hash(key);
    while((k = table[h].key) != EMPTY)
    {
        // キーが削除済みではなく、キーが一致する場合
        if(k != DELETED && keyequal(key,k))
        {
            return &table[h].data;
        }
        if(++count > BUCKET_SIZE)
        {
            return NULL;
        }
        h = rehash(h);
    }
    return NULL;
}
```

## 挿入

```cpp
int insert(KEY key, DATA* data)
{
    int h, count;
    KEY k;

    count = 0;
    h = hash(key);
    while((k = table[h].key) != EMPTY && k != DELETED)
    {
        if(keyequeal(key, k))
        {
            return 0;
        }
        if(++count > BUCKET_SIZE)
        {
            printf("table is full\n");
        }
        h = rehash(h);
    }
    table[h].key = key;
    table[h].data = *data;
    return 1;
}

```

## 削除

```cpp
int delete(KEY key)
{
    int h, count;
    KEY k;

    count = 0;
    h = hash(key);
    while((k = table[h].key) != EMPTY)
    {
        if(k!= DELETED && keyequal(key,k))
        {
            table[h].key = DELETED;
            return 1;
        }
        if(++count > BUCKET_SIZE)
        {
            return 0;
        }
        h = rehash(h);
    }
    return 0;
}

```
