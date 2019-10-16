//Source.cpp>
#include<iostream>
#include"StackClass.h"

using namespace std;

int main() {
	Stack p;
	p.startOp();
	return 0;
}
-------------------------
//StackClass.h>
#pragma once
#include<iostream>

class Node {
public:
	int data;
	Node *next;
};

class Stack {
private:
	Node *top,*head;
public:
	Stack() {
		top = NULL;
		head = NULL;
	}
	void startOp();
	void push(int);
	void pop();
	void display();
	void getTop();
};
----------------------
//ClassDef.cpp
#include"StackClass.h"
#include<string>

using namespace std;

void getMenu() {
	string menu = "Operations\n";
	menu += "1.Push\n";
	menu += "2.Display\n";
	menu += "3.Get Top\n";
	menu += "4.Pop\n";
	menu += ">>";
	cout << menu;
}

void Stack::startOp() {
	int choice, data;
	bool funcBool = true;
	while (funcBool) {
		getMenu();
		cin >> choice;
	
		switch (choice)
		{
		case 1: {
			cout << "Enter the data to PUSH: ";
			cin >> data;
			this->push(data);
			funcBool = true;
			break;
		}
		case 2: {
			this->display();
			funcBool = true;
			break;
		}
		case 3: {
			this->getTop();
			funcBool = true;
			break;
		}
		case 4: {
			this->pop();
			funcBool = true;
			break;
		}
		/*case 5:
			funcBool = false;
			break;*/
		default:
			break;
		}
	}
}
void Stack::push(int data) {
	Node *node = new Node;
	node->data = data;
	node->next = NULL;
	if (top == NULL) {
		top = node;
	}
	else {
		node->next = top;
		top = node;
	}
}
void Stack::display() {
	Node *ptr = new Node;
	if (top == NULL) {
		cout << "Stack is Empty!"<<endl;
	}
	else {
		ptr = top;
		while (ptr != NULL) {
			cout << endl;
			cout << "|   ";
			cout << ptr->data;
			cout << "   |\n";
			cout << " _________\n";
			ptr = ptr->next;
		}
		cout << endl;
	}
}

void Stack::getTop() {
	cout << "Data at TOP of the Stack: ";
	cout << top->data << endl;
}

void Stack::pop() {
	Node *temp = new Node;
	if (top == NULL) {
		cout << "Stack Underflow!";
	}
	else {
		temp = top;
		top = top->next;
		//temp->next = NULL;
		delete(temp);
	}
}
