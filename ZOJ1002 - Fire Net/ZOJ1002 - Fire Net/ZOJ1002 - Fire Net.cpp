// ZOJ1002 - Fire Net.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>  
#include <cstring>  
const int maxn = 7;
char mm[maxn][maxn];
int vis[maxn][maxn];				// ���޵ﱤ
int k, maxx;
int n;

// �ж�(x, y)���ɲ����Էŵﱤ
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

// ��ȱ���
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
				k++;				// ���õﱤ���ٽ�����ȱ������ҳ���ʱ�����ﱤ��
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