#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename Tipo>
class AVL
{
    class node
    {
    public:
        Tipo data; // store data in AVL
        node *left;
        node *right;
        int height; // the maximum path from specified node to leaves
    };
    node *root = NULL;
    node *rightRotation(node *current)
    {
        node *new_node = current->left;
        current->left = new_node->right;
        new_node->right = current;
        current->height = 1 + max(height(current->left), height(current->right));
        new_node->height = 1 + max(height(new_node->left), height(new_node->right));
        return new_node;
    }
    node *leftRotation(node *current)
    {
        node *new_node = current->right;
        current->right = new_node->left;
        new_node->left = current;
        current->height = 1 + max(height(current->left), height(current->right));
        new_node->height = 1 + max(height(new_node->left), height(new_node->right));
        return new_node;
    }
    node *insertUtility(node *current, Tipo value)
    {
        if (current == NULL)
        {
            node *new_node = new node;
            new_node->data = value;
            new_node->right = NULL;
            new_node->left = NULL;
            new_node->height = 1;
            current = new_node;
            return new_node;
        } // if AVL Tree is not empty
        if (value < current->data)
            current->left = insertUtility(current->left, value);
        else if (value > current->data)
            current->right = insertUtility(current->right, value);
        current->height = 1 + max(height(current->left), height(current->right));
        int balance = height(current->left) - height(current->right);
        if (balance > 1)
        {
            if (value > current->left->data)
            {
                current->left = leftRotation(current->left);
                return rightRotation(current);
            }
            else
            {
                return rightRotation(current);
            }
        }
        else if (balance < -1)
        {
            if (value < current->right->data)
            {
                current->right = rightRotation(current->right);
                return leftRotation(current);
            }
            else
            {
                return leftRotation(current);
            }
        }
        return current;
    }
    node *removeUtility(node *current, Tipo value)
    {
        if (current == NULL)
        {
            cout << "Tree␣is␣Empty" << endl;
            return NULL;
        } // if AVL Tree is not empty
        if (value < current->data)
            current->left = removeUtility(current->left, value);
        else if (value > current->data)
            current->right = removeUtility(current->right, value);
        else
        {
            if (current->left == NULL && current->right == NULL)
            {
                delete current;
                current = NULL;
            }
            else if (current->left != NULL && current->right != NULL)
            {
                int max = maxUtility(current->left);
                current->data = max;
                removeUtility(current->left, max);
            }
            else
            {
                node *child = current;
                if (current->right != NULL)
                {
                    current = current->right;
                }
                else
                {
                    current = current->left;
                }
                child->left = NULL;
                child->right = NULL;
                delete child;
                child = NULL;
            }
        }
        current->height = 1 + max(height(current->left), height(current->right));
        int balance = height(current->left) - height(current->right);
        if (balance > 1)
        {
            if (height(current->left) >= height(current->right))
            {
                return rightRotation(current);
            }
            else
            {
                current->left = leftRotation(current->left);
                return rightRotation(current);
            }
        }
        else if (balance < -1)
        {
            if (height(current->right) >= height(current->left))
            {
                return leftRotation(current);
            }
            else
            {
                current->right = rightRotation(current->right);
                return leftRotation(current);
            }
        }
        return current;
    }

public:
    void insert(T value)
    {
        root = insertUtility(root, value);
    }
    void remove(T value)
    {
        root = removeUtility(root, value);
    }
};