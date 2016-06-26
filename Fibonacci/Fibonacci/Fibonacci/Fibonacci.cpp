/*
 * Fibonacci
 * 2016.5.25
 *
 */

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

// 动态规划解法
int fibonacci(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	int* p = new int[n+1];
	p[1] = 1;
	p[2] = 1;
	for (int i = 3; i < n+1; i++) {
		p[i] = p[i - 1] + p[i - 2];
	}
	return p[n];
}

// 递归方法
int fibonacci_2(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return fibonacci_2(n - 1) + fibonacci(n - 2);
	}
}

int main()
{
	clock_t start_1, end_1, start_2, end_2;
	int n;
	int test[10] = { 12, 16, 21, 24, 6, 11, 41, 23, 19, 15 };
	cout << "Input n: ";
	cin >> n;

	start_1 = clock();
	for (int j = 0; j < 10; j++)
		for (int i = 0; i < 10; i++) {
			fibonacci(test[i]);
		}
	end_1 = clock();
	cout << "Dynamic programming - Time used: " << (double)(end_1 - start_1)/CLOCKS_PER_SEC << "S" <<endl;

	start_2 = clock();
	for (int j = 0; j < 10; j++)
		for (int i = 0; i < 10; i++) {
			fibonacci_2(test[i]);
		}
	end_2 = clock();
	cout << "Recursion - Time used: " << (double)(end_2 - start_2) / CLOCKS_PER_SEC << "S" << endl;

    return 0;
}

