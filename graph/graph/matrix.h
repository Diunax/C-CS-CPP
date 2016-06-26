#include<iostream>
#include<queue>
using namespace std;
#define maxWeight 999999999
class matrix {
public:
	matrix(int n);
	void insert();
	void display();
	int getNum(char v);
	void BFS(int locate);
	void DFS(int locate);
	void DFS(int locate, bool *visited);
	int getFirstNeightbor(int locate);
	int getNextNeightbor(int v, int w);
private:
	char *Data;
	int **Edge;
	int size;
};
//取顶点对应的顶点号
int matrix::getNum(char v)
{
	for (int i = 0; i < size; i++)
	{
		if (Data[i] == v)	return i;
	}
	return -1;
}
//初始化邻接矩阵
matrix::matrix(int n)
{
	size = n;
	Edge = new int *[n];
	Data = new char[n];
	for (int i = 0; i < n; i++)
	{
		Edge[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Edge[i][j] = (i == j) ? 0 : maxWeight;
		}
	}
}
//建立矩阵
void matrix::insert()
{
	int row, col, weight;
	cout << "请依次输入从0到" << size - 1 << "的全部顶点的内容" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> Data[i];
	}
	cout << "请依次输入两个顶点的顶点编号和之间的权值,输入-1退出"<<endl;
	while (cin>>row)
	{
		if (row == -1)	break;
		cin>> col >> weight;
		Edge[row][col] = weight;
		Edge[col][row] = weight;
	}
}
//输出矩阵
void matrix::display()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Edge[i][j] == maxWeight)	cout << "- ";
			else  cout << Edge[i][j]<<" ";
		}
		cout << endl;
	}
}
//广度优先，输入顶点编号
void matrix::BFS(int locate)
{
	int num = size;
	queue<int> q;
	bool *visited = new bool[num];
	for (int i = 0; i < num; i++)
	{
		visited[i] = false;
	}
	cout << Data[locate] << " ";
	visited[locate] = true;
	q.push(locate);
	while (!q.empty())
	{
		locate = q.back();
		q.pop();
		int w = getFirstNeightbor(locate);
		while (w != -1)
		{
			if (visited[w] == false)
			{
				cout << Data[w] << " ";
				visited[w] = true;
				q.push(w);
			}
			w = getNextNeightbor(locate,w);
		}
	}
}
void matrix::DFS(int locate)
{
	bool *visited = new bool[size];
	for (int i = 0; i < size; i++)
	{
		visited[i] = false;
	}
	DFS(locate, visited);
	delete[] visited;
}
void matrix::DFS(int locate, bool *visited)
{
	cout << Data[locate] << " ";
	visited[locate] = true;
	int w = getFirstNeightbor(locate);
	while (w != -1)
	{
		if (visited[w] == false)	DFS(w, visited);
		else  w = getNextNeightbor(locate, w);
	}
}
//获取顶点编号最近的邻接顶点的编号
int matrix::getFirstNeightbor(int locate)
{
	if (locate != -1)
	{
		for (int col = 0; col < size; col++)
		{
			if (Edge[locate][col]>0&&Edge[locate][col]<maxWeight)
				return col;
		}
	}
	else return -1;
}
//获取顶点编号v的邻接顶点w的下一个顶点邻接顶点编号
int matrix::getNextNeightbor(int v, int w)
{
	if (v != -1 && w != -1)
	{
		for (int col = w + 1; col < size; col++)
		{
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)	return col;
		}
	}
	return -1;
}