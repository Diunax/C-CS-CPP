// Horse.cpp : �������̨Ӧ�ó������ڵ㡣
// ����·����ȫ��������ֻ��һ�����ص�ԭ��

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
int mode[8][2] = { 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2 }; // �߷�
bool visit[maxn][maxn];
int order[maxn][maxn];
int n;						// ����N*N
int xx, yy;

struct pos {
	int x, y;
	int way = -1;
	double key = 0;
};

stack<pos>S;
bool over;

// ��������(x, y)�����ж������߷�?
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
	S.push(a);								// �õ���ջ
	// start ��һ������
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
				position[j] = temp;				// ����λ�ã���С��������
			}
			if (position[i].way == position[j].way && position[i].key > position[j].key) {
				pos temp = position[i];
				position[i] = position[j];
				position[j] = temp;				// ����λ�ã���С��������
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
	if (S.size() != n*n) {			        // ������whileѭ��if���ȫ��false�����Խ���ý׶Ρ��жϴ�ʱ�Ƿ��Ѿ����꣬δ������return false
		S.pop();							
		visit[x][y] = false;
		return false;
	}
	for (int i = 0; i < 8; i++) {			// ����������ˣ��ж���һ���Ƿ���Ե���ԭ��
		int tx = S.top().x;
		int ty = S.top().y;
		if (tx + mode[i][0] == xx && ty + mode[i][1] == yy) {
			return true;
		}
	}
	S.pop();								// ����������������㣬��pop����ǰ�������δ����Ȼ�����
	visit[x][y] = false;
	return false;
}


int main()
{
	cout << "�������̴�СN: ";
	cin >> n;
	memset(order, 0, sizeof(order));
	memset(visit, 0, sizeof(visit));
	cout << "�������������: ";
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

