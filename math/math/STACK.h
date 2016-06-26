#pragma once
#include<string>
using namespace std;
double check(double c,double d,char op)
{
	switch (op)
	{
	case '+':return c + d;
	case '-':return c - d;
	case '*':return c*d;
	case '/':return c / d;
	}
}
/* STRUCT PRIORITY */
template <typename T>
struct linknode
{
	T data;
	linknode *next;
};

/* CLASS STACK */
template <typename T>
class STACK
{
public:
	STACK();
	void push(T c);
	T pop();
	T getTop();
	bool isEmpty();
	int length;
private:
	linknode<T> *head, *tail, *p,*q;
};
template <typename T>
STACK<T>::STACK()
{
	head = tail = new linknode<T>;
	head = tail = 0;
	length = 0;
}
template <typename T>
void STACK<T>::push(T c)
{
	p = new linknode<T>;
	if (length == 0)
	{
		tail = head = new linknode<T>;
		head = p;
	}
	p->data = c;
	tail->next = p;
	tail = p;
	length++;
}
template <typename T>
T STACK<T>::pop()
{
	p = head;
	q = new linknode<T>;
	if (length == 1)
	{
		T back = p->data;
		delete p;
		length=0;
		tail = head = 0;
		return back;
	}
	else if(length>1)
	{
		for (int i = 1; i < length; i++)
		{
			q = p;
			p = p->next;
		}
		tail = q;
		T back = p->data;
		length--;
		delete p;
		return back;
	}
}
template <typename T>
T STACK<T>::getTop()
{
	return tail->data;
}
template <typename T>
bool STACK<T>::isEmpty()
{
	if (length == 0)	return true;
	else
	{
		return false;
	}
}
/*  PRIORITY */
	int isp(char c)
	{
		switch (c)
		{
		case '#':return 0;
		case '(':return 1;
		case '*':
		case '%':
		case '/':return 5;
		case '+':
		case '-':return 3;
		case ')':return 6;
		}
	}
	int icp(char c)
	{
		switch (c)
		{
		case '#':return 0;
		case '(':return 6;
		case '*':
		case '%':
		case '/':return 4;
		case '+':
		case '-':return 2;
		case ')':return 1;
		case '=':return 0;
		}
	}