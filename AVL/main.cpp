#include<iostream>
#include "AVL.h"
using namespace std;
int main()
{
	AVL<int>a;
	a.insert(a.getRoot(),10);
	a.insert(a.getRoot(),19);
	a.insert(a.getRoot(),23);
	a.insert(a.getRoot(),12);
	a.insert(a.getRoot(),23);
	a.insert(a.getRoot(),121);
	a.insert(a.getRoot(),1);
	a.insert(a.getRoot(),0);
	a.getHeightOfNodes(a.getRoot());
	a.inOrder(a.getRoot());



	return 0;
}