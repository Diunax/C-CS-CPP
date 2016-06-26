// ZOJ1942-Frogger.cpp : 定义控制台应用程序的入口点。
// Floyd遍历，动态规划，切记, k-i-j 前提勿负数环

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 2000
int x[maxn], y[maxn], n;
double d[maxn][maxn];

double dist(int i, int j) {
	return sqrt(pow(double(x[i] - x[j]), 2) + pow(double(y[i] - y[j]), 2));
}

int main()
{
	int count = 1;
	while (cin >> n && n) {
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = d[j][i] = dist(i, j);
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
		printf("Scenario #%d\n", count);
		printf("Frog Distance = %0.3f\n", d[1][n]);
	}
    return 0;
}

