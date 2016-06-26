// ZOJ1203-Swordfish.cpp : �������̨Ӧ�ó������ڵ㡣
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
int parent[Maxsize];			// ���鼯

bool operator < (const EdgeNode &a, const EdgeNode &b) {
	if (a.cost > b.cost) {
		return true;
	}
	else {
		return false;
	}
}

int Find(int i) {
	// ��ʵ��:
	// while(parent[i] >= 0) i = parent[i];
	// return i;
	// �Ľ�ʵ��:
	// �ҵ���Ԫ��i�����ĸ�������̮����������
	// ��i���������н�㵽���ľ���
	int r;
	for (r = i; parent[r] >= 0; r = parent[r]);	//�ҵ���
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
		// תΪ�ڽӾ���
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cost[i][j] = sqrt((edge[i].x - edge[j].x)*(edge[i].x - edge[j].x) + (edge[i].y - edge[j].y)*(edge[i].y - edge[j].y));
				cost[j][i] = cost[i][j];
			}
		}
		// �������ȶ���
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				EdgeNode edge;
				edge.start = i;
				edge.end = j;
				edge.cost = cost[i][j];
				PQ.push(edge);				// �������ȶ���
			}
		}
		double Mincost = 0;
		for (int count = 1; count <= n; count++) {
			EdgeNode edge;
			edge = PQ.top();
			PQ.pop();				// �����ȶ�����ȡȨֵ��С�ı�
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

