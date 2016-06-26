// ZOJ2770 - Burn the Linked Camp.cpp : �������̨Ӧ�ó������ڵ㡣
// ���Լ��ϵͳ תΪ Bellmanford��SPFA��, �жϸ���

#include "stdafx.h"
#include <iostream>
using namespace std;
#define maxn 1005

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int uu, int vv, int ww) :u(uu), v(vv), w(ww) {}
}e[maxn*maxn];

int sd[maxn];	// ǰi����Ӫ�е����ʿ��
int d[maxn];
int n, m, l;

bool bellmanford(int x)
{
	memset(d, 999999, sizeof(d));
	d[x] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			int u = e[j].u, v = e[j].v, w = e[j].w;
			if (d[v] > d[u] + w)
				d[v] = d[u] + w;
		}
	}
	// �����ж�
	for (int i = 0; i < l; i++)
		if (d[e[i].v] > d[e[i].u] + e[i].w)
			return false;
	return true;
}

int main()
{
	while (cin >> n >> m) {					// ��Ӫ��n
		int a, b, c, temp;
		memset(sd, 0, sizeof(sd));
		l = 0;
		// (1) - (0) <= C1
		// (0) - (1) <= 0
		// (2) - (1) <= C2
		// (1) - (2) <= 0
		for (int i = 1; i <= n; i++) {
			cin >> temp;
			e[l++] = Edge(i, i - 1, 0);			// (i-1) - (i) <=0
			e[l++] = Edge(i - 1, i, temp);		// (i) - (i-1) <= temp
		}
		for (int i = 1; i <= m; i++) {
			cin >> a >> b >> c;
			e[l++] = Edge(b, a-1, -c);			// b - (a-1) >=c -> (a-1) - b <= -c
		}
		// ����(n) - (0) >= ? �� (0) - (n) <= -?, ����bellmanford(n)�����-d[0]
		if (!bellmanford(n))	cout << "Bad Estimtions" << endl;
		else  cout << -d[0] << endl;			// todo Ϊʲô��0��
	}
    return 0;
}

