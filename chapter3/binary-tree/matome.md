# 2分探索木
## 定義
任意の節xについて、左部分木に含まれる要素はxの要素より小さく、右部分木に含まれる要素はxの要素より大きいという条件を満たす木


## 実現
```
typedef struct node{
    KEY data;
    struct node *left;
    struct node *right;
}NODE;
```

```c++
NODE* root;
```
である。

## 探索
```c++
NODE* search(KEY key)
{
    NODE* p;
    p = root;
    while(p != NULL){
        if(keyequal(key,p->data))
        {
            return p;
        }
        else if(keylt(key,p->data))
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return NULL;
}
```
## 挿入

```c++
NODE *insert(KEY key)
{
    // ポインタのポインタ
    NODE **p, **new;
    // pにはrootのアドレスが入る
    p = &root;
    while(*p != NULL){
        if(keyequal(key,(*p)->data))
        {
            return NULL;
        }
        else if(keylt(key,(*p)->data))
        {
            p = &((*p)->left);
        }
        else
        {
            p = &((*p)->right);
        }
    }

    if((new = malloc(sizeof(NODE))) == NULL)
    {
        return NULL;
    }
    new->left = NULL;
    new->right = NULL;
    new->data = key;
    *p = new;
    return new;
}
```
### 復習
変数のアドレスを取得するには&をつける
```c++  
int a = 1;
int *p;
p = &a;
```
ポインタ変数を宣言するには
```c++
int *p;
```
とかく。*はポインタ変数を宣言するときにつける。
ポインタ変数にアドレスを代入するには
```c++
int a = 1;
int *p;
p = &a;
```
関節参照演算子(*)を使うと、ポインタ変数が指している変数の値を取得できる。
```c++
int a = 1;
int *p;
p = &a;
cout << *p << endl; // 1
```

ポインタのポインタを宣言するには
```c++
int **p;
```
とかく。
例えば、
```c++
NODE **p, **new;
p = &root;
```
と書くと、pにはrootのアドレスが入る。ここで、rootはNODE*型の変数なので、rootのアドレスはNODE**型の変数に入る。

また、このとき
```c++
(*p)->data
```
はrootのdataにアクセスすることになる。
なぜなら、アロー演算子は
```c++
p->data == (*p).data
```
であり、今回の場合は
```c++
(*p)->data == (**p).data == root->data
```
となるからである。

さらに、
```c++
&((*p)->left);
```
はrootのleftのアドレスを取得することになる。わかりにくいね。