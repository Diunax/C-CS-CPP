// ZOJ1383-Binary Numbers.cpp : 定义控制台应用程序的入口点。
// 输入一个数，输出次数二进制形式中1的位置，最右位置为0

#include "stdafx.h"
#include <iostream>
using namespace std;

void outputOne(int val) {
	bool first = true;
	for (int i = 0; i < 32; i++)
	{
		if (val & (1 << i) && first) {
			cout << i;
			first = false;
		}
		else if (val & (1 << i) && !first) {
			cout << " " << i;
		}
	}
	cout << endl;
}

int main()
{
	int line;
	cin >> line;
	int *p = new int[line];
	for (int i = 0; i < line; i++) {
		cin >> p[i];
		outputOne(p[i]);
	}
	return 0;
}

