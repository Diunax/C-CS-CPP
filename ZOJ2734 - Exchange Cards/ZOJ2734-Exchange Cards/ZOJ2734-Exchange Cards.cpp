// ZOJ2734-Exchange Cards.cpp : �������̨Ӧ�ó������ڵ㡣
// ����һ�����ݣ�������мӷ����ʽ, ������ȱ���

#include "stdafx.h"
#include <stdio.h>  
#include <iostream>  
#include <string.h>
using namespace std;
int num[1010];
int sum, result;
int wanted, line;
void DFS(int x)
{
	if (sum == wanted)
	{
		result++;
		return;
	}
	for (int i = x; i <= wanted; i++)
	{
		if (num[i] && sum + i <= wanted)
		{
			num[i]--;
			sum += i;
			DFS(i);
			num[i]++;
			sum -= i;
		}
		else if (sum + i > wanted) {
			break;
		}
	}
}
int main()
{
	int m, n;
	bool first = true;
	while (cin >> wanted >> line)
	{
		if (!first)	cout << endl;
		first = false;
		memset(num, 0, sizeof(num));
		sum = result = 0;
		for (int i = 0; i<line; i++)
		{
			cin >> m >> n;
			num[m] = n;
		}
		DFS(1);
		cout << result << endl;
	}
	return 0;
}
