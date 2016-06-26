## ZOJ1942 - Frogger

## 题目

Freddy Frog is sitting on a stone in the middle of a lake. Suddenly he notices Fiona Frog who is sitting on another stone. He plans to visit her, but since the water is dirty and full of tourists' sunscreen, he wants to avoid swimming and instead reach her by jumping. 

Unfortunately Fiona's stone is out of his jump range. Therefore Freddy considers to use other stones as intermediate stops and reach her by a sequence of several small jumps. 

To execute a given sequence of jumps, a frog's jump range obviously must be at least as long as the longest jump occuring in the sequence. 
The frog distance (humans also call it minimax distance) between two stones therefore is defined as the minimum necessary jump range over all possible paths between the two stones.You are given the coordinates of Freddy's stone, Fiona's stone and all other stones in the lake. Your job is to compute the frog distance between Freddy's and Fiona's stone.
**Input**

The input will contain one or more test cases. The first line of each test case will contain the number of stones n (2 <= n <= 200). The next n lines each contain two integers xi, yi (0 <= xi, yi <= 1000) representing the coordinates of stone #i. Stone #1 is Freddy's stone, stone #2 is Fiona's stone, the other n-2 stones are unoccupied. There's a blank line following each test case. Input is terminated by a value of zero (0) for n.
**Output**

For each test case, print a line saying "Scenario #x" and a line saying "Frog Distance = y" where x is replaced by the test case number (they are numbered from 1) and y is replaced by the appropriate real number, printed to three decimals. Put a blank line after each test case, even after the last one.
**Sample Input**

2
0 0
3 4

3
17 4
19 4
18 5

0
**Sample Output**

Scenario #1
Frog Distance = 5.000

Scenario #2
Frog Distance = 1.414



## 知识点

`Floyd-Warshall`, ` 动态规划`



## 分析

先介绍下`Floyd-Warshall`算法：

> **Floyd-Warshall算法**（英语：Floyd-Warshall algorithm），中文亦称**弗洛伊德算法**，是解决任意两点间的最短路径的一种算法，可以正确处理有向图或负权（但不可存在负权回路)的最短路径问题，同时也被用于计算有向图的传递闭包。
>
> Floyd-Warshall算法的时间复杂度为O(N^{3})，空间复杂度为O(N^{2})。

`Floyd-Warshall`是全源最短路径算法，支持负权值，但是不允许出现负数环。该算法的原理是动态规划。我们使用动态规划思想进行分析。

设`D[i][j][k]`为从`i`到`j`的只以`(1...k)`集合中的节点为中间节点的最短路径的长度。

- 若最短路径经过点`k`，则`D[i][j][k] = D[i][k][k-1] + D[k][j][k-1]`;
- 若最短路径不经过点`k`，则`D[i][j][k] = D[i][j][k-1]`

因此`D[i][j][k] = min(D[i][k][k-1], D[i][k][k-1] + D[k][j][k-1])`。

需要注意的是在建立三个循环的过程要按`k->i->j`的次序，因为我们是在围绕经不经过`k`这个石头展开的，也就是说对于任意两个石头，我们判断他们是经过`k`这个石头路径更短还是不经过更短，如果更短，我们就用这个更短的路径来替代当前的路径，当把全部石头都遍历完，我们就得到了任意两点之间的最短路径。



---

