// ZOJ1204-Additive equations.cpp : �������̨Ӧ�ó������ڵ㡣
// ����һ�����ݣ�������мӷ����ʽ��������ȱ���

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[30];
int b[30];
int SIZE;
bool EQUAL = false;

bool inArray(int value) {
	for (int i = 0; i < SIZE; i++) {
		if (value == a[i]) {
			return true;
		}
	}
	return false;
}

// cur��ǰ������desĿ�������sum��ǰ�ܺ�
void DFS(int cur, int des, int sum, int last) {
	int i;
	// ��ǰ��������Ŀ�����ʱ
	if (cur == des) {
		if (inArray(sum)) {
			for (i = 0; i < cur - 1; i++) {
				cout << b[i] << "+";
			}
			cout << b[cur - 1] << "=" << sum << endl;
			EQUAL = true;
		}
	}
	// ��ǰ����������Ŀ�����ʱ
	else {
		for (int i = last; i < SIZE; i++) {
			if (sum + a[i] <= a[SIZE - 1] && b[cur - 1] != a[i]) {
				b[cur] = a[i];		// ��¼·��
				DFS(cur + 1, des, sum + a[i], i);
			}
		}
	}
}

int main()
{
	int length, k =0;
	cin >> length;
	for (int i = 0; i < length; i++) {
		int sum = 0;
		cin >> SIZE;
		for (int j = 0; j < SIZE; j++) {
			cin >> a[j];
		}
		// ������
		sort(a, a+SIZE);
		// �ó�������
		for (k = 0; k < SIZE; k++) {
			sum += a[k];
			if (sum > a[SIZE - 1]) {
				break;
			}
		}
		int deep = k;
		EQUAL = false;
		for (int i = 2; i <= k; i++) {
			DFS(0, i, 0, 0);
		}
		if (!EQUAL) {
			cout << "Can't find any equations." << endl;
		}
		cout << endl;
	}
    return 0;
}

