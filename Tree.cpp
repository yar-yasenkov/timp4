// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

int *arr;
int num;


void reverse(int top) 
{
	for (int i = 0; i < num; i++)
	if (arr[i] == top)
		reverse(i);

	cout << top << " ";

	return;
}

void direct(int top)
{
	cout << top << " ";
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == top)
			direct(i);
	}
	return;
}

void symm(int top)
{
		int index = 0;
		while ((arr[index] != top) && (index < num))
			index++;
		if (index < num)
			symm(index);

		cout << top << " ";

		if (index < num)
		for (int i = index + 1; i < num; i++)
		if (arr[i] == top)
			symm(i);

		return;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int  ch,*newarr,top;
	setlocale(LC_ALL, "rus");
	cout << "ввод:" << endl;
	cin >> num;
	arr = new int[num];
	newarr = new int[num];
	for (int i = 0; i < num; i++)
		newarr[i] = -1;
	ifstream fin("data.txt");
	for (int i = 0; i < num; i++)
	{
		fin >> ch;
		arr[i] = ch;
		cout << ch << " ";
	}
	cout << endl;
	
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == -1)
			top = i;
	}
	direct(top);
	cout << endl;
	reverse(top);
	cout << endl;
	symm(top);
	system("pause");
	return 0;
}

