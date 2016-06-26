#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
template<class T>
struct BinTreeNode {
	T data;
	BinTreeNode<T> *left, *right;
	int judge;
	BinTreeNode() {
		left = 0;
		right = 0;
		judge = 0;
	};
	BinTreeNode(T x) {
		left = 0;
		right = 0;
		judge = 0;
		data = x;
	};
};
template <class T>
class BinTree {
public:
	BinTree();
	void Create(string str);			//建立二叉树
	void preDgOutput();                 //输出二叉树
	void midDgOutput();
	void lastDgOutput();
	void preNdgOutput(BinTreeNode<T> *t);
	void midNdgOutput(BinTreeNode<T> *t);
	void lastNdgOutput(BinTreeNode<T> *t);
	void Children();
	BinTreeNode<T>* getRoot();
private:
	BinTreeNode<T> *root, *left, *right;
	BinTreeNode<T> *TR;
};
template <class T>
BinTree<T>::BinTree() {
	root = new BinTreeNode<T>();
}
template <class T>
void BinTree<T>::Create(string str) {
	stack<BinTreeNode<T> *> s;
	BinTreeNode<T> *first, *second;
	TR = NULL;
	int k = 0;
	int length = str.length();
	for (int i = 0; i < length; i++) {
		switch (str[i]) {
		case '(':
			s.push(second);
			k = 1;
			break;
		case ')':
			s.pop();
			break;
		case ',':
			k = 2;
			break;
		default:
			second = new BinTreeNode<T>(str[i]);
			if (TR == NULL) {
				TR = second;
				root = TR;
			}
			else if (k == 1) {
				first = s.top();
				first->left = second;
			}
			else if (k == 2) {
				first = s.top();
				first->right = second;
			}
		}
	}
}
template <class T>
BinTreeNode<T> * BinTree<T>::getRoot() {
	return root;
}
//前序遍历非递归算法
template <class T>
void BinTree<T>::preDgOutput() {
	stack<BinTreeNode<T> *>s;
	BinTreeNode<T> *p = root;
	s.push(NULL);
	while (p != NULL) {
		cout << p->data;
		if (p->right != NULL)	s.push(p->right);
		if (p->left != NULL) p = p->left;
		else {
			p = s.top();
			s.pop();
		}
	}
}
//中序遍历非递归算法
template <class T>
void BinTree<T>::midDgOutput() {
	stack<BinTreeNode<T> *>s;
	BinTreeNode<T> *p = root;
	do {
		while (p != NULL) {
			s.push(p);
			p = p->left;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			cout << p->data;
			p = p->right;
		}
	} while (p != NULL || !s.empty());
}
//后序遍历非递归算法
template <class T>
void BinTree<T>::lastDgOutput() {
	stack<BinTreeNode<T> *>s;
	BinTreeNode<T> *p = root;
	while (p != NULL) {
		s.push(p);
		p = p->left;
	}
	while (!s.empty()) {
		p = s.top();
		if (p->right == NULL || p->judge == 1) {
			s.pop();
			cout << p->data;
		}
		else {
			p->judge = 1;
			p = p->right;
			while (p != NULL) {
				s.push(p);
				p = p->left;
			}
		}
	}
}
//前序遍历递归算法
template <class T>
void BinTree<T>::preNdgOutput(BinTreeNode<T> *t) {
	if (t != NULL) {
		cout << t->data;
		preNdgOutput(t->left);
		preNdgOutput(t->right);
	}
}
//中序遍历递归算法
template <class T>
void BinTree<T>::midNdgOutput(BinTreeNode<T> *t) {
	if (t != NULL) {
		midNdgOutput(t->left);
		cout << t->data;
		midNdgOutput(t->right);
	}
}
//后序遍历递归算法
template <class T>
void BinTree<T>::lastNdgOutput(BinTreeNode<T> *t) {
	if (t != NULL) {
		lastNdgOutput(t->left);
		lastNdgOutput(t->right);
		cout << t->data;
	}
}
template <class T>
void BinTree<T>::Children() {
	stack<BinTreeNode<T> *>s, t;
	BinTreeNode<T> *p = root;
	BinTreeNode<T> *q, *head;
	q = new BinTreeNode<T>();
	head = q;
	s.push(NULL);
	t.push(NULL);
	while (p != NULL) {
		if (p->left == NULL&&p->right == NULL)	t.push(p);
		if (p->left != NULL)	s.push(p->left);
		if (p->right != NULL)	p = p->right;
		else {
			p = s.top();
			s.pop();
		}
	}
	q = head = t.top();
	t.pop();
	while (t.top() != NULL)
	{
		q->right = t.top();
		t.pop();
		q = q->right;
	}
	int i = 0;
	while (head != NULL) {
		i++;
		head = head->right;
	}
	cout << i<<endl;
}