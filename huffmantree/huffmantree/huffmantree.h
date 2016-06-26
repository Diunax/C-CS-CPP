#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<fstream>
#include<math.h>
using namespace std;
struct huffmanNode{
	huffmanNode(char tdata, int tweight) {
		data = tdata;
		weight = tweight;
		left = NULL;
		right = NULL;
	}
	huffmanNode() {
		data = ' ';
		weight = 0;
		left = NULL;
		right = NULL;
	}
	huffmanNode* huffmamNode(huffmanNode a) {
		huffmanNode *A;
		A = new huffmanNode();
		A->left = a.left;
		A->right = a.right;
		A->weight = a.weight;
		A->data = a.data;
		return A;
	}
	char data;
	int weight;
	huffmanNode *left;
	huffmanNode *right;
};
class huffmanTree {
public:
	void create(huffmanNode nodes[],int size);
	void sort(huffmanNode *nodes,int size);
	void preOutput();
	void encoding();
	void decoding();
	void print();
	char getChar(string str);
	string toBinary(int num);
	huffmanNode *root;
	map<string, char>key;
};
string huffmanTree::toBinary(int num) {
	int a;
	string b = "";
	do
	{
		a = num % 2;
		if (a == 1)	b="1"+b;
		else b="0"+b;
		num = (num - a) / 2;
	} while (num != 0);
	return b;
}
void huffmanTree::sort(huffmanNode *nodes,int size) {
	for (int i = 0; i < size-1; i++)
		for (int j = i; j < size; j++) {
			if ((nodes + i)->weight > (nodes + j)->weight) {
				huffmanNode temp = *(nodes + i);
				*(nodes + i) = *(nodes + j);
				*(nodes + j) = temp;
			}
		}
}
void huffmanTree::create(huffmanNode nodes[],int size) {
	huffmanNode *A=NULL;
	sort(nodes, size);
	for (int i = 0; i < size - 1; i++) {
		A = new huffmanNode('#', nodes[i].weight + nodes[i + 1].weight);
		if (nodes[i].weight > nodes[i + 1].weight)
		{
			A->left = new huffmanNode(nodes[i+1]);
			A->right = new huffmanNode(nodes[i]);
		}
		else if (nodes[i].weight <= nodes[i + 1].weight)
		{
			A->left = new huffmanNode(nodes[i]);
			A->right = new huffmanNode(nodes[i + 1]);
		}
		nodes[i + 1] = *A;
		sort(nodes + i + 1, size - i - 1);
	}
	root = A;
}
void huffmanTree::preOutput() {
	stack<huffmanNode *>s;
	huffmanNode *p = root;
	cout << "字符: ";
	s.push(NULL);
	while (p != NULL) {
		if(p->data!='#')	cout << p->data;
		if (p->right != NULL)	s.push(p->right);
		if (p->left != NULL) p = p->left;
		else {
			p = s.top();
			s.pop();
		}
	}
	cout << endl;
}
void huffmanTree::encoding() {  //层次遍历
	string str="";
	queue<huffmanNode *>s;
	huffmanNode *p = root;
	s.push(root);
	int i = -1;
	while (!s.empty()) {
		p = s.front(); 
		s.pop();
		if (p->data != '#') {
			char data = p->data;
			if (data != '#') {
				str += toBinary(i);
				key.insert(pair<string, char>(toBinary(i),data));
			}
		}
		i++;
		if (p->left != NULL)	s.push(p->left);
		if (p->right != NULL)	s.push(p->right);
	}
	ofstream outdata;
	outdata.open("Codefile", ios::trunc);
	outdata << str;
	cout << "编码: " << str<<endl;
	outdata.close();
}
char huffmanTree::getChar(string str){
	map<string, char>::iterator iter = key.find(str);
	if (iter != key.end())	return iter->second;
	else return '#';
}
void huffmanTree::decoding() {
	string str,output,streamdata="";
	int m=0,y=0;
	ofstream outdata;
	ifstream indata;
	indata.open("Codefile");
	indata >> str;
	indata.close();
	int i = 0;
	bool end=false;
	cout << "译码: ";
	do {
		int u = i+1;//第i行每一个节点有u个字符
		int j = pow(2,u-1);//第i行最多有j个节点
		for (int k = 0; k <= j; k++) {
			for (int t = 0; t < u; t++,y++) {
				if (y < str.length())
					output += str[y];
				else
					break;
			}
			if (output == "") {
				end = true;
				break;
			}
			if (getChar(output) != '#') {
				cout << getChar(output);
				streamdata=+ getChar(output);
				m = m + u;
			}
			y = m;
			output = "";
		}
		if (end) {
			cout << endl;
			break;
		}
		i++;
	} while (1);
	outdata.open("Textfile", ios::trunc);
	outdata << streamdata;
	outdata.close();
}
void huffmanTree::print() {
	bool end = false;
	string str,outprint="";
	ifstream indata;
	ofstream outdata;
	indata.open("Codefile");
	indata >> str;
	indata.close();
	outdata.open("CodePrint", ios::trunc);
	int length = str.length();
	int count = length % 50+1;
	cout << "输出:";
	for (int i = 0; i < length; i++) {
		for (int j = i; j < 50; j++) {
			if ((50 * i + j)>length)	break;
			outprint += str[50*i+j];
		}
		if (outprint == "")	break;
		cout << outprint << endl;
		outdata << outprint<<'\r';
		outprint = "";
	}
	outdata.close();
}