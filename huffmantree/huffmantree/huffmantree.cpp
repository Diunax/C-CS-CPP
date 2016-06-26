// huffmantree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include "huffmantree.h"
using namespace std;

int main()
{
	huffmanTree A;
	int n, weight;
	char data;
	cout << "请输入节点个数: ";
	cin >> n;
	huffmanNode *nodes = new huffmanNode[n];
	huffmanNode *now = nodes;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i << "个节点的字符: ";
		cin >> data;
		cout << "请输入第" << i << "个节点的权重: ";
		cin >> weight;
		nodes->data = data;
		nodes->weight = weight;
		nodes++;
	}
	A.create(now,n);
	A.preOutput();
	A.encoding();
	A.decoding();
	A.print();
	return 0;
}

