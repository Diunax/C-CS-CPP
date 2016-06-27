## ZOJ1610 - Count the Colors

## 题目

Painting some colored segments on a line, some previously painted segments may be covered by some the subsequent ones.Your task is counting the segments of different colors you can see at last.
**Input**
The first line of each data set contains exactly one integer n, 1 <= n <= 8000, equal to the number of colored segments.Each of the following n lines consists of exactly 3 nonnegative integers separated by single spaces:

x1 x2 c

x1 and x2 indicate the left endpoint and right endpoint of the segment, c indicates the color of the segment.All the numbers are in the range [0, 8000], and they are all integers.Input may contain several data set, process to the end of file.
**Output**

Each line of the output should contain a color index that can be seen from the top, following the count of the segments of this color, they should be printed according to the color index.If some color can't be seen, you shouldn't print it.Print a blank line after every dataset.
**Sample Input**

5
0 4 4
0 3 1
3 4 2
0 2 2
0 2 3
4
0 1 1
3 4 1
1 3 2
1 3 1
6
0 1 0
1 2 1
2 3 1
1 2 0
2 3 0
1 2 1
**Sample Output**

1 1
2 1
3 11 10 2
1 1



## 知识点

`线段树`



## 分析

此题需要明确的一点是不能使用数组来记录颜色，数组效率很低，应该使用`线段树`来解决这道题。

在做关于`线段树`的题目的时候，要注意`线段树`的另一种变形`点线段树`。不过这道题还是用`线段树`来解决的。

解答此题有两个步骤：

- 建立完整线段树

  我们可以给初始线段树每个节点都赋予`color = -1`的属性。表示这是一颗没有颜色的节点。

- 成段更新染色

  在输入各个线段的颜色后，我们要对原线段树进行更新。可以使用`color = -2`来表示这是一颗混了各种颜色的树，和`-1`以及纯颜色区分开来。同时要注意的是，在处理一个树节点，比如题目给的第一个例子，我们经过第一步操作后(0, 4)的`color`值为4。接着是线段(0, 3)，`color`为1。此时做法是把(0, 4)的`color`设为-2，把其孩子(0, 2)和(2, 4)的`color`设为其父节点(0, 4)的`color`即4。接着猜开始使用(0, 3)的颜色来处理(0, 2)和(2, 4)。往下处理方式相同。

之后我们前序遍历这颗树就可以了。

如果此题使用数组，很明显使用数组将非常简单，但是效率十分低，我们每次染色都需要操作一大堆数。并且最后要遍历整个数组。如果数组范围较大，比如此题是8000，此题可能无法AC。而使用线段树，我们使用了`color`这个标记，为-1时表示未染色，用-2表示混杂颜色，我们在前序遍历进行到一个线段时发现`color`不为-2时，就不需要再继续搜索下去了。



---

