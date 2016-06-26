// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

void merge(int *a, int low, int mid, int high) {
	int *p = new int[high - low];
	int i = low, j = mid + 1;
	for (int k = 0; k<high; k++) {
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
	for (int k = 0; k<high; k++) {
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
	clock_t start_1, end_1, start_2, end_2;
	int a[12] = { 23, 32, 27, 18, 45, 11, 63, 12, 19, 16, 25, 52 };
	int b[12] = { 23, 32, 27, 18, 45, 11, 63, 12, 19, 16, 25, 52 };

	start_1 = clock();
	mergesort(a, 0, 11);
	end_1 = clock();
	cout << "Time used:" << (double)((end_1 - start_1) / CLOCKS_PER_SEC) << endl;

	start_2 = clock();
	quicksort(b, 0, 11);
	end_2 = clock();
	cout << "Time used:" << (double)((end_2 - start_2) / CLOCKS_PER_SEC) << endl;

	for (int i = 0; i<12; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i<12; i++) {
		cout << b[i] << " ";
	}

	return 0;
}
