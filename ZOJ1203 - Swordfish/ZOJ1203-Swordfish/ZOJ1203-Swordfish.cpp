// ZOJ1203-Swordfish.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
using namespace std;
#define Maxsize 100

struct EdgeNode {
	int start, end;
	double cost;
};
struct Edge {
	double x, y;
};
Edge edge[1000];
double cost[1000][1000];
int parent[Maxsize];			// 并查集

bool operator < (const EdgeNode &a, const EdgeNode &b) {
	if (a.cost > b.cost) {
		return true;
	}
	else {
		return false;
	}
}

int Find(int i) {
	// 简单实现:
	// while(parent[i] >= 0) i = parent[i];
	// return i;
	// 改进实现:
	// 找到含元素i的树的根，采用坍塌规则缩短
	// 从i到根的所有结点到根的距离
	int r;
	for (r = i; parent[r] >= 0; r = parent[r]);	//找到根
	while (i != r) {
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}
void Union(int i, int j) {
	parent[i] = j;
}

priority_queue<EdgeNode> PQ;

int main()
{
	int n;
	while (cin >> n && n) {
		memset(parent, -1, sizeof(parent));
		for (int i = 1; i <= n; i++) {
			cin >> edge[i].x >> edge[i].y;
		}
		// 转为邻接矩阵
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cost[i][j] = sqrt((edge[i].x - edge[j].x)*(edge[i].x - edge[j].x) + (edge[i].y - edge[j].y)*(edge[i].y - edge[j].y));
				cost[j][i] = cost[i][j];
			}
		}
		// 存入优先队列
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				EdgeNode edge;
				edge.start = i;
				edge.end = j;
				edge.cost = cost[i][j];
				PQ.push(edge);				// 存入优先队列
			}
		}
		double Mincost = 0;
		for (int count = 1; count <= n; count++) {
			EdgeNode edge;
			edge = PQ.top();
			PQ.pop();				// 从优先队列中取权值最小的边
			int u = Find(edge.start),
				v = Find(edge.end);
			if (u != v) {
				Union(u, v);
				Mincost += edge.cost;
			}
		}
		printf("%.2f\n", Mincost);
	}
    return 0;
}

