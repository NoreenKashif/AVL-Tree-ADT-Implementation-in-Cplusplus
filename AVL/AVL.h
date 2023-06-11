#ifndef AVL_H
#define AVL_H
#include"BTNode.cpp"
template<typename T>
class AVL
{
	BTNode<T>* root;
	BTNode<T>* search(BTNode<T>* root, T key);
	int max(int a, int b);
	BTNode<T>* rightRotate(BTNode<T>* y);
	BTNode<T>* leftRotate(BTNode<T>* x);
	int getBalanceFactor(BTNode<T>* p);
public:
	int getHeightOfNodes(BTNode<T>* h1);
	void inOrder(BTNode<T>*);
	AVL();
	BTNode<T>* getRoot();
	BTNode<T>* insert(BTNode<T>* root, T val);
	int getHeight(BTNode<T>* h1);
	
};
#endif

