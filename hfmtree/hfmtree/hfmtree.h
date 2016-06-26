#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
struct hfmnode
{
	char ch;
	int weight;
	hfmnode *left;
	hfmnode *right;
	hfmnode *parent;
	bool operator <= (hfmnode&R) { return weight <= R.weight; }
	bool operator > (hfmnode&R) { return weight>R.weight; }
	hfmnode operator = (hfmnode&R)
	{
		ch = R.ch;
		weight = R.weight;
		left = R.left;
		right = R.right;
		parent = R.parent;
		return *this;
	}
};

class HuffmanTree
{
public:
	HuffmanTree(int value[], int n, char k[]);
	HuffmanTree() { loadtree(); }
	~HuffmanTree();
	void Build(int value[], int n, char k[]);
	void makeList();
	void printList();
	void preorder() { preorder(root); }
	void writefile(string text);
	string encode(char x) { coding = ""; return encode(x, root, coding); }
	char decode(string x) { return decode(x, root); }
	void Encoding();
	void Decoding();
	void Huffmancode() { Huffmancode(root); }
	int Height() { return Height(root); }
	void Print();
	void printing()
	{
		fstream fio;
		fio.open("TreePrint.txt", ios::out);
		if (!fio)cerr << "can't open file!" << endl;
		printing(root, 0, fio);
		fio.close();
	}
	void save();
	void ordersave(hfmnode *p, fstream &fio);
	void load();
	void loadtree();
private:
	void preorder(hfmnode *p);
	string encode(char x, hfmnode *p, string coding);
	char decode(string x, hfmnode *p);
	void Huffmancode(hfmnode *p);
	int Height(hfmnode *p);
	void printing(hfmnode *p, int h, fstream &fio);
	hfmnode *root;
	hfmnode *List;
	int ListLength;
	string coding;
};
HuffmanTree::HuffmanTree(int value[], int n, char k[])
{
	Build(value, n, k);
}

void HuffmanTree::Build(int value[], int n, char k[])
{
	List = new hfmnode[n];
	ListLength = n;
	for (int i = 0; i<n; i++)
	{
		List[i].weight = value[i];
		List[i].ch = k[i];
		List[i].left = NULL;
		List[i].right = NULL;
	}
	hfmnode *newnode;
	hfmnode *newleft;
	hfmnode *newright;
	makeList();
	while (ListLength != 1)
	{
		newnode = new hfmnode;
		newnode->weight = List[ListLength - 1].weight + List[ListLength - 2].weight;
		newnode->ch = '#';

		newleft = new hfmnode;
		newleft->weight = List[ListLength - 1].weight;
		newleft->left = List[ListLength - 1].left;
		newleft->right = List[ListLength - 1].right;
		newleft->ch = List[ListLength - 1].ch;

		newright = new hfmnode;
		newright->weight = List[ListLength - 2].weight;
		newright->left = List[ListLength - 2].left;
		newright->right = List[ListLength - 2].right;
		newright->ch = List[ListLength - 2].ch;

		newnode->left = newleft;
		newnode->right = newright;

		ListLength--;
		List[ListLength - 1] = *newnode;
		newleft->parent = &List[ListLength - 1];
		newright->parent = &List[ListLength - 1];
		makeList();
	}
	root = &List[0];
	root->parent = NULL;
	root->weight = n;
}

HuffmanTree::~HuffmanTree() {}

void HuffmanTree::makeList()
{
	hfmnode x;
	for (int i = 1; i<ListLength; i++)
	{
		for (int j = ListLength - 1; j >= i; j--)
		{
			if (List[j]>List[j - 1])
			{
				x = List[j];
				List[j] = List[j - 1];
				List[j - 1] = x;
			}
		}
	}
}

void HuffmanTree::printList()
{
	for (int i = 0; i<ListLength; i++)
	{
		cout << List[i].weight << " ";
	}
	cout << endl;
}

void HuffmanTree::preorder(hfmnode *p)
{
	if (p != NULL)
	{
		cout << p->weight << " ";
		preorder(p->left);
		preorder(p->right);
	}
}

string HuffmanTree::encode(char x, hfmnode *p, string coding)
{
	if (p != NULL)
	{
		if (x == p->ch)return coding;
		return encode(x, p->left, coding + "0") + encode(x, p->right, coding + "1");
	}
	return "";
}

void HuffmanTree::Huffmancode(hfmnode *p)
{
	if (p != NULL)
	{
		if (p->ch != '#')cout << p->ch << ": " << encode(p->ch) << endl;
		Huffmancode(p->left);
		Huffmancode(p->right);
	}
}

