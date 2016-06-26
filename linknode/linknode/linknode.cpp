///linknode.cpp
///@version 1.0
///@author Ruiming Zhuang
///@time 2015-9-24 22:00
#include "stdafx.h"
#include<iostream>
using namespace std;
struct link
{
	char data;
	struct link *next;
};
class linknode
{
public:
	void newlink();
	void headinsert();//头插入建表
	void tailinsert();//尾插入建表
	void insertlink(int l, char c);//插入
	void deletelink(int l);//删除
	void searchlink(char c);//查找
	void printlength();//输出表长
	void invertlink();//倒置
	void print();//输出表元素
	int getnum();
private:
	link *head=0, *tail=0, *p,*q;
	int num, i, j;
};
int linknode::getnum()
{
	return num;
}
void linknode::newlink()
{
	head = 0;
	tail = 0;
}
void linknode::print()
{
	if (head == 0 || tail == 0)
	{
		cout << "请先建表！" << endl;
	}
	else
	{
		p = head;
		for (i = 0; i<num; i++)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}
void linknode::headinsert()
{
	if (head == 0 || tail == 0)
	{
		int i;
		tail = head = new link;
		p = new link;
		tail = p;
		cout << "请输入建链元素个数: ";
		cin >> num;
		cout << "请依次输入各元素的值" << endl;
		for (i = 0; i<num; i++)
		{
			cin >> p->data;
			p->next = head;
			head = p;
			p = new link;
		}
		print();
	}
	else
		cout << "表已建立" << endl;
}
void linknode::tailinsert()
{
	if (head == 0 || tail == 0)
	{
		int i;
		tail = head=new link;
		p = new link;
		head = p;
		cout << "请输入建链元素个数: ";
		cin >> num;
		cout << "请依次输入各元素的值" << endl;
		for (i = 0; i<num; i++)
		{
			cin >> p->data;
			tail->next = p;
			tail = p;
			p = new link;
		}
		print();
	}
	else
		cout << "表已建立" << endl;
}
void linknode::insertlink(int l, char c)
{
	cout << "插入前的链表元素:" << endl;
	print();
	link *temp, *q;
	if (l == 1)
	{
		p = new link;
		p->data = c;
		p->next = head;
		head = p;
		num++;
	}
	else if(l>1&&l<=num)
	{
		q = head;
		temp = new link;
		p = new link;
		p->data = c;
		for (i = 1; i < l;i++)
		{
			temp = q;
			q = q->next;	//插入的元素位置
		}
		temp->next = p;
		p->next = q;
		num++;
	}
	else if (l == num+1)
	{
		q = new link;
		q->data = c;
		tail->next = q;
		tail = q;
		num++;
	}
	cout << "插入后的链表元素:" << endl;
	print();
}
void linknode::deletelink(int l)
{
	cout << "删除之前的链表元素:" << endl;
	print();
	if (l == 1)
	{
		p = head;
		head = head->next;
		delete p;
		num--;
	}
	else
	{
		q = new link;
		p = head;
		for (i = 1; i < l; i++)
		{
			q = p;	//q为查找位置的前一位置
			p = p->next;	//p为查找的位置
		}
		if (l != num)
		{
			q->next = p->next;
		}
		else
		{
			q->next = 0;
			tail = q;
		}
		delete p;
		num--;
	}
	cout << "删除之后的链表元素:" << endl;
	print();
}
void linknode::searchlink(char c)
{
	bool find = false;
	p = head;
	for (int i = 1; i <= num; i++)
	{
		if (p->data == c)
		{
			find = true;
			cout << "查找成功，位于位置" << i << endl;
		}
		p = p->next;
	}
	if (!find)
		cout << "查找失败，没有找到该元素!" << endl;
}
void linknode::printlength()
{
	cout << "表长为" << num << endl;
}
void linknode::invertlink()
{
	q = new link;
	p = head;
	head = tail = q;
	for (i = 1; i <= num; i++)
	{
		q->data=p->data;
		q->next = head;
		head = q;
		q = new link;
		p = p->next;
	}
}
int main()
{
	linknode A;
	char use;
	int l;
	char c;
	bool in = false;
	cout << "1.初始化" << endl;
	cout << "2.头插入建表" << endl;
	cout << "3.尾插入建表" << endl;
	cout << "4.插入元素" << endl;
	cout << "5.删除元素" << endl;
	cout << "6.查找元素" << endl;
	cout << "7.输出表长" << endl;
	cout << "8.倒置" << endl;
	cout << "9.退出" << endl;
	while (cin >> use)
	{
		switch (use)
		{
		case '1':A.newlink(); break;
		case '2':A.headinsert(); break;
		case '3':A.tailinsert(); break;
		case '4':
			while (!in)
			{
				cout << "请输入你要插入的元素和插入的位置:";
				cin >> c >> l;
				if (l < 1 || l>A.getnum()+1)
				{
					cout << "超出范围！请重新输入！" << endl;
					in = false;
				}
				else
				{
					A.insertlink(l, c);
					in = true;
				}
			}
			in = false;
			break;
		case '5':
			while (!in)
			{
				cout << "请输入您要删除的元素位置:";
				cin >> l;
				if (l<1 || l>A.getnum())
				{
					cout << "超出范围！请重新输入！" << endl;
					in = false;
				}
				else
				{
					A.deletelink(l); break;
					in = true;
					
				}
			}
			in = false;
			break;
		case '6':
			cout << "请输入您要查找的元素:";
			cin >> c;
			A.searchlink(c);
			break;
		case '7':A.printlength(); break;
		case '8':A.invertlink(); break;
		case '9':exit(0); break;
		case '0':A.print(); break;
		}
	}
}
