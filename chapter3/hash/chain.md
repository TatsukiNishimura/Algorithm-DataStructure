[return to reading.md](reading.md)

## チェイン法

ハッシュのチェイン法（Hash Chaining）は、ハッシュテーブルを実装するための一つの方法です。ハッシュテーブルは、データを効率的に格納し、検索するためのデータ構造です。

ハッシュのチェイン法では、ハッシュ関数を使用してキーをハッシュ値に変換し、そのハッシュ値に基づいてデータを格納します。複数のデータが同じハッシュ値を持つ場合、それらのデータをリンクリスト（チェイン）でつなげて格納します。具体的な手順は以下の通りです。

キーをハッシュ関数に渡してハッシュ値を計算します。
ハッシュ値を配列のインデックスとして使用し、データを格納する場所を特定します。
同じハッシュ値を持つデータが既に格納されている場合、その位置にあるリンクリストの末尾にデータを追加します。
同じハッシュ値を持つデータが存在しない場合、新しいリンクリストを作成し、データを格納します。
データの検索や削除を行う場合も同様に、ハッシュ関数を使用してハッシュ値を計算し、対応する位置のリンクリストをたどることで行います。

ハッシュのチェイン法は、ハッシュ関数の性能によって効率が左右されます。ハッシュ関数が均等にハッシュ値を分散させることができれば、チェインの長さを最小限に抑えることができます。ただし、ハッシュ値の衝突（異なるキーが同じハッシュ値を持つこと）が発生すると、性能が低下する可能性があります。

ハッシュのチェイン法は一般的に使用されるハッシュテーブルの実装方法の一つであり、検索や挿入の平均的な時間複雑度は O(1)です。ただし、ハッシュ値の衝突が頻繁に発生する場合や、リンクリストの長さが非常に長くなる場合には、性能が低下する可能性がある点に留意する必要があります。

### 探索手順

1. ハッシュの計算
2. ハッシュ値のデータを連結リストで線形探索

### チェイン法の解析

バケット数を B,登録データの数を N とする。

各バケットには平均して N/B 個のデータが格納される。

探索の計算量は、

- ハッシュ値を求めてバケットを決める : O(1)
- バケット内の線形探索 : O(N/B)
- 合計 : O(1) + O(N/B) = O(N/B)

挿入の計算量は、

- 連結リストの先頭に要素を挿入する : O(1)
- キーの重複チェックのために探索 : O(N/B)
- 合計 : O(1) + O(N/B) = O(N/B)

削除の計算量は、

- 連結リストから要素を削除する : O(1)
- キーの重複チェックのために探索 : O(N/B)
- 合計 : O(1) + O(N/B) = O(N/B)

N に対して、B が十分に大きい場合、O(N/B) は O(1) とみなせる。

一方、N に対して、B が十分には大きくない場合、O(N/B) は O(N) とみなせる。
つまり、探索にかかる時間は一定時間とみなせなくなるから、

<strong>チェイン法では高速性を担保するためには十分なバケット数を確保する必要がある。</strong>

# チェイン法の実装

## 構造体

```c++
typedef struct cell
{
    KEY key;
    DATA data;
    struct cell *next;
}CELL;
```

## 探索

```c++
DATA* find(KEY key)
{
    CELL *p;
    for (p = table[hash(key)]; p != NULL; p = p->next) {
        if (keyequal(p->key, key) == 0) {
            return &p->data;
        }
    }
}

```

## 挿入

```c++
int insert(KEY key, DATA data)
{
    CELL *p;
    int h;

    if(find(key) != NULL)
    {
        return 0;
    }

    if ((p = (CELL*)malloc(sizeof(CELL))) == NULL) {
        printf("メモリ不足\n");
    }
    h = hash(key);
    p->key = key;
    p->data = data;
    p->next = table[h];
    table[h] = p;
    return 1;
}

```

## 削除

```c++
int delete(KEY key)
{
    CELL *p, *q;
    int h;

    h = hash(key);
    // パケットが空の場合
    if (table[h] == NULL) {
        return 0;
    }
    // 先頭の場合
    if (keyequal(table[h]->key, key) == 0) {
        p = table[h];
        table[h] = p->next;
        free(p);
        return 1;
    }
    // それ以外
    for (q = table[h], p = q->next; p != NULL; q = p, p = p->next) {
        if (keyequal(p->key, key) == 0) {
            q->next = p->next;
            free(p);
            return 1;
        }
    }
    return 0;
}
```
