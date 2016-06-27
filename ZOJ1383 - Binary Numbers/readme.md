## ZOJ1383 -  Binary Numbers

## 题目

Given a positive integer n, print out the positions of all 1's in its binary representation. The position of the least significant bit is 0.

**Example**
The positions of 1's in the binary representation of 13 are 0, 2, 3.

**Task**
Write a program which for each data set:

reads a positive integer n,
computes the positions of 1's in the binary representation of n,
writes the result.

**Input**
The first line of the input contains exactly one positive integer d equal to the number of data sets, 1 <= d <= 10. The data sets follow.
Each data set consists of exactly one line containing exactly one integer n, 1 <= n <= 10^6.

**Output**
The output should consists of exactly d lines, one line for each data set.
Line i, 1 <= i <= d, should contain increasing sequence of integers separated by single spaces - the positions of 1's in the binary representation of the i-th input number.

**Sample Input**

1
13

**Sample Output**

0 2 3

## 知识点

`移位运算符`



## 分析

很简单的一道题，输入n个数，对于每个数，输出其二进制表示的所有1的位置。

比如13，二进制表示为0000 1101。所以输出结果为0 2 3。

这里主要是想介绍下`C++`的左移右移指令。

``` c++
void outputOne(int val) {
	bool first = true;
	for (int i = 0; i < 32; i++)
	{
		if (val & (1 << i) && first) {
			cout << i;
			first = false;
		}
		else if (val & (1 << i) && !first) {
			cout << " " << i;
		}
	}
	cout << endl;
}
```

每次循环对1左右`i`位，然后与`value`相与。就可以分别判断`value`的二进制表示中第`i`位是否为1。



---

