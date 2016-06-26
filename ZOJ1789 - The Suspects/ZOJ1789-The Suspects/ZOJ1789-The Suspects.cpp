// ZOJ1789-The Suspects.cpp : 定义控制台应用程序的入口点。
// 传染病嫌疑人

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int group[500][30000];		// group数组
int m;						// k是group数量
int suspects[30000];
int number = 1;

void search(int t) {
	for (int i = 0; i < m; i++) {
		if (group[i][0] == -2) {		// -2代表已全部有嫌疑
			continue;
		}
		else {
			int j = 1;
			while (group[i][j] != -1) {
				if (group[i][j] == t) {	// 该组含嫌疑人
					group[i][0] = -2;
					int u = 1;
					while (group[i][u] != -1) {						// 遍历该组
						if (suspects[group[i][u]] == 1) {			// 已搜索
							u++;
							continue;
						}
						else {								
							number++;
							suspects[group[i][u]] = 1;		// 进入搜索范围
							search(group[i][u]);			// 进入搜索
							u++;
						}
					}
				}
				j++;
			}
		}
	}
}


int main(){
	int n, k;
	while (cin >> n >> m) {
		number = 1;
		if (n == 0 && m == 0) {
			break;
		}
		else {
			memset(group, -1, sizeof(group));
			memset(suspects, 0, sizeof(suspects));
			suspects[0] = 1;
			for (int i = 0; i < m; i++) {
				cin >> k;
				for (int j = 1; j <= k; j++) {
					cin >> group[i][j];
				}
			}
		}
		search(0);
		cout << number << endl;
	}
    return 0;
}

