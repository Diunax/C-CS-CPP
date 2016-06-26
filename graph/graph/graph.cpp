// graph.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "matrix.h"
#include "list.h"
#include <iostream>
using namespace std;
int main()
{
	int size,num;
	cout << "请输入图的顶点个数:";
	cin >> size;
	matrix A(size);
	A.display();
	A.insert();
	A.display();
	cout << "请输入进行广度优先的顶点号:";
	cin >> num;
	cout << "广度优先遍历:" << endl;
	A.BFS(num);
	cout << "深度优先遍历:" << endl;
	A.DFS(num);
    return 0;
}

