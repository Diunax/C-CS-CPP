// ZOJ1002 - Fire Net.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>  
#include <cstring>  
const int maxn = 7;
char mm[maxn][maxn];
int vis[maxn][maxn];				// 有无碉堡
int k, maxx;
int n;

// 判断(x, y)处可不可以放碉堡
bool judge(int x, int y) {			
	for (int i = x; i >= 0; i--) {
		if (vis[i][y] == 1) {
			return false;
		}
		if (mm[i][y] == 'X'){
			break;
		}
	}
	for (int i = x; i < n; i++) {
		if (vis[i][y] == 1) {
			return false;
		}
		if (mm[i][y] == 'X') {
			break;
		}
	}
	for (int j = y; j >= 0; j--) {
		if (vis[x][j] == 1) {
			return false;
		}
		if (mm[x][j] == 'X') {
			break;
		}
	}
	for (int j = y; j < n; j++) {
		if (vis[x][j] == 1) {
			return false;
		}
		if (mm[x][j] == 'X') {
			break;
		}
	}
	return true;
}

// 深度遍历
void DFS()
{
	if (k > maxx)
		maxx = k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j] && judge(i, j) && mm[i][j] == '.')
			{
				vis[i][j] = 1;
				k++;				// 放置碉堡，再进行深度遍历，找出此时的最大碉堡数
				DFS();
				vis[i][j] = 0;
				k--;
			}
		}
	}
}
int main()
{
	while (scanf("%d", &n) && n)
	{
		k = maxx = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			scanf("%s", mm[i]);
		}
		DFS();
		printf("%d\n", maxx);
	}
	return 0;
}