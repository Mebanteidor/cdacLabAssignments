#include<string>
#include"Tree.h"


void getMenu() {
	string menu = "Binary Tree Menu\n";
	menu += "1.Insert\n";
	menu += "2.Exit\n";
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
		case 2:
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

}