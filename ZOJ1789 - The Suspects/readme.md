## ZOJ1789 - The Suspects

## 题目

Severe acute respiratory syndrome (SARS), an atypical pneumonia of unknown aetiology, was recognized as a global threat in mid-March 2003. To minimize transmission to others, the best strategy is to separate the suspects from others.In the Not-Spreading-Your-Sickness University (NSYSU), there are many student groups. Students in the same group intercommunicate with each other frequently, and a student may join several groups. To prevent the possible transmissions of SARS, the NSYSU collects the member lists of all student groups, and makes the following rule in their standard operation procedure (SOP).Once a member in a group is a suspect, all members in the group are suspects.However, they find that it is not easy to identify all the suspects when a student is recognized as a suspect. Your job is to write a program which finds all the suspects.
**Input**The input contains several cases. Each test case begins with two integers n and m in a line, where n is the number of students, and m is the number of groups. You may assume that 0 < n <= 30000 and 0 <= m <= 500. Every student is numbered by a unique integer between 0 and n-1, and initially student 0 is recognized as a suspect in all the cases. This line is followed by m member lists of the groups, one line per group. Each line begins with an integer k by itself representing the number of members in the group. Following the number of members, there are k integers representing the students in this group. All the integers in a line are separated by at least one space.A case with n = 0 and m = 0 indicates the end of the input, and need not be processed.
**Output**

For each case, output the number of suspects in one line.


**Sample Input**

100 4
2 1 2
5 10 13 11 12 14
2 0 1
2 99 2
200 2
1 5
5 1 2 3 4 5
1 0
0 0
**Sample Output**

4
1
1





## 知识点

`并查集`，`DFS`



## 分析

以题目给的第一个例子为例，有100个学生，4个学习小组。这4个学习小组分别是：

- 2人小组，学生1，2
- 5人小组，学生10，13，11，12，14
- 2人小组，学生0，1
- 2人小组，学生99，2

学生0有传染病嫌疑。问这些学生中有多少人有可能感染传染病。



这道题可以有多种做法，比较简单的做法就是我现在写的代码。也就是按顺序遍历下来，找到带传染病的学生0，然后把该组的所有学生都置为有嫌疑，每个新增的学生都继续递归调用搜索。最后递归的次数也就是传染病的可能人数。

在判断该学生是否已经被有传染病嫌疑时，可以使用数组标记位判断，亦可以使用并查集。



---
