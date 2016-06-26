// Resource.cpp : 定义控制台应用程序的入口点。
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
					f[i][j] = f[k][j - 1] + c[i - k][j];		// i台设备分配给前j个车间所能带来的利润
					p[i][j] = k;			  // i台设备分配给前j个车间的最优解下，j号车间分配的设备数为k
				}
			}
		}
	}
	cout << "最大获利: " << f[n][m] << endl;
	cout << "资源分配方案: " << endl;
	int k = n;
	for (int j = m; j >= 1; j--) {
		cout << "第 " << j << " 号车间使用" << k - p[k][j] << "台设备." << endl;
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
P:	cout << "1. 随机数据" << endl;
	cout << "2. 手动输入" << endl;
	cout << "请您输入操作方式: ";
	cin >> s;
	if (s == 1) {
		while (count--) {
			srand(count);
			n = 30;	// 设备数
			m = 10; // 车间数
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
		cout << "请分别输入设备数和车间数: " << endl;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cout << "请分别输入第" << i << "台设备分配给" << m << "台车间分别能带来的盈利:";
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

