// Knapsack.cpp : 定义控制台应用程序的入口点。
// 背包问题，动态规划

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
using namespace std;
#define maxn 100
int n, m, j;
int v[maxn];
int s[maxn];
int p[maxn][maxn];

int main()
{
	srand(1212);
	int n = 10;
	int m = 50;
	memset(p, 0, sizeof(p));
	memset(v, 0, sizeof(v));
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; i++) {
		s[i] = rand() % 10;		// 体积
		v[i] = rand() % 50;		// 价值
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			p[i][j] = p[i - 1][j];
			if (j >= s[i]) {
				if (p[i - 1][j] < p[i - 1][j - s[i]] + v[i]) {
					p[i][j] = p[i - 1][j - s[i]] + v[i];
				}
			}
		}
	}
	return 0;
}

