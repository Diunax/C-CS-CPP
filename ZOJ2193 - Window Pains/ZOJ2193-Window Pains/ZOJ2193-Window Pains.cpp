// ZOJ2193-Window Pains.cpp : 定义控制台应用程序的入口点。
// 拓扑排序

#include "stdafx.h"
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int a[4][4];

bool exist[10];
string cover[4][4];
int G[10][10];
int indegree[10];
int type;				// 输入的数的类型

void buildG() {			// 构造有向图
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int p = 0; p < cover[i][j].length(); p++) {
				int from = a[i][j],
					to = cover[i][j][p] - '0';
				// [i][j]到所有[i][j]可能覆盖点，建立邻接矩阵
				if (G[from][to] == 0 && from != to && exist[from] && exist[to]) {
					G[from][to] = 1;
					indegree[from] ++;
				}
			}
		}
	}
}

bool check() {			// 判断是否有环，无环返回true，有环返回false
	for (int i = 0; i < type; i++) {
		int count = 0;	// 计算当前入度等于0的窗口数
		int number = 0;	// 记录当前窗口数
		for (int j = 1; j <= 9; j++) {
			if (exist[j] && indegree[j] == 0) {
				count++;
			}
			if (exist[j]) {
				number++;
			}
		}
		// 如果已经没有入度为0的窗口而当前窗口还不为0，则返回false
		if (count == 0 && number > 0) {
			return false;
		}
		int k=0;
		// 找到入度为0的点
		for (int j = 1; j <= 9; j++) {
			if (exist[j] && indegree[j] == 0) {
				k = j;
				break;
			}
		}
		exist[k] = false;
		for (int j = 1; j <= 9; j++)
			if (exist[j] && G[j][k])
				// 删除相应顶点入边(入度减1)  
				indegree[j]--;
	}
}

int main() {
	string str;
	for (int i = 1; i <= 9; i++) {			// cover表示(i,j)处可能的覆盖
		int t = (i-1) / 3;
		int k = (i-1) % 3;
		cover[t][k] += char(i + '0');
		cover[t][k + 1] += char(i + '0');
		cover[t + 1][k] += char(i + '0');
		cover[t + 1][k + 1] += char(i + '0');
	}
	while (cin >> str && str != "ENDOFINPUT") {
		memset(exist, 0, sizeof(exist));
		memset(indegree, 0, sizeof(indegree));
		memset(G, 0, sizeof(G));
		type = 0;
		for (int i = 0; i < 4; i++) {					// 输入数据
			for (int j = 0; j < 4; j++) {
				cin >> a[i][j];
				if (!exist[a[i][j]])	type++;
				exist[a[i][j]] = true;					
			}
		}
		buildG();
		if (check()) {
			cout << "THESE WINDOWS ARE CLEAN" << endl;
		}
		else {
			cout << "THESE WINDOWS ARE BROKEN" << endl;
		}
		string s;
		cin >> s;
	}
	return 0;
}