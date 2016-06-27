## ZOJ1002 - Fire Net

Suppose that we have a square city with straight streets. A map of a city is a square board with n rows and n columns, each representing a street or a piece of wall.

A blockhouse is a small castle that has four openings through which to shoot. The four openings are facing North, East, South, and West, respectively. There will be one machine gun shooting through each opening.

Here we assume that a bullet is so powerful that it can run across any distance and destroy a blockhouse on its way. On the other hand, a wall is so strongly built that can stop the bullets.

The goal is to place as *many* blockhouses in a city as possible so that no two can destroy each other. A configuration of blockhouses is **legal** provided that no two blockhouses are on the same horizontal row or vertical column in a map unless there is at least one wall separating them. In this problem we will consider small square cities (at most 4x4) that contain walls through which bullets cannot run through.

The following image shows five pictures of the same board. The first picture is the empty board, the second and third pictures show legal configurations, and the fourth and fifth pictures show illegal configurations. For this board, the maximum number of blockhouses in a legal configuration is 5; the second picture shows one way to do it, but there are several other ways.

Your task is to write a program that, given a description of a map, calculates the maximum number of blockhouses that can be placed in the city in a legal configuration.

The input file contains one or more map descriptions, followed by a line containing the number 0 that signals the end of the file. Each map description begins with a line containing a positive integer *n* that is the size of the city; *n* will be at most 4. The next *n* lines each describe one row of the map, with a '.' indicating an open space and an uppercase 'X' indicating a wall. There are no spaces in the input file.

For each test case, output one line containing the maximum number of blockhouses that can be placed in the city in a legal configuration.

**Sample input:**

```c
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0
```

**Sample output:**

```c
5
1
5
2
4
```



## 知识点

 `二分图`，`DFS`



## 分析

这道题的意思很明显，在一张4X4的地图中放置碉堡，碉堡不能同行或同列，除非中间有墙阻隔。问最多能放置多少个碉堡。

做这道题的时候还不了解`二分图`，所以用的`DFS`方法。此题最佳解法应是使用`二分图`。

关于`DFS`的做法这里不再多说，以后再改用`二分图`实现，这里简单说下`二分图`的做法。

以下面这个图为例子

``` c++
.X..
....
XX..
....
```

从左到右分别用1 2 3 ...表示，墙壁不编号也不打断编号。

横向可以得到多条边：

(1) (2 3) (4 5 6 7) (8 9) (10 11 12 13)

纵向可以得到多条边：

(1 4) (5) (2 6 8 12) (3 7 9 13) (10) (11)

然后我们可以将有横向和纵向有覆盖的边连接起来。接着就是找最大匹配的问题。