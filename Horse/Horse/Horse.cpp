// Horse.cpp : 定义控制台应用程序的入口点。
// 马走路经过全部点有且只有一次最后回到原点

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stack>
#include <queue>
#include <math.h>
#include <algorithm>
#include <iomanip>
#define maxn 10000
using namespace std;
int mode[8][2] = { 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2 }; // 走法
bool visit[maxn][maxn];
int order[maxn][maxn];
int n;						// 棋盘N*N
int xx, yy;

struct pos {
	int x, y;
	int way = -1;
	double key = 0;
};

stack<pos>S;
bool over;

// 计算坐标(x, y)可以有多少种走法?
int count_next_num(int x, int y) {
	int next_x, next_y, count = 0;
	for (int i = 0; i < 8; i++) {
		next_x = x + mode[i][0];
		next_y = y + mode[i][1];
		if (visit[next_x][next_y])	continue;
		if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)	continue;
		count++;
	}
	return count;
}

bool next(int x, int y) {
	pos a;
	a.x = x;
	a.y = y;
	S.push(a);								// 该点入栈
	// start 下一步数组
	int next_x, next_y, count = 0;
	pos position[8];
	for (int i = 0; i < 8; i++) {
		next_x = a.x + mode[i][0];
		next_y = a.y + mode[i][1];
		if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)	continue;
		if (visit[next_x][next_y])	continue;
		position[i].way = count_next_num(next_x, next_y);
		position[i].x = next_x;
		position[i].y = next_y;
		position[i].key = sqrt((next_x - xx)*(next_x - xx) + (next_y - yy)*(next_y - yy));
	}
	for (int i = 0; i < 8; i++) {
		if (position[i].way == -1) continue;
		for (int j = 0; j < 8; j++) {
			if (position[i].way == -1) continue;
			if (position[i].way < position[j].way) {
				pos temp = position[i];
				position[i] = position[j];
				position[j] = temp;				// 交换位置，从小到大排序
			}
			if (position[i].way == position[j].way && position[i].key > position[j].key) {
				pos temp = position[i];
				position[i] = position[j];
				position[j] = temp;				// 交换位置，从小到大排序
			}
		}
	}
	// end
	visit[x][y] = true;
	for (int i = 0; i < 8; i++) {
		if (position[i].way >= 0 && position[i].way <= 8) {
			if (next(position[i].x, position[i].y)) {
				return true;
			}
		}
		else continue;
	}
	if (S.size() != n*n) {			        // 如上述while循环if语句全部false，所以进入该阶段。判断此时是否已经走完，未走完则return false
		S.pop();							
		visit[x][y] = false;
		return false;
	}
	for (int i = 0; i < 8; i++) {			// 如果已走完了，判断下一步是否可以到达原点
		int tx = S.top().x;
		int ty = S.top().y;
		if (tx + mode[i][0] == xx && ty + mode[i][1] == yy) {
			return true;
		}
	}
	S.pop();								// 如果上述条件不满足，则pop出当前坐标点标记未访问然后回退
	visit[x][y] = false;
	return false;
}


int main()
{
	cout << "输入棋盘大小N: ";
	cin >> n;
	memset(order, 0, sizeof(order));
	memset(visit, 0, sizeof(visit));
	cout << "请输入马的坐标: ";
	cin >> xx >> yy;
	int sum = n*n;
	int xxx, yyy;
	if (n >= 6) {
		xxx = xx;
		yyy = yy;
		xx = n / 2;
		yy = n / 2;
		next(xx, yy);
		while (!S.empty()) {
			pos a = S.top();
			S.pop();
			order[a.x][a.y] = sum;
			sum--;
		}
		int cast = order[xxx][yyy];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << (order[i][j] + cast) % (n*n) + 1<< "   ";
			}
			cout << endl;
		}
		return 0;
	}
	if (next(xx, yy)) {
		while (!S.empty()) {
			pos a = S.top();
			S.pop();
			order[a.x][a.y] = sum;
			sum--;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << order[i][j] << " ";
				if (order[i][j] < 10) {
					cout << " ";
				}
			}
			cout << endl;
		}
	}
	else {
		cout << "Noway" << endl;
	}
    return 0;
}