void HuffmanTree::Encoding()
{
	char p;
	string code = "";
	fstream fio;
	fio.open("ToBeTran.txt", ios::in | ios::binary);
	if (!fio)cerr << "can't open file!" << endl;
	while (fio.get(p))
	{
		code += encode(p);
	}
	fio.close();
	fio.open("CodeFile.txt", ios::out | ios::binary);
	if (!fio)cerr << "can't open file!" << endl;
	fio << code;
	fio.close();
}

char HuffmanTree::decode(string x, hfmnode *p)
{
	if (p != NULL)
	{
		if (x == encode(p->ch))return p->ch;
		if (decode(x, p->left) != '#')return decode(x, p->left);
		if (decode(x, p->right) != '#')return decode(x, p->right);
	}
	return '#';
}

void HuffmanTree::Decoding()
{
	string code = "";
	string text = "";
	char c, p;
	fstream fio;
	fio.open("CodeFile.txt", ios::in | ios::binary);
	if (!fio)cerr << "can't open file!" << endl;
	while (fio.get(p))
	{
		code += p;
		c = decode(code);
		if (c != '#')
		{
			text += c;
			code = "";
		}
	}
	fio.close();
	fio.open("TextFile.txt", ios::out | ios::binary);
	if (!fio)cerr << "can't open file!" << endl;
	fio << text;
	fio.close();
}

int HuffmanTree::Height(hfmnode *p)
{
	if (p == NULL)return 0;
	int i = Height(p->left);
	int j = Height(p->right);
	return(i<j) ? j + 1 : i + 1;
}

void HuffmanTree::writefile(string text)
{
	fstream fio;
	fio.open("ToBeTran.txt", ios::out | ios::binary);
	if (!fio)cerr << "can't open file!" << endl;
	fio << text;
	fio.close();
}

void HuffmanTree::Print()
{
	char p;
	fstream fio;
	fio.open("CodeFile.txt", ios::in | ios::binary);
	if (!fio)cerr << "can't open file!" << endl;
	for (int i = 0; fio.get(p); i++)
	{
		cout << p;
		if (i % 50 == 0 && i != 0)cout << endl;
	}
	fio.close();
}

void HuffmanTree::printing(hfmnode *p, int h, fstream &fio)
{
	if (p != NULL)
	{
		printing(p->right, h + 1, fio);
		for (int i = 0; i<h; i++) { cout << "    "; fio << "    "; }
		cout << p->weight << endl; fio << p->weight << endl;
		printing(p->left, h + 1, fio);
	}
}

void HuffmanTree::save()
{
	fstream fio;
	fio.open("hfmTree.txt", ios::out);
	if (!fio)cerr << "can't open file!" << endl;
	fio << root->weight << endl;
	ordersave(root, fio);
	fio.close();
}

void HuffmanTree::ordersave(hfmnode *p, fstream &fio)
{
	if (p != NULL)
	{
		if (p->ch != '#')fio << p->ch << " " << p->weight << endl;
		ordersave(p->left, fio);
		ordersave(p->right, fio);
	}
}

void HuffmanTree::loadtree()
{
	int n;
	char *c;
	int *value;
	fstream fio;
	fio.open("hfmTree.txt", ios::in);
	if (!fio)cerr << "can't open file!" << endl;
	fio >> n;
	c = new char[n];
	value = new int[n];
	for (int i = 0; i<n; i++)
	{
		fio >> c[i] >> value[i];
	}
	Build(value, n, c);
	fio.close();
}

void HuffmanTree::load()
{
	loadtree();
	coding = "";
	hfmnode *newnode;
	hfmnode *newleft;
	hfmnode *newright;
	makeList();
	while (ListLength != 1)
	{
		newnode = new hfmnode;
		newnode->weight = List[ListLength - 1].weight + List[ListLength - 2].weight;
		newnode->ch = '#';

		newleft = new hfmnode;
		newleft->weight = List[ListLength - 1].weight;
		newleft->left = List[ListLength - 1].left;
		newleft->right = List[ListLength - 1].right;
		newleft->ch = List[ListLength - 1].ch;

		newright = new hfmnode;
		newright->weight = List[ListLength - 2].weight;
		newright->left = List[ListLength - 2].left;
		newright->right = List[ListLength - 2].right;
		newright->ch = List[ListLength - 2].ch;

		newnode->left = newleft;
		newnode->right = newright;

		ListLength--;
		List[ListLength - 1] = *newnode;
		newleft->parent = &List[ListLength - 1];
		newright->parent = &List[ListLength - 1];
		makeList();
	}
	root = &List[0];
	root->parent = NULL;
}
