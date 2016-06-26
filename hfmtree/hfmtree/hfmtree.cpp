// hfmtree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "hfmtree.h"
using namespace std;
int main()
{
	string text;
	bool BeingInit = 0, BeingEncode = 0;
	HuffmanTree *tree;
	char *c;
	int *value;
	int n;
	int select;
	while (true)
	{
		cout << "1.initialization" << endl;
		cout << "2.write text to file" << endl;
		cout << "3.Encoding" << endl;
		cout << "4.Decoding" << endl;
		cout << "5.Print CodeFile" << endl;
		cout << "6.TreePrinting" << endl;
		cout << "7.show The Huffman code" << endl;
		cout << "8.exit" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			int t; 
			cout << "1.build a new HuffmanTree" << endl;
			cout << "2.load from the file" << endl; 
			cin >> t;
			while (true)
			{
				if (t == 1)
				{
					cout << "输入字符个数：";
					cin >> n;
					c = new char[n];
					value = new int[n];
					for (int i = 0; i<n; i++)
					{
						cout << "第" << i + 1 << "个字符：";
						cin >> c[i];
						cout << "第" << i + 1 << "个权值：";
						cin >> value[i];
					}
					tree = new HuffmanTree(value, n, c);
					break;
				}
				if (t == 2)
				{
					tree = new HuffmanTree;
					break;
				}
			}
			cout << "initialization success!" << endl;
			BeingInit = 1;
			tree->save();
			break;
		case 2:cout << "input your text: "; cin >> text;
			tree->writefile(text);
			cout << "OK!" << endl;
			break;
		case 3:if (!BeingInit) { cout << "the tree is not exist" << endl; break; }
			   tree->Encoding();
			   cout << "succeed in encoding!" << endl;
			   BeingEncode = 1;
			   break;
		case 4:if (!BeingInit) { cout << "the tree is not exist" << endl; break; }
			   if (!BeingEncode) { cout << "the tree haven't been encode, you must encoding before!" << endl; break; }
			   tree->Decoding();
			   cout << "succeed in decoding!" << endl;
			   break;
		case 5:if (!BeingInit) { cout << "the tree is not exist" << endl; break; }
			   if (!BeingEncode) { cout << "the tree haven't been encode, you must encoding before!" << endl; break; }
			   tree->Print(); cout << endl; break;
		case 6:if (!BeingInit) { cout << "the tree is not exist" << endl; break; }
			   tree->printing();
			   break;
		case 7:tree->Huffmancode(); cout << endl; break;
		case 8:exit(0);
		default:break;
		}
	}
	system("pause");
}
