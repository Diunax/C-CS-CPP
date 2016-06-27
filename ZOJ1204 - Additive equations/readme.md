## ZOJ1204 - Additive equations

We all understand that an integer set is a collection of distinct integers. Now the question is: given an integer set, can you find all its addtive equations? To explain what an *additive equation* is, let's look at the following examples: 
1+2=3 is an additive equation of the set {1,2,3}, since all the numbers that are summed up in the left-hand-side of the equation, namely 1 and 2, belong to the same set as their sum 3 does. We consider 1+2=3 and 2+1=3 the same equation, and will always output the numbers on the left-hand-side of the equation in ascending order. Therefore in this example, it is claimed that the set {1,2,3} has an unique additive equation 1+2=3.
It is not guaranteed that any integer set has its only additive equation. For example, the set {1,2,5} has no addtive equation and the set {1,2,3,5,6} has more than one additive equations such as 1+2=3, 1+2+3=6, etc. When the number of integers in a set gets large, it will eventually become impossible to find all the additive equations from the top of our minds -- unless you are John von Neumann maybe. So we need you to program the computer to solve this problem.

**Input**
The input data consists of several test cases. 
The first line of the input will contain an integer N, which is the number of test cases. 
Each test case will first contain an integer M (1<=M<=30), which is the number of integers in the set, and then is followed by M distinct positive integers in the same line.

**Output**
For each test case, you are supposed to output all the additive equations of the set. These equations will be sorted according to their lengths first( i.e, the number of integer being summed), and then the equations with the same length will be sorted according to the numbers from left to right, just like the sample output shows. When there is no such equation, simply output "Can't find any equations." in a line. Print a blank line after each test case.

**Sample Input**

``` c
3
3 1 2 3
3 1 2 5
6 1 2 3 5 4 6
```

**Output for the Sample Input**

```c
1+2=3

Can't find any equations.

1+2=3
1+3=4
1+4=5
1+5=6
2+3=5
2+4=6
1+2+3=6
```



## 知识点

`DFS`

## 分析

这道题和前面一道交换卡片的题有点类似。也是使用深度优先遍历的方法解决。但这道题要注意记录路径，并且深度优先遍历实施前一般都要进行下排序，这道题目也是。纯`DFS`题目，不做细讲了。

---

