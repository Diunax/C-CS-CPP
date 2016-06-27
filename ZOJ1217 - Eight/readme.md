## ZOJ1217 - Eight

## 题目

The 15-puzzle has been around for over 100 years; even if you don't know it by that name, you've seen it. It is constructed with 15 sliding tiles, each with a number from 1 to 15 on it, and all packed into a 4 by 4 frame with one tile missing. Let's call the missing tile 'x'; the object of the puzzle is to arrange the tiles so that they are ordered as: 

``` c
 1  2  3  4 
 5  6  7  8 
 9 10 11 12 
13 14 15  x
```

where the only legal operation is to exchange 'x' with one of the tiles with which it shares an edge. As an example, the following sequence of moves solves a slightly scrambled puzzle:

``` c
 1  2  3  4     1  2  3  4     1  2  3  4     1  2  3  4 
 5  6  7  8     5  6  7  8     5  6  7  8     5  6  7  8 
 9  x 10 12     9 10  x 12     9 10 11 12     9 10 11 12 
 13 14 11 15    13 14 11 15    13 14  x 15    13 14 15  x 
            r->            d->             r->
```

The letters in the previous row indicate which neighbor of the 'x' tile is swapped with the 'x' tile at each step; legal values are 'r','l','u' and 'd', for right, left, up, and down, respectively.

Not all puzzles can be solved; in 1870, a man named Sam Loyd was famous for distributing an unsolvable version of the puzzle, and frustrating many people. In fact, all you have to do to make a regular puzzle into an unsolvable one is to swap two tiles (not counting the missing 'x' tile, of course).

In this problem, you will write a program for solving the less well-known 8-puzzle, composed of tiles on a three by three arrangement.

**Input**

You will receive, several descriptions of configuration of the 8 puzzle. One description is just a list of the tiles in their initial positions, with the rows listed from top to bottom, and the tiles listed from left to right within a row, where the tiles are represented by numbers 1 to 8, plus 'x'. For example, this puzzle

```c
 1  2  3 
 x  4  6 
 7  5  8
```

is described by this list:

1 2 3 x 4 6 7 5 8

**Output**

You will print to standard output either the word ``unsolvable'', if the puzzle has no solution, or a string consisting entirely of the letters 'r', 'l', 'u' and 'd' that describes a series of moves that produce a solution. The string should include no spaces and start at the beginning of the line. Do not print a blank line between cases.

**Sample Input**

 2  3  4  1  5  x  7  6  8

**Sample Output**

ullddrurdllurdruldr

## 知识点

`四分树`，`散列`，`BFS`

## 分析

这道题其实就是九宫格拼图的问题，给出一个拼图问能不能拼出原样。

一般我们都会想到从给出的这个图开始去做深度优先遍历或者广度优先遍历直至找出原样。

由于题目已经给定了这是一个3*3的方格，所以我们要考虑避免多次重复计算，所以应该想到这道题应该逆推过来。也就是从原图出发，建立一棵树记录全部可能情况。然后对于每次输入，只需要找找看是否存在这个图，如果有，依次输出变化关系即可。

从输入的图找出原图不难，但是要输出他们的关系则有一定的技巧了。此题我采用的是用`map`来保存图与图的映射关系，用广度优先遍历来建图。其余的参考代码吧。



---

