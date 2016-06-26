// ZOJ1217-Eight.cpp : 定义控制台应用程序的入口点。
// 方块移动复位问题

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <iterator>
using namespace std;

queue<string> Qu;
map<string, string> Map;
map<string, string>::iterator it;
string a = "12345678x";
string b;


void move(int from, int to, string a) {
	b = a;
	char temp;
	temp = b[to];
	b[to] = b[from];
	b[from] = temp;
	it = Map.find(b);
	if (it == Map.end()) {
		Map[b] = a;
		Qu.push(b);
	}
	else return;
}

void getDirect(string a, string b) {
	int x = a.find('x');
	int y = b.find('x');
	if (y == x - 3)	cout << "d";
	else if (y == x - 1)	cout << "r";
	else if (y == x + 3)	cout << "u";
	else if (y == x + 1)	cout << "l";
}

void search() {
	Qu.push(a);
	while (!Qu.empty()) {
		string t = Qu.front();
		Qu.pop();
		int x = t.find('x');
		if (x % 3 != 2) {			// 右移
			move(x, x + 1, t);
		}
		if (x % 3 != 0) {			// 左移
			move(x, x - 1, t);
		}
		if (x / 3 != 0) {			// 上移
			move(x, x - 3, t);
		}
		if (x / 3 != 2) {			// 下移
			move(x, x + 3, t);
		}
	}
}

int main() {
	search();
	string str = "";
	string data;
	string first;
	while (cin>>first) {
		str = "";
		str += first;
		for (int i = 1; i < 9; i++) {
			cin >> data;
			str += data;
		}
		while (str != a)
		{
			it = Map.find(str);
			if (it == Map.end()) {
				cout << "unsolvable";
				break;
			}
			else {
				getDirect(it->second, it->first);
				str = it->second;
			}
		}
		cout << endl;
	}
	return 0;
}
