#pragma once
#pragma once
#pragma once
#include<iostream>

using namespace std;

class TreeNode {
public:
	int data;
	TreeNode *right, *left;
};

class Tree
{
private:
	TreeNode *root;
public:
	Tree() {
		root = NULL;
	}
	void startOp();
	void insertNode(int);
};
