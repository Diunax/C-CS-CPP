// Resource.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
using namespace std;
#define maxn 100
int n, m, j;
int c[maxn][maxn];
int f[maxn][maxn];
int p[maxn][maxn];

void distribute() {
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k <= i; k++) {
				if (f[i][j] < f[k][j - 1] + c[i - k][j]) {
					f[i][j] = f[k][j - 1] + c[i - k][j];		// į�豸�����ǰj���������ܴ���������
					p[i][j] = k;			  // į�豸�����ǰj����������Ž��£�j�ų��������豸��Ϊk
				}
			}
		}
	}
	cout << "������: " << f[n][m] << endl;
	cout << "��Դ���䷽��: " << endl;
	int k = n;
	for (int j = m; j >= 1; j--) {
		cout << "�� " << j << " �ų���ʹ��" << k - p[k][j] << "̨�豸." << endl;
		k = p[k][j];
	}
	cout << endl;
}

int main()
{
	int s, count=10;
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	memset(p, 0, sizeof(p));
P:	cout << "1. �������" << endl;
	cout << "2. �ֶ�����" << endl;
	cout << "�������������ʽ: ";
	cin >> s;
	if (s == 1) {
		while (count--) {
			srand(count);
			n = 30;	// �豸��
			m = 10; // ������
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					c[i][j] = rand() % 1000;
					cout << c[i][j] << " ";
				}
				cout << endl;
			}
			distribute();
		}
	}
	else if (s == 2) {
		cout << "��ֱ������豸���ͳ�����: " << endl;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cout << "��ֱ������" << i << "̨�豸�����" << m << "̨����ֱ��ܴ�����ӯ��:";
			for (int j = 1; j <= m; j++) {
				cin >> c[i][j];
			}
			cout << endl;
		}
	}
	else {
		goto P;
	}
    return 0;
}

