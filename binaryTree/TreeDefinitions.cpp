#include<string>
#include"Tree.h"


void getMenu() {
	string menu = "Binary Tree Menu\n";
	menu += "1.Insert\n";
	menu += "2.Pre-Order Traversal\n";
	menu += "3.In-Order Traversal\n";
	menu += "4.Post-Order Traversal\n";
	menu += "5.Exit\n";
	menu += ">>";
	cout << menu;
}
void Tree::startOp() {
	int choice, data;
	bool funcBool = true;
	while (funcBool) {
		getMenu();
		cin >> choice;
		//funcBool=menuOp(choice);
		switch (choice)
		{
		case 1: {
			cout << "Enter data to insert: ";
			cin >> data;
			this->insertNode(data);
			cout << "Data Added!";
			cout << endl<<endl;
			funcBool = true;
			break;
		}
		case 2: {
			this->preOrder();
			funcBool = true;
			break;
		}
		case 3: {
			this->inOrder();
			funcBool = true;
			break;
		}
		case 4: {
			this->postOrder();
			funcBool = true;
			break;
		}
		case 5:
			funcBool = false;
			break;
		default:
			break;
		}
	}
}
void Tree::insertNode(int idata) {
	TreeNode *temp = new TreeNode;
	temp->data = idata;
	temp->left = NULL;
	temp->right = NULL;
	TreeNode *parent, *nodePtr;
	parent = NULL;
	if (root == NULL) {
		root = temp;
		return;
	}
	else {
		nodePtr = root;
		while (nodePtr != NULL)
		{
			parent = nodePtr;
			if (idata > nodePtr->data) {
				nodePtr = nodePtr->right;
			}
			else
			{
				nodePtr = nodePtr->left;
			}
		}
		if (idata > parent->data) {
			parent->right = temp;
		}
		else {
			parent->left = temp;
		}
	}
}

void Tree::preOrder() {
	if (root == NULL) {
		cout << "Tree is Empty!"<<endl;
	}
	else {
		preOrderTrav(root);
	}
	cout << endl;
}

void Tree::preOrderTrav(TreeNode *pnode) {
	cout << pnode->data << " ";
	if (pnode->left != NULL) {
		preOrderTrav(pnode->left);
	}
	if (pnode->right != NULL) {
		preOrderTrav(pnode->right);
	}
}

void Tree::inOrder() {
	if (root == NULL) {
		cout << "Tree is Empty!" << endl;
	}
	else {
		inOrderTrav(root);
	}
	cout << endl;
}

void Tree::inOrderTrav(TreeNode *pnode) {
	
	if (pnode != NULL) {
		inOrderTrav(pnode->left);
		cout << pnode->data << " ";
		inOrderTrav(pnode->right);
	}
}

void Tree::postOrder() {
	if (root == NULL) {
		cout << "Tree is Empty!" << endl;
	}
	else {
		postOrderTrav(root);
	}
	cout << endl;
}

void Tree::postOrderTrav(TreeNode *pnode) {

	if (pnode != NULL) {
		postOrderTrav(pnode->left);
		postOrderTrav(pnode->right);
		cout << pnode->data << " ";
	}
}
