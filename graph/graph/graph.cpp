// graph.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "matrix.h"
#include "list.h"
#include <iostream>
using namespace std;
int main()
{
	int size,num;
	cout << "������ͼ�Ķ������:";
	cin >> size;
	matrix A(size);
	A.display();
	A.insert();
	A.display();
	cout << "��������й�����ȵĶ����:";
	cin >> num;
	cout << "������ȱ���:" << endl;
	A.BFS(num);
	cout << "������ȱ���:" << endl;
	A.DFS(num);
    return 0;
}

