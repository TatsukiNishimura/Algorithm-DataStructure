# 木構造
## 行きがけ順
1. 根に立ち寄る
2. 左の部分木に移動
3. 右の部分木に移動
## 通りがけ順
1. 左の部分木に移動
2. 根に立ち寄る
3. 右の部分木に移動
## 帰りがけ順
1. 左の部分木に移動
2. 右の部分木に移動
3. 根に立ち寄る

# 逆ポーランド記法
```
1 2 + 3 4 - *
```
みたいなやつ

これは
```
(1+2)*(3-4)
```
と同じ

# 木の実現
- 連結リストを使う

節を表す構造体としてlabel,childをメンバに持つ構造体を用意して、子同士を連結リストで保持しておく