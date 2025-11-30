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

void printInOrder(address root)
{
    if (root == Nil)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}

// Soal 2
int hitungJumlahNode(address root)
{
    if (root == Nil)
    {
        return 0;
    }
    else
    {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root)
{
    if (root == Nil)
    {
        return 0;
    }
    else
    {
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
    }
}

int hitungKedalaman(address root, int start)
{
    if (root == Nil)
    {
        return start;
    }
    else
    {
        int hl = hitungKedalaman(root->left, start);
        int hr = hitungKedalaman(root->right, start);
        int maxHeight;
        if (hl > hr)
        {
            maxHeight = hl;
        }
        else
        {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
}