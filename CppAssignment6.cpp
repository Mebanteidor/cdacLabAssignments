#include "pch.h"
#include <iostream>
#include<cstdio>

using namespace std;

void revFunc(char *);

int main()
{
	char myString[30];

	cout << "Enter a string:";
	cin >> myString;
	cout << endl; 

	revFunc(myString);
	cout<<"Reverse of string is : "<<myString<<endl;
}

void revFunc(char *str) {
	char temp;
	int j{};
	j = strlen(str)-1;
	for (int i = 0;i <j;i++,j--) {  //--------reversing block
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	//return str;
}
