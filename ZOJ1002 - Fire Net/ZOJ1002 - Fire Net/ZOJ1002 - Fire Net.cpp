// ZOJ1002 - Fire Net.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int n;
int G[4][4];
int len[32][4];

int main() {
	int row, col;
	while (cin >> n && n) {
		int k = 0;
		int num = 1;
		char temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> temp;
				if (temp != 'X') {
					G[i][j] = num;
					num++;
				}
				else {
					G[i][j] = 0;
				}
			}
		}
		// 横向	形成row个点
		for (int i = 0; i < n; i++) {
			int u = 0;
			bool stone = true;
			for (int j = 0; j < n; j++) {
				if (G[i][j] != 0) {
					stone = false;
					len[k][u] = G[i][j];
					u++;
				}
				else {
					if (stone)	continue;
					else {
						stone = true;
						k++;
						u = 0;
					}
				}
			}
			if (!stone)	k++;
		}
		row = k;
		// 纵向	形成col个点
		for (int j = 0; j < n; j++) {
			int u = 0;
			bool stone = true;
			for (int i = 0; i < n; i++) {
				if (G[i][j] != 0) {
					stone = false;
					len[k][u] = G[i][j];
					u++;
				}
				else {
					if (stone)	continue;
					else {
						stone = true;
						k++;
						u = 0;
					}
				}
			}
			if (!stone)	k++;
		}
		col = k - row;
	}
	return 0;
}