#include "stdafx.h"
#include <iostream>
using namespace std;
struct BSnode
{
	int data;
	BSnode *left, *right;
	BSnode()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
};
class BS
{
public:
	BS();
	void build();
	void preshow() { preshow(root); };
	bool insert(int a);
	bool search(int x);
private:
	BSnode * search(int x, BSnode *p);
	bool insert(int x, BSnode *&ptr);
	void preshow(BSnode *p);
	BSnode *root;
	int count;
};
BS::BS()
{
	root = NULL;
	count = 0;
}
bool BS::insert(int a)
{ 
	return insert(a, root); 
};
bool BS::search(int x)
{ 
	return search(x, root) != NULL ? true : false; 
};
bool BS::insert(int x, BSnode *&ptr)
{
	if (ptr == NULL)
	{
		ptr = new BSnode;
		ptr->data = x;
		return true;
	}
	else if (x<ptr->data) insert(x, ptr->left);
	else if (x>ptr->data) insert(x, ptr->right);
	else return false;
}
void BS::build()
{
	int data;
	cout << "请输入结点个数：";
	cin >> count;
	cout << "输入对应的数据：";
	for (int i = 0; i < count; i++)
	{
		cin >> data;
		insert(data, root);
	}
}
void BS::preshow(BSnode *p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		preshow(p->left);
		preshow(p->right);
	}
}
BSnode * BS::search(int x, BSnode *p)
{
	if (p == NULL) return NULL;
	else if (x<p->data) return search(x, p->left);
	else if (x>p->data) return search(x, p->right);
	else return p;

}
int main()
{
	int data;
	BS A;
	A.build();
	cout << "输入查找的数据:";
	cin >> data;
	cout << "前序遍历:";
	A.preshow();
	if (A.search(data))
		cout << "能查找到";
	else
		cout << "查找不到";
}
