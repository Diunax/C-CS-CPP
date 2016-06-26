// StuHealthManageSystem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
struct Stu {
	string id;
	string name;
	string date;
	string sex;
	string health;
	Stu *next;
};
class HealthManage {
public:
	void reset();
	void insertStu();
	void deleteStu(string id);
	void searchStu(string id);
	void print();
private:
	Stu *head,*tail,*p,*q;
	int count;
};
//��ʼ��
void HealthManage::reset() {
	count = 0;
	head = 0;
	tail = 0;
}
//����ѧ����Ϣ
void HealthManage::insertStu() {
	int i,num;
	tail = head = new Stu;
	p = new Stu;
	head = p;
	cout << "������ѧ������: ";
	cin >> num;
	cout << "����������ѧ����ѧ�š��������������ڡ��Ա�����״����" << endl;
	for (i = 0; i<num; i++)
	{
		cin >> p->id>>p->name>>p->date>>p->sex>>p->health;
		tail->next = p;
		tail = p;
		p = new Stu;
		count++;
	}
	cout << "��ӳɹ�" << endl;
}
//ɾ��ѧ����Ϣ
void HealthManage::deleteStu(string id) {
	int l = 1;
	bool find = false;
	p = head;
	for (int i = 0; i < count; i++) {
		if (p->id == id) {
			find = true;
			if (l == 1)
			{
				p = head;
				head = head->next;
				delete p;
				count--;
			}
			else
			{
				q = new Stu;
				p = head;
				for (i = 1; i < l; i++)
				{
					q = p;
					p = p->next;
				}
				if (l != count)
				{
					q->next = p->next;
				}
				else
				{
					q->next = 0;
					tail = q;
				}
				delete p;
				count--;
			}
		}
		p = p->next;
		l++;
	}
	if (!find)	cout << "��ѧ����Ϣ�����ڣ�" << endl;
	else  cout << "ɾ���ɹ���" << endl;
}
//����ѧ����Ϣ
void HealthManage::searchStu(string id) {
	bool find = false;
	p = head;
	for (int i = 1; i <= count; i++)
	{
		if (p->id == id)
		{
			find = true;
			cout << "ѧ��  ����  ��������  �Ա�  ����״��" << endl;
			cout << p->id << "  " << p->name << "  " << p->date << "  "<<p->sex<<"    " << p->health << endl;
		}
		p = p->next;
	}
	if (!find)
		cout << "��ѧ����Ϣ������" << endl;
}
//���ȫ��ѧ����Ϣ
void HealthManage::print() {
	p = head;
	for (int i = 1; i <= count; i++)
	{
		cout << p->id << "  " << p->name << "  " << p->date << "  " << p->sex <<"    "<< p->health << endl;
		p = p->next;
	}
}
int main()
{
	HealthManage A;
	int turn = 0;
	string id;
	cout << "ѧ�������������ϵͳ" << endl;
	cout << "1.�½�ѧ��������" << endl;
	cout << "2.����ѧ����Ϣ" << endl;
	cout << "3.ɾ��ѧ����Ϣ" << endl;
	cout << "4.��ѯѧ����Ϣ" << endl;
	cout << "5.���ѧ����Ϣ" << endl;
	cout << "6.�˳�" << endl;
	while (1) {
		cin >> turn;
		switch (turn) {
		case 1:
			A.reset();
			break;
		case 2:
			A.insertStu();
			break;
		case 3:
			cout << "����ɾ����ѧ��ѧ��: ";
			cin >> id;
			A.deleteStu(id);
			break;
		case 4:
			cout << "������ҵ�ѧ��ѧ��: ";
			cin >> id;
			A.searchStu(id);
			break;
		case 5:
			cout << "*****ѧ��������Ϣ*****"<<endl;
			cout << "ѧ��  ����  ��������  �Ա�  ����״��" << endl;
			A.print();
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}