// BinTreeCpp.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "���ù����ʽ����" << endl;
	cin >> str;
	t.Create(str);
	cout << "1.ǰ��ǵݹ����:";
	t.preDgOutput();
	cout << endl;
	cout << "2.����ǵݹ����:";
	t.midDgOutput();
	cout<< endl;
	cout << "3.����ǵݹ����:";
	t.lastDgOutput();
	cout<<endl;
	cout << "4.ǰ��ݹ����:";
	t.preNdgOutput(t.getRoot());
	cout<< endl;
	cout << "5.����ݹ����:";
	t.midNdgOutput(t.getRoot());
	cout<<endl;
	cout << "6.����ݹ����:";
	t.lastNdgOutput(t.getRoot());
	cout<<endl;
	system("pause");
    return 0;
}

