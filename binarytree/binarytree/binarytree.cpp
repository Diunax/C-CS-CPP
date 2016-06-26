// binarytree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include  "tree.h"
#include<iostream>
#include<Windows.h>
int main()
{
	BinTree<char> A,B;
	string str;
	cin >> str;
	A.Create(str);
	A.Output();
	//A.Copy(A.getRoot(), B.getRoot());
	/*if (A.Check(A.getRoot(), B.getRoot())) {
		cout << "equal";
	}
	else
		cout << "no equal";*/
	//B.Output();
	A.Children();
	return 0;
	system("pause");
}

