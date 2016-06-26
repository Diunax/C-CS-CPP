// math.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include "STACK.h"
using namespace std;
int main(){
	STACK<char> s;
	STACK<double> i;
	double result,b=1,out;
	int count = 0, op = 1, print = 1;
	char ch = '#', ch1;
	s.push(ch);
	string str;
	cout << "暂不支持表达式含正负号，表达式格式如下: 5*(1+6/2)-4= " << endl;
	while (cin >> str)
	{
		int length = str.length();
		const char *p = str.c_str();
		while (!s.isEmpty())
		{
			if (isdigit(*p) || *p == '.')
			{
				double a = *p - 48;
				if (*p == '.')
				{
					b = 0.1;
				}
				else
				{
					if (b != 1)	//b表示前面有无.号，1表示无.号且为第一个数
					{
						out = i.pop();
						if (b==10) {
							out = (out*b + a)*op;
							i.push(out);
						}
						else {
							out = out + a*b*op;
							i.push(out);
							b = b / 10;
						}
					}
					else
					{
						out = a*op;
						i.push(a*op);
						b = 10;
					}
					if(s.getTop()=='-')	result = -out;
					else result = out;
				}
				p++;
				count = 1;//存入数count为1
			}
			else
			{
				b = 1;
				if (count == 0&&(*p=='+'||*p=='-'))
				{
					if (*p == '+')	p++;
					else if (*p == '-')
					{
						op = op*-1;
						count = 0;	//对于正负号进行操作，count扔为0
						p++;
					}
				}
				else
				{
					b = 1;
					ch1 = s.getTop();
					if (isp(ch1) < icp(*p))
					{
						s.push(*p);
						p++;
						count = 0;//存入运算符count为0
					}
					else if (isp(ch1) > icp(*p)&&i.length>1)
					{
						char op = s.pop();
						double a = i.pop();
						double b = i.pop();
						if (a == 0&&op=='/')
						{
							cout << "除数不能为0！" << endl;
							while (!i.isEmpty())	i.pop();
							while (!s.isEmpty())	s.pop();
							s.push('#');
							print = 0;
							continue;
						}
						result = check(b, a, op);
						i.push(result);
						count = 1;//存入数count为1
					}
					else
					{
						char temp = s.pop();
						if (temp == '(')	p++;
						else if (temp == '#') {
							s.push('#');
							break;
						}
					}
					op = 1;
				}
			}
		}
		if (print == 1) {
			cout << "运算结果为: " << result << endl;
			while (s.getTop()!='#')	s.pop();
			while (!i.isEmpty())	i.pop();
			op = 1;
		}
		else {
			print = 1;
			op = 1;
			continue;
		}
	}
	system("pause");
	return 0;
}

