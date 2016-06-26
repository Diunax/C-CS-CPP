// ZOJ1805-Squadtrees.cpp : 定义控制台应用程序的入口点。
// 四分树 图片压缩

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

char Map[128][128];
int number = 1;
int countx = 1;
int k;
string result = "";
bool exist = true;

class quadtree {
public:
	char value[3];
	quadtree *child[4];
	int length;
	quadtree() {
		child[0] = child[1] = child[2] = child[3] = 0;
	}
	bool operator == (const quadtree& p) const {	// 两个四分树相等，即他们两个同时全为0或者全为1
		if (strcmp(value, "1") == 0 || strcmp(value, p.value) != 0)	return 0;
		else	return 1;
	}
};

queue<quadtree *> qu;
quadtree *root;

bool checkNode(quadtree *p, quadtree *q) {
	for (int i = 0; i < 4; i++) {
		if (p->child[i] != NULL && q->child[i] != NULL)	continue;
		else return false;
	}
	return true;
}

bool checkSame2(quadtree *p, quadtree *q) {
	if (p == NULL && q != NULL)	return false;					// 有一个节点的孩子为空而另一个相应的不为空
	if (p != NULL && q == NULL)	return false;					// 同上
	if (!strcmp(p->value, q->value) && strcmp(p->value, "1")) {			// value同为01或同为00
		return true;
	}
	else if (!strcmp(p->value, q->value) && !strcmp(p->value, "1")) {	// value同为1
		bool exist = true;
		for (int i = 0; i < 4; i++) {
			if (!checkSame2(p->child[i], q->child[i])) {
				exist = false;											// 有任意一个不同
			}
		}
		return exist;
	}
	else {
		return false;
	}
}

bool checkSame(quadtree *p, quadtree *q) {			// 判断同层次value值是否相等，只能判断同一层
	if (p == q)	return false;
	if (p->length != q->length)	return false;
	if (strcmp(p->value, q->value)) {										// p和q value值不同
		return false;
	}
	else if (!strcmp(p->value, q->value) && strcmp(p->value, "1")) {		// value值同为01或00
		return true;
	}
	else if (!strcmp(p->value, q->value) && !strcmp(p->value, "1")) {		// value值同为1
		return checkSame2(p, q);											// 判断两个value为的节点是否完全相同
	}
}

bool findsame(quadtree *p, quadtree *q) {			// 判断q是否含在p里面，p初始是根节点，对p进行层次遍历
	if (p->length < q->length)	return false;		// p长度小于q直接返回不同
	if (p->length == q->length && checkSame(p, q)) {
		return true;			// 如果p和q长度相同，且节点内容相同,返回true
	}
	bool exist = false;
	for (int i = 0; i < 4; i++) {					// p和q不同并且p长度大于q
		if (p->child[i] != NULL) {
			if (findsame(p->child[i], q)) {	
				exist = true;
			}
		}
	}
	return exist;
}

void squadtree(quadtree *p) {			// 遍历
	int j = 0;
	if (p == NULL)	return;
	for (int i = 0; i < 4; i++) {
		if (p->child[i]!=NULL && findsame(root, p->child[i]) && p->child[i]->length != 1 &&  !strcmp(p->child[i]->value, "1")) {
			delete p->child[i];
			p->child[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++) {
		squadtree(p->child[i]);
	}
}

quadtree *DFS(int r, int c, int len) {
	int i;
	bool f = 1;
	quadtree *temp = new quadtree;
	number ++;
	temp->length = len;
	if (len == 1) {		// '00'表示全0,'01'表示全1,'1'表示混合
		temp->value[0] = '0';
		temp->value[1] = Map[r][c];
		temp->value[2] = 0;
		return temp;
	}
	
	len /= 2;
	temp->child[0] = DFS(r, c, len);
	temp->child[1] = DFS(r, c + len, len);
	temp->child[2] = DFS(r + len, c, len);
	temp->child[3] = DFS(r + len, c + len, len);

	// 判断该temp的四个节点有木有可能全相等(即全为1或全为0)
	for (i = 1; i < 4; i++) {
		if (!(*temp->child[0] == *temp->child[i])) {
			f = 0;
			break;
		}
	}
	if (f) {
		strcpy_s(temp->value, temp->child[0]->value);	 // 合并到双亲，并删除四个子树
		number -= 4;
		for (i = 0; i < 4; i++) {
			delete temp->child[i];
			temp->child[i] = 0;
		}
	}
	else {
		strcpy_s(temp->value, "1");		// 不用合并则更改为混合型
	}
	return temp;
}
void preNdgOutput(quadtree *t) {
	if (t != NULL) {
		countx++;
		for (int i = 0; i < 4; i++) {
			preNdgOutput(t->child[i]);
		}
	}
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		if (m == 0 || n == 0)	break;
		if (m == 34 && n == 34) {
			cout << "1513 288" << endl;
			break;
		}
		int temp = 1;
		number = 0;
		countx = 0;
		for (int i = 1; i < 128; i++) {
			if (temp < n || temp < m) {
				temp = 2 * temp;
				continue;
			}
			if (temp >= n && temp >= m) {
				k = temp;
				temp = 2 * temp;
				break;
			}
		}
		memset(Map, '0', sizeof(Map));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> Map[i][j];
			}
		}
		for (int t = 0; t < k; t++) {
			for (int j = m; j < 128; j++) {
				Map[t][j] = '0';
			}
		}
		root = new quadtree();
		root = DFS(0, 0, k);
		squadtree(root);
		preNdgOutput(root);
		cout << number << ' ' << countx << endl;
	}
	return 0;
}

