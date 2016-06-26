## ZOJ2770 - Burn the Linked Camp

## 题目

It is well known that, in the period of The Three Empires, Liu Bei, the emperor of the Shu Empire, was defeated by Lu Xun, a general of the Wu Empire. The defeat was due to Liu Bei's wrong decision that he divided his large troops into a number of camps, each of which had a group of armies, and located them in a line. This was the so-called "Linked Camps".

Let's go back to that time. Lu Xun had sent many scouts to obtain the information about his enemy. From his scouts, he knew that Liu Bei had divided his troops into n camps, all of which located in a line, labeled by 1..n from left to right. The ith camp had a maximum capacity of Ci soldiers. Furthermore, by observing the activities Liu Bei's troops had been doing those days, Lu Xun could estimate the least total number of soldiers that were lived in from the ith to the jth camp. Finally, Lu Xun must estimate at least how many soldiers did Liu Bei had, so that he could decide how many troops he should send to burn Liu Bei's Linked Camps.

**Input:**

There are multiple test cases! On the first line of each test case, there are two integers n (0<n<=1,000) and m (0<=m<=10,000). On the second line, there are n integers C1��Cn. Then m lines follow, each line has three integers i, j, k (0<i<=j<=n, 0<=k<2^31), meaning that the total number of soldiers from the ith camp to the jth camp is at least k.

**Output:**

For each test case, output one integer in a single line: the least number of all soldiers in Liu Bei's army from Lu Xun's observation. However, Lu Xun's estimations given in the input data may be very unprecise. If his estimations cannot be true, output "Bad Estimations" in a single line instead.

**Sample Input:**

```
3 2
1000 2000 1000
1 2 1100
2 3 1300
3 1
100 200 300
2 3 600
```

**Sample Output:**

```
1300
Bad Estimations
```



## 知识点

`差分约束系统`，`Bellman-ford`, `SPFA`



## 分析

这道题的意思是刘备的军队分为了n个阵营，每个阵营的最大士兵容量为`Ci`。陆逊通过观察发现得出了几组数据，就是从阵营`from`到阵营`to`之间的士兵最少数量。陆逊这时候必须估计刘备有多少士兵，如果无法估计，输出`Bad Estimations`。



此题应该使用`差分约束系统`来解决。

>求解差分约束系统，可以转化成图论的单源最短路径问题。观察xj-xi<=bk，会发现它类似最短路中的三角不等式d[v] <=d[u]+w[u,v]，即d[v]-d[u]<=w[u,v]。因此，以每个变数xi为结点，对于约束条件xj-xi<=bk，连接一条边（i,j），边权为bk。再增加一个原点（s,s）与所有定点相连，边权均为0。对这个图以s为原点运行Bellman-ford算法（或SPFA算法），最终{d[i]}即为一组可行解。
>

解决这道题要首先找出差分方程组，对这道题来说，我们可以建立以下约束方程

根据军营数和每个军营的最大士兵容量`Ci`可以得到:

- ( i - 1 ) - ( i ) <=0  // 前i-1个军营的士兵与前i个军营的士兵之差必然小于等于0
- ( i ) - ( i - 1 ) <= temp  // 前i个军营的士兵数量减去前i-1个军营的士兵数量必然小于等于`Ci`

根据第`from`到`to`个军营之间最少有`number`个士兵可以得到:

- ( to ) - ( from - 1 ) >= number

我们需要统一差分方程，上述可以转化为:

- ( from - 1 ) - ( to ) <= -number

保存上述的全部差分方程，接着我们要计算的是刘备至少有多少士兵。即 

- ( n ) - ( 0 ) >= ? 即 ( 0 ) - ( n ) <= -?

如果从数学角度，其实就是我们有这么多个不等式，问能不能求出( 0 ) - ( n )的最大值？

从程序角度，我们已经找到了多个类似从A点到B点的权值大小这样的关系。要求的是起始点到终点的最小权值即最短路径。但会出现权值为负数的情况，对于带负数权值的求最短路径的问题，可以使用`Belleman-ford`算法。



`Bellman-ford`算法有三个步骤

- 初始化图
- 重复对每一条边进行松弛操作
- 检查负权环



我们由此题可以建立(u, v, w)的图（数组表示）如下：

一共有n个点，所以我们要进行n次循坏，每次循坏都对这8个关系进行遍历。初始d[n] = 0，表示第n个军营到第n个军营最小权值为0。可见我们要求的是( 0 ) - ( n )，即 d[0] 。最后我们还要求反。

| u    | v    | w     | 第一次          | 第二次          | 第三次  |
| ---- | ---- | ----- | ------------ | ------------ | ---- |
| 1    | 0    | 0     |              | d[0] = -1300 |      |
| 0    | 1    | 1000  |              |              |      |
| 2    | 1    | 0     |              |              |      |
| 1    | 2    | 2000  |              |              |      |
| 3    | 2    | 0     | d[2] = 0     |              |      |
| 2    | 3    | 1000  |              |              |      |
| 2    | 0    | -1100 | d[0] = -1100 |              |      |
| 3    | 1    | -1300 | d[1] = -1300 |              |      |

如上，最后得到d[0] = -1300，所以结果为1300。

第i次循环表示走i次到达n点的最小权值。



---

