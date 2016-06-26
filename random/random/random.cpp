// random.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>  
using namespace std;

int main()
{
	srand(101);
	ofstream out("test.txt");
	int count = 20000;
	while(out.is_open() && count--) {
		int n = rand() % 36;
		int m = rand() % 36;
		out << n << endl << m << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				out << rand() % 2;
			}
			out << endl;
		}
	}
	out.close();
    return 0;
}

