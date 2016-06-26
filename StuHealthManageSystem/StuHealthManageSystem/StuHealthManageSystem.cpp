// StuHealthManageSystem.cpp : 定义控制台应用程序的入口点。
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
//初始化
void HealthManage::reset() {
	count = 0;
	head = 0;
	tail = 0;
}
//插入学生信息
void HealthManage::insertStu() {
	int i,num;
	tail = head = new Stu;
	p = new Stu;
	head = p;
	cout << "请输入学生个数: ";
	cin >> num;
	cout << "请依次输入学生的学号、姓名、出生日期、性别、身体状况。" << endl;
	for (i = 0; i<num; i++)
	{
		cin >> p->id>>p->name>>p->date>>p->sex>>p->health;
		tail->next = p;
		tail = p;
		p = new Stu;
		count++;
	}
	cout << "添加成功" << endl;
}
//删除学生信息
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
	if (!find)	cout << "该学生信息不存在！" << endl;
	else  cout << "删除成功！" << endl;
}
//查找学生信息
void HealthManage::searchStu(string id) {
	bool find = false;
	p = head;
	for (int i = 1; i <= count; i++)
	{
		if (p->id == id)
		{
			find = true;
			cout << "学号  姓名  出生日期  性别  身体状况" << endl;
			cout << p->id << "  " << p->name << "  " << p->date << "  "<<p->sex<<"    " << p->health << endl;
		}
		p = p->next;
	}
	if (!find)
		cout << "该学生信息不存在" << endl;
}
//输出全部学生信息
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
	cout << "学生健康情况管理系统" << endl;
	cout << "1.新建学生健康表" << endl;
	cout << "2.插入学生信息" << endl;
	cout << "3.删除学生信息" << endl;
	cout << "4.查询学生信息" << endl;
	cout << "5.输出学生信息" << endl;
	cout << "6.退出" << endl;
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
			cout << "输入删除的学生学号: ";
			cin >> id;
			A.deleteStu(id);
			break;
		case 4:
			cout << "输入查找的学生学号: ";
			cin >> id;
			A.searchStu(id);
			break;
		case 5:
			cout << "*****学生健康信息*****"<<endl;
			cout << "学号  姓名  出生日期  性别  身体状况" << endl;
			A.print();
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}