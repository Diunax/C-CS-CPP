// ZOJ2193-Window Pains.cpp : �������̨Ӧ�ó������ڵ㡣
// ��������

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
int type;				// �������������

void buildG() {			// ��������ͼ
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int p = 0; p < cover[i][j].length(); p++) {
				int from = a[i][j],
					to = cover[i][j][p] - '0';
				// [i][j]������[i][j]���ܸ��ǵ㣬�����ڽӾ���
				if (G[from][to] == 0 && from != to && exist[from] && exist[to]) {
					G[from][to] = 1;
					indegree[from] ++;
				}
			}
		}
	}
}

bool check() {			// �ж��Ƿ��л����޻�����true���л�����false
	for (int i = 0; i < type; i++) {
		int count = 0;	// ���㵱ǰ��ȵ���0�Ĵ�����
		int number = 0;	// ��¼��ǰ������
		for (int j = 1; j <= 9; j++) {
			if (exist[j] && indegree[j] == 0) {
				count++;
			}
			if (exist[j]) {
				number++;
			}
		}
		// ����Ѿ�û�����Ϊ0�Ĵ��ڶ���ǰ���ڻ���Ϊ0���򷵻�false
		if (count == 0 && number > 0) {
			return false;
		}
		int k=0;
		// �ҵ����Ϊ0�ĵ�
		for (int j = 1; j <= 9; j++) {
			if (exist[j] && indegree[j] == 0) {
				k = j;
				break;
			}
		}
		exist[k] = false;
		for (int j = 1; j <= 9; j++)
			if (exist[j] && G[j][k])
				// ɾ����Ӧ�������(��ȼ�1)  
				indegree[j]--;
	}
}

int main() {
	string str;
	for (int i = 1; i <= 9; i++) {			// cover��ʾ(i,j)�����ܵĸ���
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
		for (int i = 0; i < 4; i++) {					// ��������
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