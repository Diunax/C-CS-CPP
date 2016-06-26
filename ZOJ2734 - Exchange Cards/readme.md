## ZOJ2734 - Exchange Cards

## 题目

As a basketball fan, Mike is also fond of collecting basketball player cards. But as a student, he can not always get the money to buy new cards, so sometimes he will exchange with his friends for cards he likes. Of course, different cards have different value, and Mike must use cards he owns to get the new one. For example, to get a card of value 10$, he can use two 5$ cards or three 3$ cards plus one 1$ card, depending on the kinds of cards he have and the number of each kind of card. And Sometimes he will involve unfortunately in a bad condition that he has not got the exact value of the card he is looking for (fans always exchange cards for equivalent value).

Here comes the problem, given the card value he plans to get and the cards he has, Mike wants to fix how many ways he can get it. So it's you task to write a program to figure it out.

**Input**

The problem consists of multiple test cases, terminated by **EOF**. There's a blank line between two inputs.

The first line of each test case gives **n**, the value of the card Mike plans to get and **m**, the number of different kinds of cards Mike has. **n** will be an integer number between 1 and 1000. **m** will be an integer number between 1 and 10.

The next **m** lines give the information of different kinds of cards Mike have. Each line contains two integers, **val** and **num**, representing the value of this kind of card, and the number of this kind of card Mike have.

**Note:** different kinds of cards will have different value, each **val** and **num** will be an integer greater than zero.

**Output**

For each test case, output in one line the number of different ways Mike could exchange for the card he wants. You can be sure that the output will fall into an integer value.

Output a blank line between two test cases.

**Sample Input**

```
5 2
2 1
3 1

10 5
10 2
7 2
5 3
2 2
1 5
```

**Sample Output**

```
1

7
```

## 知识点

`DFS`



## 分析

这道题目的意思是，以第二个例子为例，迈克想换去价值为10的卡片，他有5种卡片，他有价值为10的卡片2张，价值为7的卡片2张，价值为5的卡片3张，价值为2的卡片2张，价值为1的卡片5张。问他可以有多少种组合方式去换去价值为10的这张卡片。

其实意思就是找出可以有多少种加法组合得到要求的数字。

说到这里我们可以很明显想到这道题用深度遍历`DFS`来解决。分别考虑一次加法，二次加法，三次加法等等。

需要注意的是一定要按降序来进行深度遍历。



---

