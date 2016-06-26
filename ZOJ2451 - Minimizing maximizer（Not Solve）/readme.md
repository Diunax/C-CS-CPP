## ZOJ2451 - Minimizing maximizer

## 题目

The company Chris Ltd. is preparing a new sorting hardware called Maximizer. Maximizer has N inputs numbered from 1 to N. Each input represents one integer. Maximizer has one output which represents the maximum value present on Maximizer's inputs.

Maximizer is implemented as a pipeline of sorters *Sorter*(i[1], j[1]), ..., *Sorter*(i[k], j[k]). Each sorter has N inputs and N outputs. *Sorter*(i, j) sorts values on inputs i, i+1, ..., j in non-decreasing order and lets the other inputs pass through unchanged. The N-th output of the last sorter is the output of the Maximizer.

An intern (a former ACM contestant) observed that some sorters could be excluded from the pipeline and Maximizer would still produce the correct result. What is the length of the shortest subsequence of the given sequence of sorters in the pipeline still producing correct results for all possible combinations of input values?

**Task**

Write a program that:

- reads the description of a Maximizer, i.e. the initial sequence of sorters in the pipeline,
- computes the length of the shortest subsequence of the initial sequence of sorters still producing correct results for all possible input data,
- writes the result.

### Input Specification

The input consists of several test cases.
For each case, the first line contains two integers N and M (2 <= N <= 50 000, 1 <= M <= 500 000) separated by a single space. Integer N is the number of inputs and integer M is the number of sorters in the pipeline. The initial sequence of sorters is described in the next M lines. The k-th of these lines contains the parameters of the k-th sorter: two integers i[k] and j[k] (1 <= i[k] < j[k] <= N) separated by a single space.

### Output Specification

For each test case, print in one line the length of the shortest subsequence of the initial sequence of sorters still producing correct results for all possible data.

### Sample Input

```
40 6
20 30
1 10
10 20
20 30
15 25
30 40
```

### Output for the Sample Input

```
4
```



## 知识点

`线段树`, `点线段树`



## 分析

​	todo



---

