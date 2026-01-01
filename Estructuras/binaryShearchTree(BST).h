#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Every vertex in this BST is a C Struct (to expose all its members publicly)
struct BSTVertex
{
  // all these attributes remain public to slightly simplify the code although this may not be the best practice
  BSTVertex *parent;
  BSTVertex *left;
  BSTVertex *right;
  int key;
  int height; // will be used in AVL lecture
};

// This is just a sample implementation
// There are other ways to implement BST concepts...
class BST
{
protected:
  BSTVertex *root;

  BSTVertex *insert(BSTVertex *T, int v)
  {
    if (T == NULL)
    { // insertion point is found
      T = new BSTVertex;
      T->key = v;
      T->parent = T->left = T->right = NULL;
      T->height = 0; // used in AVL lecture
    }
    else
    {
      if (T->key != v)
      {
        if (T->key < v)
        { // search to the right
          T->right = insert(T->right, v);
          T->right->parent = T;
        }
        else
        { // search to the left
          T->left = insert(T->left, v);
          T->left->parent = T;
        }
      }
    }
    return T; // return the updated BST
  }

  void inorder(BSTVertex *T)
  {
    if (T == NULL)
      return;
    inorder(T->left);      // recursively go to the left
    printf(" %d", T->key); // visit this BST node
    inorder(T->right);     // recursively go to the right
  }

  void preorder(BSTVertex *T)
  {
    if (T == NULL)
      return;
    printf(" %d", T->key); // visit this BST node
    preorder(T->left);     // recursively go to the left
    preorder(T->right);    // recursively go to the right
  }

  int findMin(BSTVertex *T)
  {
    if (T == NULL)
      return -1; // BST is empty, no minimum
    else if (T->left == NULL)
      return T->key; // this is the min
    else
      return findMin(T->left); // go to the left
  }

  int findMax(BSTVertex *T)
  {
    if (T == NULL)
      return -1; // BST is empty, no maximum
    else if (T->right == NULL)
      return T->key; // this is the max
    else
      return findMax(T->right); // go to the right
  }

  int kth(BSTVertex *T, int &k)
  {
    if (T == NULL)
      return -1;
    int leftResult = kth(T->left, k);
    if (leftResult != -1)
      return leftResult;
    if (k == 0)
      return T->key;
    k--;
    return kth(T->right, k);
  }
  int contar(BSTVertex *T)
  {
    if (T == NULL)
      return 0;
    return 1 + contar(T->left) + contar(T->right);
  }
  int Rank(BSTVertex *T, int v)
  {
    if (T == NULL)
      return -1;

    if (v == T->key)
    {
      return 1 + contar(T->left);
    }
    else if (v < T->key)
    {
      return Rank(T->left, v);
    }
    else
    {
      int rightRank = Rank(T->right, v);
      if (rightRank == -1)
        return -1;
      return 1 + contar(T->left) + rightRank;
    }
  }

  BSTVertex *search(BSTVertex *T, int v)
  {
    if (T == NULL)
      return T; // not found
    else if (T->key == v)
      return T; // found
    else if (T->key < v)
      return search(T->right, v); // search to the right
    else
      return search(T->left, v); // search to the left
  }

  int successor(BSTVertex *T)
  {
    if (T->right != NULL)       // we have right subtree
      return findMin(T->right); // this is the successor
    else
    {
      BSTVertex *par = T->parent;
      BSTVertex *cur = T;
      // if par(ent) is not root and cur(rent) is its right children
      while ((par != NULL) && (cur == par->right))
      {
        cur = par; // continue moving up
        par = cur->parent;
      }
      return par == NULL ? -1 : par->key; // this is the successor of T
    }
  }

  int predecessor(BSTVertex *T)
  {
    if (T->left != NULL)       // we have left subtree
      return findMax(T->left); // this is the predecessor
    else
    {
      BSTVertex *par = T->parent;
      BSTVertex *cur = T;
      // if par(ent) is not root and cur(rent) is its left children
      while ((par != NULL) && (cur == par->left))
      {
        cur = par; // continue moving up
        par = cur->parent;
      }
      return par == NULL ? -1 : par->key; // this is the successor of T
    }
  }

  BSTVertex *remove(BSTVertex *T, int v)
  {
    if (T == NULL)
      return T; // cannot find the item

    if (T->key == v)
    {                                          // the node to be deleted
      if (T->left == NULL && T->right == NULL) // this is a leaf
        T = NULL;                              // simply erase this node
      else if (T->left == NULL && T->right != NULL)
      {                               // only one child at right
        T->right->parent = T->parent; // ma, take care of my child
        T = T->right;                 // bypass T
      }
      else if (T->left != NULL && T->right == NULL)
      {                              // only one child at left
        T->left->parent = T->parent; // ma, take care of my child
        T = T->left;                 // bypass T
      }
      else
      {                                          // has two children, find successor to avoid quarrel
        int successorV = successor(v);           // predecessor is also OK btw
        T->key = successorV;                     // replace with successorV
        T->right = remove(T->right, successorV); // delete the old successorV
      }
    }
    else if (T->key < v) // search to the right
      T->right = remove(T->right, v);
    else // search to the left
      T->left = remove(T->left, v);
    return T; // return the updated BST
  }

  // will be used in AVL lecture
  int getHeight(BSTVertex *T)
  {
    if (T == NULL)
      return -1;
    else
      return max(getHeight(T->left), getHeight(T->right)) + 1;
  }

public:
  BST() { root = NULL; }

  void insert(int v) { root = insert(root, v); }

  void inorder()
  {
    inorder(root);
    printf("\n");
  }

  void preorder()
  {
    preorder(root);
    printf("\n");
  }

  int findMin() { return findMin(root); }

  int findMax() { return findMax(root); }

  int search(int v)
  {
    BSTVertex *res = search(root, v);
    return res == NULL ? -1 : res->key;
  }

  int successor(int v)
  {
    BSTVertex *vPos = search(root, v);
    return vPos == NULL ? -1 : successor(vPos);
  }

  int predecessor(int v)
  {
    BSTVertex *vPos = search(root, v);
    return vPos == NULL ? -1 : predecessor(vPos);
  }

  void remove(int v) { root = remove(root, v); }

  // will be used in AVL lecture
  int getHeight() { return getHeight(root); }
};