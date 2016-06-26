// Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
#define number 100
using namespace std;

void merge(int *a, int low, int mid, int high) {
	int *p;
	p = new int[high - low + 100];
	int i = low, j = mid + 1;
	for (int k = 0; k <= high; k++) {
		if (i > mid) {
			p[k] = a[j];
			j++;
		}
		else if (j > high) {
			p[k] = a[i];
			i++;
		}
		else {
			if (a[i] <= a[j]) {
				p[k] = a[i];
				i++;
			}
			else if (a[i] > a[j]) {
				p[k] = a[j];
				j++;
			}
		}
	}
	for (int k = 0; k <= high; k++) {
		a[low] = p[k];
		low++;
	}
}

void mergesort(int *a, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int split(int *a, int low, int high) {
	int x = a[low];
	int i = low;
	for (int j = low + 1; j <= high; j++) {
		if (a[j] <= x) {
			i = i + 1;
			if (i != j) {
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	a[low] = a[i];
	a[i] = x;
	return i;
}

void quicksort(int *a, int low, int high) {
	if (low < high) {
		int w = split(a, low, high);
		quicksort(a, low, w - 1);
		quicksort(a, w + 1, high);
	}
}

int main() {
	DWORD start_1, end_1, start_2, end_2;
	srand(time(0));
	int **p = new int*[200];
	int **q = new int*[200];
	for (int i = 0; i < 200; i++) {
		p[i] = new int[number];
		q[i] = new int[number];
		for (int j = 0; j < number; j++) {
			q[i][j] = p[i][j] = rand() % 9000000;
		}
	}

	start_1 = clock();
	for (int i = 0; i < 200; i++) {
		quicksort(p[i], 0, 99);
	}
	end_1 = clock();


	start_2 = clock();
	for (int i = 0; i < 200; i++) {
		mergesort(q[i], 0, 99);
	}
	end_2 = clock();


	cout << "quicksort Time used:" <<static_cast<double> (end_1 - start_1) / CLOCKS_PER_SEC *1000 << "ms" << endl;
	cout << "mergesort Time used:" << static_cast<double> (end_2 - start_2) / CLOCKS_PER_SEC * 1000 << "ms" << endl;

	return 0;
}
