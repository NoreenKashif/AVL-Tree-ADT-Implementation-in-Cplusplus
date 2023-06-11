#include<iostream>
#include"AVL.h"
using namespace std;
template<typename T>
BTNode<T>* AVL<T>::getRoot()
{
    return root;
}
template<typename T>
AVL<T>::AVL()
{
	root = nullptr;
}
template<typename T>
BTNode<T>* AVL<T>::rightRotate(BTNode<T>* y)
{
    BTNode<T>* x = y->left;
    BTNode<T>* T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(getHeightOfNodes(y->left),
        getHeightOfNodes(y->right)) + 1;
    x->height = max(getHeightOfNodes(x->left),
        getHeightOfNodes(x->right)) + 1;
    return x;
}
template<typename T>
BTNode<T>* AVL<T>::leftRotate(BTNode<T>* x)
{
    BTNode<T>* y = x->right;
    BTNode<T>* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeightOfNodes(x->left),
        getHeightOfNodes(x->right)) + 1;
    y->height = max(getHeightOfNodes(y->left),
        getHeightOfNodes(y->right)) + 1;
    return y;
}
template<typename T>
int AVL<T>::getHeight(BTNode<T>* h1)
{
	int l = 0, r = 0, h = 1;
	if (left && h1->left)
		l = getHeight(h1->left);
	if (right && h1->right)
		r = getHeight(h1->right);
	if (l > r)
		return h + l;
	return h + r;
}
template<typename T>
BTNode<T>* AVL<T>::search(BTNode<T>* p, T key)
{
	if (p->info == key)
	{
		return p;
	}
	if (p->info < key)
		search(root->left, key);
	if (p->info > key)
		search(root->right, key);
}
template<typename T>
int AVL<T>::getBalanceFactor(BTNode<T>* p)
{

	int heightOfLeftNode = getHeightOfNodes(p->left);
	int heightOfRightNode = getHeightOfNodes(p->right);
	int balanceFactor = heightOfLeftNode - heightOfRightNode;
	return balanceFactor;
}
template<typename T>
int AVL<T>::max(int a, int b)
{
    return (a > b) ? a : b;
}
template<typename T>
BTNode<T>* AVL<T>::insert(BTNode<T>* r, T val)
{
	if (r == nullptr)
	{
		r = new BTNode<T>(val);
		return;
	}

    if (val < r->info)
        r->left = insert(r->left, val);
    else if (val > r->info)
        r->right = insert(r->right, val);
    else
        return r;

   
    r->height = 1 + max(height(r->left),
        height(r->right));

    
    int balance = getBalanceFactor(r);

    // Left Left Case
    if (balance > 1 && val < r->left->key)
        return rightRotate(r);

    // Right Right Case
    if (balance < -1 &&  val > r->right->info)
        return leftRotate(r);

    // Left Right Case
    if (balance > 1 && val > r->left->info)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    // Right Left Case
    if (balance < -1 && val < r->right->info)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

   

}
template<typename T>
int AVL<T>::getHeightOfNodes(BTNode<T>* h1)
{
    int l = 0, r = 0, h = 1;
    if(left && h1->left)
        l = getHeightOfNodes(h1->left);
    if(right && h1->right)
        r = getHeightOfNodes(h1->right);
    if(l > r)
        return h + l;
    return h + r;
}
template<typename T>
void AVL<T>::inOrder(BTNode<T>*r)
{
    if (r != NULL)
    {
        inOrder(r->left);
        cout << r->info << ": " << r->height << endl;
        inOrder(r->right);
    }
}