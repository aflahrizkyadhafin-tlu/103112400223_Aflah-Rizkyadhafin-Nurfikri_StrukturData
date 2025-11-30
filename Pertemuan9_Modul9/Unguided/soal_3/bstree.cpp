#include "bstree.h"

address alokasi(infotype x)
{
    address newNode = new Node();
    newNode->info = x;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

void insertNode(address &root, infotype x)
{
    address newNode = alokasi(x);
    address check = findNode(root, x);

    if (check == Nil)
    {
        if (root == Nil)
        {
            root = newNode;
            return;
        }
        else if (x < root->info)
        {
            insertNode(root->left, x);
        }
        else
        {
            insertNode(root->right, x);
        }
    }
}

address findNode(address root, infotype x)
{
    if (root == Nil)
    {
        return Nil;
    }

    if (x == root->info)
    {
        return root;
    }
    else if (x < root->info)
    {
        return findNode(root->left, x);
    }
    else
    {
        return findNode(root->right, x);
    }
}

void printPreOrder(address root)
{
    if (root == Nil)
    {
        return;
    }
    cout << root->info << " - ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(address root)
{
    if (root == Nil)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->info << " - ";
}