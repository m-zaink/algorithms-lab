#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b) { return a > b ? a : b; }

int height(struct Node *n)
{
    if (n == NULL)
        return NULL;
    return n->height;
}

struct Node *makeNode(int key)
{
    struct Node *local = (struct Node *)malloc(sizeof(struct Node));
    local->key = key;
    local->left = local->right = NULL;
    local->height = 1;
    return local;
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left, *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *y)
{
    struct Node *x = y->right, *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return makeNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; //empty nodes not allowed.

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if(balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && key < node->right->key) {
        node -> right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}