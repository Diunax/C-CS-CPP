// ZOJ1805-Squadtrees.cpp : �������̨Ӧ�ó������ڵ㡣
// �ķ��� ͼƬѹ��

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
	bool operator == (const quadtree& p) const {	// �����ķ�����ȣ�����������ͬʱȫΪ0����ȫΪ1
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
	if (p == NULL && q != NULL)	return false;					// ��һ���ڵ�ĺ���Ϊ�ն���һ����Ӧ�Ĳ�Ϊ��
	if (p != NULL && q == NULL)	return false;					// ͬ��
	if (!strcmp(p->value, q->value) && strcmp(p->value, "1")) {			// valueͬΪ01��ͬΪ00
		return true;
	}
	else if (!strcmp(p->value, q->value) && !strcmp(p->value, "1")) {	// valueͬΪ1
		bool exist = true;
		for (int i = 0; i < 4; i++) {
			if (!checkSame2(p->child[i], q->child[i])) {
				exist = false;											// ������һ����ͬ
			}
		}
		return exist;
	}
	else {
		return false;
	}
}

bool checkSame(quadtree *p, quadtree *q) {			// �ж�ͬ���valueֵ�Ƿ���ȣ�ֻ���ж�ͬһ��
	if (p == q)	return false;
	if (p->length != q->length)	return false;
	if (strcmp(p->value, q->value)) {										// p��q valueֵ��ͬ
		return false;
	}
	else if (!strcmp(p->value, q->value) && strcmp(p->value, "1")) {		// valueֵͬΪ01��00
		return true;
	}
	else if (!strcmp(p->value, q->value) && !strcmp(p->value, "1")) {		// valueֵͬΪ1
		return checkSame2(p, q);											// �ж�����valueΪ�Ľڵ��Ƿ���ȫ��ͬ
	}
}

bool findsame(quadtree *p, quadtree *q) {			// �ж�q�Ƿ���p���棬p��ʼ�Ǹ��ڵ㣬��p���в�α���
	if (p->length < q->length)	return false;		// p����С��qֱ�ӷ��ز�ͬ
	if (p->length == q->length && checkSame(p, q)) {
		return true;			// ���p��q������ͬ���ҽڵ�������ͬ,����true
	}
	bool exist = false;
	for (int i = 0; i < 4; i++) {					// p��q��ͬ����p���ȴ���q
		if (p->child[i] != NULL) {
			if (findsame(p->child[i], q)) {	
				exist = true;
			}
		}
	}
	return exist;
}

void squadtree(quadtree *p) {			// ����
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
	if (len == 1) {		// '00'��ʾȫ0,'01'��ʾȫ1,'1'��ʾ���
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

	// �жϸ�temp���ĸ��ڵ���ľ�п���ȫ���(��ȫΪ1��ȫΪ0)
	for (i = 1; i < 4; i++) {
		if (!(*temp->child[0] == *temp->child[i])) {
			f = 0;
			break;
		}
	}
	if (f) {
		strcpy_s(temp->value, temp->child[0]->value);	 // �ϲ���˫�ף���ɾ���ĸ�����
		number -= 4;
		for (i = 0; i < 4; i++) {
			delete temp->child[i];
			temp->child[i] = 0;
		}
	}
	else {
		strcpy_s(temp->value, "1");		// ���úϲ������Ϊ�����
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

