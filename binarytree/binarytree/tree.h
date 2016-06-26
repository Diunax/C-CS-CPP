#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
template<class T>
struct binaryTree {
	T data;
	binaryTree<T> *left, *right;
	binaryTree() {
		left = 0;
		right = 0;
	};
	binaryTree(T x) {
		left = 0;
		right = 0;
		data = x;
	};
};
template <class T>
class BinTree{
public:
	BinTree();
	void Create(string str);
	void Exchange(binaryTree<T> *p);
	void Output();
	bool Check(binaryTree<T> *B1, binaryTree<T> *B2);
	void Copy(binaryTree<T> *B1, binaryTree<T> *B2);
	void Children();
	binaryTree<T>* getRoot();
private:
	binaryTree<T> *root, *left, *right;
	binaryTree<T> *TR;
};
template <class T>
BinTree<T>::BinTree() {
	root = new binaryTree<T>();
}
template <class T>
void BinTree<T>::Create(string str) {
	stack<binaryTree<T> *> s;
	binaryTree<T> *first,*second;
	TR = NULL;
	int k=0;
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
			second = new binaryTree<T>(str[i]);
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
void BinTree<T>::Exchange(binaryTree<T> *p) {
	binaryTree<T> *temp;
	if (p->left != 0) {
		Exchange(p->left);
		temp = p->left;
		p->left = p->right;
		p->right = temp;
	}
	else if (p->right != 0) {
		Exchange(p->right);
		temp = p->right;
		p->right = p->left;
		p->left = temp;
	}
}
template <class T>
binaryTree<T> * BinTree<T>::getRoot() {
	return root;
}
template <class T>
//前序遍历输出
void BinTree<T>::Output() {
	stack<binaryTree<T> *>s;
	binaryTree<T> *p = root;
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
template <class T>
bool BinTree<T>::Check(binaryTree<T> *B1, binaryTree<T> *B2) {
	stack<binaryTree<T> *>s1,s2;
	binaryTree<T> *p = B1;
	binaryTree<T> *q = B2;
	s1.push(NULL);
	s2.push(NULL);
	while (p != NULL) {
		if (p->data != q->data)	return false;
		if (p->right != NULL) {
			if (q->right == NULL) {
				return false;
			}
			else {
				s1.push(p->right);
				s2.push(q->right);
			}
		}
		if (p->left != NULL) {
			if (q->left == NULL) {
				return false;
			}
			else {
				p = p->left;
				q = q->left;
			}
		}
		else {
			p = s1.top();
			q = s2.top();
			s1.pop();
			s2.pop();
		}
	}
	return true;
}
template <class T>
void BinTree<T>::Copy(binaryTree<T> *B1, binaryTree<T> *B2) {
	stack<binaryTree<T> *>s1, s2;
	binaryTree<T> *p = B1;
	binaryTree<T> *q = B2;
	int t = 3;
	s1.push(NULL);
	s2.push(NULL);
	while (p != NULL) {
		if (t == 3) {
			B2->data = p->data;
		}
		else if (t == 1) {
			q->left = new binaryTree<T>(p->data);
			q = q->left;
		}
		else {
			q->right = new binaryTree<T>(p->data);
			q = q->right;
		}
		if (p->right != NULL) {
			s1.push(p->right);
			s2.push(q);
		}
		if (p->left != NULL) {
			p = p->left;
			t = 1;
		}
		else {
			p = s1.top();
			q = s2.top();
			s1.pop();
			s2.pop();
			t = 0;
		}
	}
}
template <class T>
void BinTree<T>::Children() {
	stack<binaryTree<T> *>s,t;
	binaryTree<T> *p = root;
	binaryTree<T> *q,*head;
	q = new binaryTree<T>();
	head = q;
	s.push(NULL);
	t.push(NULL);
	while (p != NULL) {
		if(p->left==NULL&&p->right==NULL)	t.push(p);
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
	cout << "叶子节点为: ";
	while (head != NULL) {
		cout << head->data<<" ";
		head = head->right;
	}
}
template <class T>
void BinTree<T>::LinktoArray(char []a) {
}