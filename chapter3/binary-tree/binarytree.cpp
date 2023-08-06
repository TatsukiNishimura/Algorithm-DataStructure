#include <stdio.h>
#include <stdlib.h>

#define KEY int

typedef struct node
{
    KEY data;
    struct node *left;
    struct node *right;
} NODE;

NODE *root = NULL;

NODE *search(KEY key)
{
    NODE *p;
    p = root;
    while (p != NULL)
    {
        if (keyequal(key, p->data))
            return p;
        else if (keylt(key, p->data))
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}

bool keyequal(KEY a, KEY b)
{
    if (a == b)
        return true;
    else
        return false;
}

bool keylt(KEY a, KEY b)
{
    if (a < b)
        return true;
    else
        return false;
}

NODE *insert(KEY key)
{
    NODE **p, *newnode;
    p = &root;

    // 挿入すべき場所まで移動する
    while (*p != NULL)
    {
        if (keyequal(key, (*p)->data))
        {
            return NULL;
        }
        else if (keylt(key, (*p)->data))
        {
            p = &((*p)->left);
        }
        else
        {
            p = &((*p)->right);
        }
    }

    if ((newnode = (NODE *)malloc(sizeof(NODE))) == NULL)
    {
        printf("out of memory");
    }
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    // 挿入すべき場所に挿入する
    *p = newnode;
    return newnode;
}

int delete_node(KEY key)
{
    NODE **p;
    NODE *x;

    p = &root;
    while (*p != NULL)
    {
        if (keyequal(key, (*p)->data))
        {
            x = *p;
            // 葉のとき
            if (x->left == NULL && x->right == NULL)
            {
                *p = NULL;
            }
            // 右の子のみ持つとき
            else if (x->left == NULL)
            {
                *p = x->right;
            }
            // 左の子のみ持つとき
            else if (x->right == NULL)
            {
                *p = x->left;
            }
            // 左も右も子がある
            else
            {
                *p = deletemin(&x->right);
                (*p)->left = x->left;
                (*p)->right = x->right;
            }
            free(x);
            return 1;
        }
        else if (keylt(key, (*p)->data))
        {
            p = &((*p)->left);
        }
        else
        {
            p = &((*p)->right);
        }
    }
}

NODE *deletemin(NODE **p)
{
    NODE *x;
    // 一番小さい値のノードまで移動する
    while ((*p)->left != NULL)
    {
        p = &(*p)->left;
    }
    x = *p;
    *p = (*p)->right;
    return x;
}

int main(void)
{
}