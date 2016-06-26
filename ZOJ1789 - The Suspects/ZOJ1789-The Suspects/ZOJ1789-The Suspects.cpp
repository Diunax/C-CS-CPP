// ZOJ1789-The Suspects.cpp : �������̨Ӧ�ó������ڵ㡣
// ��Ⱦ��������

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int group[500][30000];		// group����
int m;						// k��group����
int suspects[30000];
int number = 1;

void search(int t) {
	for (int i = 0; i < m; i++) {
		if (group[i][0] == -2) {		// -2������ȫ��������
			continue;
		}
		else {
			int j = 1;
			while (group[i][j] != -1) {
				if (group[i][j] == t) {	// ���麬������
					group[i][0] = -2;
					int u = 1;
					while (group[i][u] != -1) {						// ��������
						if (suspects[group[i][u]] == 1) {			// ������
							u++;
							continue;
						}
						else {								
							number++;
							suspects[group[i][u]] = 1;		// ����������Χ
							search(group[i][u]);			// ��������
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

