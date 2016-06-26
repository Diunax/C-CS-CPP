// ZOJ2812-Quicksum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int quickSum(string str) {
	int sum = 0;
	int size = str.size();
	for (int i = 0; i < size; i++) {
		if (str.at(size - i - 1) == 32) continue;
		else 
			sum += (size - i) * (str.at(size - i - 1) - 64);
	}
	return sum;
}

int main()
{
	string str;
	while (1) {
		getline(cin, str);
		if (str != "#") {
			cout << quickSum(str) << endl;
		}
		else {
			return 0;
		}
	}
    return 0;
}

