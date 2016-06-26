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
	void headinsert();//ͷ���뽨��
	void tailinsert();//β���뽨��
	void insertlink(int l, char c);//����
	void deletelink(int l);//ɾ��
	void searchlink(char c);//����
	void printlength();//�����
	void invertlink();//����
	void print();//�����Ԫ��
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
		cout << "���Ƚ���" << endl;
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
		cout << "�����뽨��Ԫ�ظ���: ";
		cin >> num;
		cout << "�����������Ԫ�ص�ֵ" << endl;
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
		cout << "���ѽ���" << endl;
}
void linknode::tailinsert()
{
	if (head == 0 || tail == 0)
	{
		int i;
		tail = head=new link;
		p = new link;
		head = p;
		cout << "�����뽨��Ԫ�ظ���: ";
		cin >> num;
		cout << "�����������Ԫ�ص�ֵ" << endl;
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
		cout << "���ѽ���" << endl;
}
void linknode::insertlink(int l, char c)
{
	cout << "����ǰ������Ԫ��:" << endl;
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
			q = q->next;	//�����Ԫ��λ��
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
	cout << "����������Ԫ��:" << endl;
	print();
}
void linknode::deletelink(int l)
{
	cout << "ɾ��֮ǰ������Ԫ��:" << endl;
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
			q = p;	//qΪ����λ�õ�ǰһλ��
			p = p->next;	//pΪ���ҵ�λ��
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
	cout << "ɾ��֮�������Ԫ��:" << endl;
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
			cout << "���ҳɹ���λ��λ��" << i << endl;
		}
		p = p->next;
	}
	if (!find)
		cout << "����ʧ�ܣ�û���ҵ���Ԫ��!" << endl;
}
void linknode::printlength()
{
	cout << "��Ϊ" << num << endl;
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
	cout << "1.��ʼ��" << endl;
	cout << "2.ͷ���뽨��" << endl;
	cout << "3.β���뽨��" << endl;
	cout << "4.����Ԫ��" << endl;
	cout << "5.ɾ��Ԫ��" << endl;
	cout << "6.����Ԫ��" << endl;
	cout << "7.�����" << endl;
	cout << "8.����" << endl;
	cout << "9.�˳�" << endl;
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
				cout << "��������Ҫ�����Ԫ�غͲ����λ��:";
				cin >> c >> l;
				if (l < 1 || l>A.getnum()+1)
				{
					cout << "������Χ�����������룡" << endl;
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
				cout << "��������Ҫɾ����Ԫ��λ��:";
				cin >> l;
				if (l<1 || l>A.getnum())
				{
					cout << "������Χ�����������룡" << endl;
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
			cout << "��������Ҫ���ҵ�Ԫ��:";
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
