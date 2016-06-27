// ZOJ1610-Count the Colors.cpp : 定义控制台应用程序的入口点。
// 线段树，成段更新染色
// 不使用数组，因为数组效率太低，理解线段树！

#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;
#define Maxsize 8005

int col[Maxsize];
int colCount[Maxsize];

// 顺序存储结构
struct node {
	int ld, rd;
	int color;
}Tree[Maxsize*3];

// 建立空线段树
void buildtree(int i, int a, int b) {
	Tree[i].ld = a;
	Tree[i].rd = b;
	Tree[i].color = -1;
	if (b - a == 1)	return;
	buildtree(i * 2, a, (a + b) / 2);
	buildtree(i * 2 + 1, (a + b) / 2, b);
}

// 插入 1 0 4 4
void insert(int i, int a, int b, int color) {
	int mid = (Tree[i].ld + Tree[i].rd) / 2;

	if (a <= Tree[i].ld && Tree[i].rd <= b) {
		Tree[i].color = color;
		return;
	}
	
	if (Tree[i].color != -2) {		// 代表有颜色覆盖
		Tree[i * 2].color = Tree[i].color;
		Tree[i * 2 + 1].color = Tree[i].color;
	}
	Tree[i].color = -2;
	if (b <= mid) {
		insert(i * 2, a, b, color);
	}
	else if (a >= mid) {
		insert(i * 2 + 1, a, b, color);
	}
	else {
		insert(i * 2, a, mid, color);
		insert(i * 2 + 1, mid, b, color);
	}

}

void search(int i) {
	if (Tree[i].color != -2 && Tree[i].color != -1) {
		for (int j = Tree[i].ld; j < Tree[i].rd; j++) {
			col[j] = Tree[i].color;
		}
	}
	if (Tree[i].color == -2) {
		search(2 * i);
		search(2 * i + 1);
	}
}

int main() {
	int n, m, a, b, c;
	while (cin >> n) {
		memset(colCount, 0, sizeof(colCount));
		memset(col, -1, sizeof(col));
		buildtree(1, 0, 8000);
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			insert(1, a, b, c);
		}
		search(1);
		int t = -1;
		for (int i = 0; i <= 8000; i++) {
			if (col[i] == t)	continue;
			t = col[i];
			if (t != -1)	colCount[t]++;
		}
		for (int i = 0; i <= 18; i++) {
			if (colCount[i]) {
				cout << i << " " << colCount[i] << endl;
			}
		}
		cout << endl;
	}
	return 0;
}

