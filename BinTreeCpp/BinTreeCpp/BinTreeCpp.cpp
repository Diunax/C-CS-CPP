// BinTreeCpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "tree.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	BinTree<char> t;
	string str;
	cout << "请用广义表方式建树" << endl;
	cin >> str;
	t.Create(str);
	cout << "1.前序非递归遍历:";
	t.preDgOutput();
	cout << endl;
	cout << "2.中序非递归遍历:";
	t.midDgOutput();
	cout<< endl;
	cout << "3.后序非递归遍历:";
	t.lastDgOutput();
	cout<<endl;
	cout << "4.前序递归遍历:";
	t.preNdgOutput(t.getRoot());
	cout<< endl;
	cout << "5.中序递归遍历:";
	t.midNdgOutput(t.getRoot());
	cout<<endl;
	cout << "6.后序递归遍历:";
	t.lastNdgOutput(t.getRoot());
	cout<<endl;
	system("pause");
    return 0;
}

