## ZOJ1203 - Swordfish



  We all remember that in the movie Swordfish, Gabriel broke into the World Bank Investors Group in West Los Angeles, to rob $9.5 billion. And he needed Stanley, the best hacker in the world, to help him break into the password protecting the bank system. Stanley's lovely daughter Holly was seized by Gabriel, so he had to work for him. But at the last moment, Stanley made some little trick in his hacker mission: he injected a trojan horse in the bank system, so the money would jump from one account to another account every 60 seconds, and would continue jumping in the next 10 years. Only Stanley knew when and where to get the money. If Gabriel killed Stanley, he would never get a single dollar. Stanley wanted Gabriel to release all these hostages and he would help him to find the money back.
  You who has watched the movie know that Gabriel at last got the money by threatening to hang Ginger to death. Why not Gabriel go get the money himself? Because these money keep jumping, and these accounts are scattered in different cities. In order to gather up these money Gabriel would need to build money transfering tunnels to connect all these cities. Surely it will be really expensive to construct such a transfering tunnel, so Gabriel wants to find out the minimal total length of the tunnel required to connect all these cites. Now he asks you to write a computer program to find out the minimal length. Since Gabriel will get caught at the end of it anyway, so you can go ahead and write the program without feeling guilty about helping a criminal.

**Input:**
The input contains several test cases. Each test case begins with a line contains only one integer N (0 <= N <=100), which indicates the number of cities you have to connect. The next N lines each contains two real numbers X and Y(-10000 <= X,Y <= 10000), which are the citie's Cartesian coordinates (to make the problem simple, we can assume that we live in a flat world). The input is terminated by a case with N=0 and you must not print any output for this case.

**Output:**
You need to help Gabriel calculate the minimal length of tunnel needed to connect all these cites. You can saftly assume that such a tunnel can be built directly from one city to another. For each of the input cases, the output shall consist of two lines: the first line contains "Case #n:", where n is the case number (starting from 1); and the next line contains "The minimal distance is: d", where d is the minimal distance, rounded to 2 decimal places. Output a blank line between two test cases.

**Sample Input:**

```c
5
0 0
0 1
1 1
1 0
0.5 0.5
0
```

**Sample Output:**

```c
Case #1:
The minimal distance is: 2.83
```



## 知识点

 `并查集`，`优先队列`，`Kruskal`，`最小生成树`

## 分析

这道题明显是求最小生成树。给出多个城市的位置，要求找出连接所有点的最小距离。求最小生成树可以使用`Kruskal`或者`Prim`算法。这里只讨论`Kruskal`算法。

> **Kruskal算法**是一种用来查找最小生成树的算法，由Joseph Kruskal在1956年发表。用来解决同样问题的还有Prim算法和Boruvka算法等。三种算法都是贪婪算法的应用。和Boruvka算法不同的地方是，Kruskal算法在图中存在相同权值的边时也有效。

关于`Kruskal`的步骤，如下:

>1. 新建图G，G中拥有原图中相同的节点，但没有边
>2. 将原图中所有的边按权值从小到大排序
>3. 从权值最小的边开始，如果这条边连接的两个节点于图G中不在同一个连通分量中，则添加这条边到图G中
>4. 重复3，直至图G中所有的节点都在同一个连通分量中

我们可以使用`优先队列`和`并查集`来进行优化。取权值最小边，可以使用优先队列。判断这个边的两个节点在不在同一个连通分量可以使用并查集。

这里说下并查集和优先队列：

- 并查集

  并查集是一般会设置两个方法，即`Find`和`Union`。`Union`方法是将两个自己合并成一个集合。一般我们会选取集合中的一个元素作为根，其他节点作为他的孩纸。`Union`可以这样写：

  ``` c++
  void Union(int i, int j) {
  	parent[i] = j;
  }
  ```

  例如在该题中，我们每次取权值最小的边，在该边入列前，我们要先判断该边加入后会不会形成环路。因此我们可以判断下这条边的起始点和终点在不在一个集合里面。比如对于1-2-3-4-1这样连通的点，我们顺序找下去，可以建立出parent[1] = 2, parent[2] = 3, parent[3] = 4这个关系。接着对于4-1，我们先使用`Find`方法(前面的也有这个过程)，`Find`方法可以用下面的代码表示：

  ```c++
  int Find(int i) {
      while(parent[i] >= 0) i = parent[i];
  	return i;
  }
  ```

  如果我们`Find(4)`会得到-1，（初始值全部设为-1），所以直接返回4，`Find(1)`会得到`2`，接着找`Find(2)`得到3，接着找`Find(3)`得到4，接着找`Find(4)`得到-1，那么返回4。两个数相同代表他们处在同一个集合。可以看到1，2，3都是4的孩子。

  并查集的`Find`和`Union`方法可以做进一步的优化如下：

  ```c++
  int CollapsingFind(int i) {
    //采用坍塌规则缩短
    for(int r = i; parent[r] >= 0; r = parent[r]);
    while(i != r) {
    	int s = parent[i];
      parent[i] = r;
      i = s;
    }
    return r;
  }

  void WeightedUnion(int i, int j) {
    // 基于权重规则构造以i和j为根的集合的并
    int temp = parent[i] + parent[j];
    if(parent[j] < parent[i]) {
    	parent[i] = j;
      parent[j] = temp;
    }
    else {
      parent[j] = i;
      parent[i] = temp;
    }
  }

  ```

- 优先队列

  优先队列的头文件，定义，以及使用方法

  ```c++
  #include <queue>											// 头文件
  priority_queue<EdgeNode> PQ;								// 定义
  bool operator < (const EdgeNode &a, const EdgeNode &b) {	// 运算符重载
  	if (a.cost > b.cost) {
  		return true;
  	}
  	else {
  		return false;
  	}
  }
  ```



---

