## ZOJ2193 - Window Pains

## 题目

Boudreaux likes to multitask, especially when it comes to using his computer. Never satisfied with just running one application at a time, he usually runs nine applications, each in its own window. Due to limited screen real estate, he overlaps these windows and brings whatever window he currently needs to work with to the foreground. If his screen were a 4 x 4 grid of squares, each of Boudreaux's windows would be represented by the following 2 x 2 windows:

1 1  . .                                                    . 2 2 .                                                  .  . 3 3

1 1 .  .                                                    . 2 2 .                                                  .  . 3 3

.  .  .  .                                                    .  .  .  .                                                  .  .  .  .

.  .  .  .						      .  .  .  .						  .  .  .  . 



.  .  .  .                                                    .  .  .  .                                                   .  .  .  .

4 4 .  .                                                   .  5 5  .                                                  .  6  6  .

4 4 .  .                                                   .  5 5  .                                                  .  6  6  .

.  .  .  .						     .   .   .  .						   .   .   .   . 



.   .   .  .                                                 .   .   .   .                                                .   .   .   .

.   .   .  .                                                 .   .   .   .                                                .   .   .   .

7 7  .   .                                                .  8  8   .                                                .   .  9   9

7 7  .   .						    .   8  8   .						  .   .  9   9



When Boudreaux brings a window to the foreground, all of its squares come to the top, overlapping any squares it shares with other windows. For example, if window 1 *and then* window 2 were brought to the foreground, the resulting representation would be:

1 2 2 . 

1 2 2  . 

.  .  .  . 

.  .  .  .

If window 4 were then brought to the foreground:

1 2 2 . 

4 4 2  . 

4 4  .  . 

.  .  .  .

. . . and so on . . .

Unfortunately, Boudreaux's computer is very unreliable and crashes often. He could easily tell if a crash occurred by looking at the windows and seeing a graphical representation that should not occur if windows were being brought to the foreground correctly. And this is where you come in . . .

**Input**

Input to this problem will consist of a (non-empty) series of up to 100 data sets. Each data set will be formatted according to the following description, and there will be **no blank lines** separating data sets.

A single data set has 3 components:

1. *Start line* - A single line:`         START      `
2. *Screen Shot* - Four lines that represent the current graphical representation of the windows on Boudreaux's screen. Each position in this 4 x 4 matrix will represent the current piece of window showing in each square. To make input easier, the list of numbers on each line will be delimited by a single space.
3. *End line* - A single line:`         END      `

After the last data set, there will be a single line:

```
   ENDOFINPUT

```

Note that each piece of visible window will appear only in screen areas where the window could appear when brought to the front. For instance, a 1 can only appear in the top left quadrant.

**Output**

For each data set, there will be exactly one line of output. If there exists a sequence of bringing windows to the foreground that would result in the graphical representation of the windows on Boudreaux's screen, the output will be a single line with the statement:

```
   THESE WINDOWS ARE CLEAN

```

Otherwise, the output will be a single line with the statement:

```
   THESE WINDOWS ARE BROKEN

```

**Sample Input**

START
1 2 3 3
4 5 6 6
7 8 9 9
7 8 9 9
END
START
1 1 3 3
4 1 3 3
7 7 9 9
7 7 9 9
END
ENDOFINPUT

**Sample Output**

THESE WINDOWS ARE CLEAN
THESE WINDOWS ARE BROKEN

## 知识点

`拓扑排序`, `AOV`

## 分析

如果知道`拓扑排序`的话应该很容易知道这道题要用`拓扑排序`来解决。

不看题目看例子也可以看懂题目的意思了~

> 在[图论](https://zh.wikipedia.org/wiki/%E5%9B%BE%E8%AE%BA)中，由一个[有向无环图](https://zh.wikipedia.org/wiki/%E6%9C%89%E5%90%91%E6%97%A0%E7%8E%AF%E5%9B%BE)的顶点组成的序列，当且仅当满足下列条件时，称为该[图](https://zh.wikipedia.org/wiki/%E5%9B%BE)的一个**拓扑排序**（英语：Topological sorting）。
>
> 1. 每个顶点出现且只出现一次；
> 2. 若A在序列中排在B的前面，则在图中不存在从B到A的[路径](https://zh.wikipedia.org/wiki/%E8%B7%AF%E5%BE%84_(%E5%9B%BE%E8%AE%BA))。
>
> 也可以定义为：拓扑排序是对有向无环图的顶点的一种排序，它使得如果存在一条从顶点A到顶点B的路径，那么在排序中B出现在A的后面[[1\]](https://zh.wikipedia.org/wiki/%E6%8B%93%E6%92%B2%E6%8E%92%E5%BA%8F#cite_note-book-1)。

进行`拓扑排序`，有以下步骤：

1. 输入AOV网络。令n为顶点个数。
2. 在AOV网络中选择一个入度为0的结点，并输出之。
3. 从图中删去该顶点，同时删去所有它发出的有向边。
4. 重复以上2，3步，直到下面的情况之一出现：
   - 全部顶点均已输出，拓扑有序序列形成，拓扑排序完成。
   - 图中还有未输出的顶点，但已没有入度为0的结点（说明网络中必定存在有向环）。

接下来来看下这道题。

进行`拓扑排序`第一步是建立邻接矩阵和他们的度数。我们要知道这个邻接矩阵表示的是什么和什么之间的关系。对于这道题，邻接矩阵是用来表示窗口i可以覆盖哪些窗口。比如对于此题的第一个例子，我们建立邻接矩阵如下图：

所以建立出来的邻接矩阵如下。`G[I][J]`为1时表示窗口I可以覆盖窗口J。

```c
G[10][10]
G[0]	0 0 0 0 0 0 0 0 0 0
G[1]	0 0 0 0 0 0 0 0 0 0
G[2]	0 1 0 0 0 0 0 0 0 0
G[3]	0 0 1 0 0 0 0 0 0 0
G[4]	0 1 0 0 0 0 0 0 0 0
G[5]	0 1 1 0 1 0 0 0 0 0
G[6]	0 0 1 1 0 1 0 0 0 0
G[7]	0 0 0 0 1 0 0 0 0 0
G[8]	0 0 0 0 1 1 0 1 0 0
G[9]	0 0 0 0 0 1 1 0 1 0
```

同时记录下indegree[9]表示窗口i的入度。

接着使用拓扑排序算法即可。



---

