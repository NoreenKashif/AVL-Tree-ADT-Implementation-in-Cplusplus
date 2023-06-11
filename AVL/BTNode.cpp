#include<iostream>
using namespace std;
template<typename T>
struct BTNode
{
	T info;
	int height=1;
	BTNode<T>* left;
	BTNode<T>* right;
	BTNode()
	{
		left = nullptr;
		right = nullptr;
		height = 1;
	}
	BTNode(T val)
	{
		info = val;
		left = nullptr;
		right = nullptr;
		height = 1;

	}
};