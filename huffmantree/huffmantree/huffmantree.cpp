// huffmantree.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "������ڵ����: ";
	cin >> n;
	huffmanNode *nodes = new huffmanNode[n];
	huffmanNode *now = nodes;
	for (int i = 0; i < n; i++) {
		cout << "�������" << i << "���ڵ���ַ�: ";
		cin >> data;
		cout << "�������" << i << "���ڵ��Ȩ��: ";
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

