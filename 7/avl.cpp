#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int key, height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct Node *rotateLeft(Node *y)
{
    Node *x = y->right;
    Node *t2 = x->left;

    x->left = y;
    y->right = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->right), height(x->left)) + 1;

    return x;
}

struct Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->right), height(x->left)) + 1;

    return x;
}

struct Node *makeNode(int key)
{
    struct Node *local = (struct Node *)malloc(sizeof(struct Node));
    local->key = key;
    local->left = NULL;
    local->right = NULL;
    local->height = 1;
    return local;
}

int getBalance(Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

struct Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return makeNode(key);
    }

    if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else
    {
        return node;
    }

    node->height = max(height(node->right), height(node->left)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
    {
        return rotateRight(node);
    }

    if (balance > 1 && key > node->left->key)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return rotateLeft(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " : " << root->height << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 
  */

    printf("Preorder traversal of the constructed AVL"
           " tree is \n");
    preOrder(root);

    getchar();

    return 0;
}