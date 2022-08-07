# leetcode

<!-- TOC -->

- [leetcode](#leetcode)
  - [零、仓库构成 😀](#零仓库构成-)
  - [一、知识详解 😄](#一知识详解-)
  - [二、知识点总结和对应题目 😋](#二知识点总结和对应题目-)
    - [1. 数组 🔢](#1-数组-)
      - [简单模拟](#简单模拟)
      - [贪心](#贪心)
      - [滑动窗口](#滑动窗口)
      - [双指针](#双指针)
      - [随机数组](#随机数组)
    - [2. 字符串 🔡](#2-字符串-)
      - [字符串自身变化](#字符串自身变化)
      - [字符串与数字](#字符串与数字)
      - [字符串匹配](#字符串匹配)
        - [KMP 算法](#kmp-算法)
      - [贪心](#贪心-1)
    - [3. 链表 ➡️](#3-链表-️)
      - [链表元素相加](#链表元素相加)
      - [链表元素重构](#链表元素重构)
      - [删除链表节点](#删除链表节点)
      - [反转链表 ⬅️](#反转链表-️)
    - [4. 栈 ⤵️](#4-栈-️)
      - [栈模拟](#栈模拟)
      - [单调栈](#单调栈)
    - [5. 队列 ⏩](#5-队列-)
    - [6. 查找 🔎](#6-查找-)
      - [二分查找](#二分查找)
        - [二分查找模板](#二分查找模板)
        - [一些二分查找的应用](#一些二分查找的应用)
    - [7. 位运算 0️⃣1️⃣](#7-位运算-0️⃣1️⃣)
      - [运算符和优先级](#运算符和优先级)
      - [常用操作](#常用操作)
      - [常用函数和常数](#常用函数和常数)
    - [8. 树 🌴](#8-树-)
      - [最近公共祖先](#最近公共祖先)
      - [二叉树](#二叉树)
    - [9. 图 🧩](#9-图-)
      - [欧拉通路](#欧拉通路)
    - [10. 动态规划 🔒](#10-动态规划-)
      - [一维序列](#一维序列)
    - [10. 排序](#10-排序)
      - [堆排序](#堆排序)

<!-- /TOC -->

## 零、仓库构成 😀

这个仓库是一个学习记录式的仓库，每周更新。

- leetBook：按照 leetbook 刷题的题目记录和总结。目前在做！
  - [leetBook 初级算法](leetBook/leetbook_basicAlgorithm.md)【一刷：2022.03.27-05.30】
  - [leetBook 中级算法](leetBook/leetbook_mediumAlgorithm.md) 【一刷：2022.05.30-08.07】
  - [leetBook 高级算法](leetBook/leetbook_hardAlgorithm.md) 【一刷：2022.08.07 - 】
- Knowledge：基础知识或专题性的记录，主要是 C++。
  - [C++相关知识](Knowledge/cplusplus.md)
- totalProblem(CN)：所有刷过的题目的源码。
- weeklyCompetiton：周赛记录，不过近期没有在做了。
- codingInterview：未来会记录一些实际问过的题和剑指 offer 的题目。

## 一、知识详解 😄

- [C++相关知识](Knowledge/cplusplus.md)

## 二、知识点总结和对应题目 😋

### 1. 数组 🔢

【15. 三数之和】


#### 简单模拟

#### 贪心

#### 滑动窗口

- 【3.无重复字符的最长子串】
- 【209.长度最小的子数组】
- 【1004.最大连续 1 的个数 III】
- 【2104（周赛）】

模板：

```c++
int findSubset(vector<int> &nums, int k)
{
    int n = nums.size();
    int start = 0, end = 0; //双指针，当前遍历的区间为[start, end]
    int sums = 0;           //用于统计子数组/子区间是否有效，根据题目可能会改成求和/计数
    int res = 0;            //保存最大的满足题目要求的 子数组/子串 长度
    while (end < n)
    {
        //当右边的指针没有搜索到 数组/字符串 的结尾
        sums += nums[end]; //增加当前右边指针的数字/字符的求和/计数
        while (a)
        {
            // a表示区间[start,end]不符合题目给定条件
            //需要一直移动左指针，直至找到一个符合题意的区间
            sums -= nums[start]; //移动左指针前需要从nums中减少start位置字符的求和/计数
            start++;             //移动左指针，注意不能跟上面一行代码写反
        }
        //找到了一个符合题意要求的子数组/子串
        res = max(res, end - start + 1); //更新维护的最小/最大的结果
        end++;                           //移动右指针，探索新的区间
    }
    return res;
}
```

#### 双指针

【19.删除链表的倒数第 N 个结点】
【26.删除有序数组中的重复项】
【88.合并两个有序数组】
【125.验证回文串】
【234.回文链表】
【344.反转字符串】

#### 随机数组

【384.打乱数组】洗牌算法典型题。

### 2. 字符串 🔡

#### 字符串自身变化

【344.反转字符串】

#### 字符串与数字

【7.整数翻转】
【8.字符串转换整数 (atoi)】

弹出和推入数字的写法：弹出：`num=x%10;x/=10;` 推入：`result=result*10+num;`

#### 字符串匹配

【38.外观数列】
【14.最长公共前缀】

##### KMP 算法

【28.实现 strStr()】

#### 贪心

【2182.构造限制重复的字符串】

### 3. 链表 ➡️

#### 链表元素相加

【2.两数相加】

#### 链表元素重构

【328.奇偶链表】

#### 删除链表节点

【19.删除链表的倒数第 N 个结点】 双指针

#### 反转链表 ⬅️

- 24: 两两反转链表
- 92： 给定一个区间，反转区间内的链表
- 206： 反转整个链表
- 2074 （周赛）：区间值递增，反转偶数区间的链表（若最后一个区间少于递增数量那么如果是偶数个同样反转，否则不反转）

### 4. 栈 ⤵️

#### 栈模拟

【2211（周赛）】

#### 单调栈

### 5. 队列 ⏩

### 6. 查找 🔎

#### 二分查找

> 可以使用 upper_bound 和 lower_bound 来实现一些查找
> 这两个函数是使用二分查找实现的
> upper_bound：在指定范围内查找大于目标值的第一个元素，不存在则返回 end
> lower_bound：在指定区域内查找大于等于目标值的第一个元素，不存在则返回 end

##### 二分查找模板

- 34：在排序数组中查找元素的第一个和最后一个位置
- 35：给定递增序列，插入目标元素，保持数组递增
- 2080：设计数据结构，多次查找区间内目标值出现次数

##### 一些二分查找的应用

- 【2187.完成旅途的最少时间】（\#281)
- 【162. 寻找峰值】 可以用二分查找优化。

### 7. 位运算 0️⃣1️⃣

- 【136.只出现一次的数字】
- 【371. 两整数之和】
- 

#### 运算符和优先级

优先级从高到低：

1. 按位取反（`~`）
2. 左移（`<<`）、有符号右移（`>>`）
3. 按位与（`&`）、按位或（`|`）、按位异或（`^`）

#### 常用操作

位运算的累加：`ans = ans | X;`，通常 ans 起始为 0， X 是计算后的结果。
位运算的遍历：右移 n`n = n >> 1;`并不断取 n 的最后一个数位`n & 1`。
检查最后一位是否为 1：`n & 1`。
检查第 i 位是否为 1： `n & (1 << i)`。
改变某一位所在的位置（通常是 1）：`1 << X`，把 1 移动到从右到左的第 X 位。
把 n 的二进制最低位的 1 变为 0： `n & (n - 1)`。

#### 常用函数和常数

统计 1 的个数：`__builtin_popcount(x ^ y)`
翻转数组时使用的掩码：

```c++
   const uint32_t M1 = 0x55555555;  // 01010101010101010101010101010101
   const uint32_t M2 = 0x33333333;  // 00110011001100110011001100110011
   const uint32_t M4 = 0x0f0f0f0f;  // 00001111000011110000111100001111
   const uint32_t M8 = 0x00ff00ff;  // 00000000111111110000000011111111
   const uint32_t M16 = 0x0000ffff; // 00000000000000001111111111111111
```

### 8. 树 🌴

#### 最近公共祖先

- 【2096（周赛）】
  - 基本思想：先找 root 到两个节点的路径，然后删除 root 到最近公共祖先的路径，一边全部替换成 U，然后两段路径拼接。
  - 小技巧：维护了树的父节点哈希表

#### 二叉树

- 【2196. 根据描述创建二叉树（周赛）】

### 9. 图 🧩

#### 欧拉通路

- 【332.重新安排行程】
- 【753.破解保险箱】
- 【2097（周赛）】 深度优先搜索（Hierholzer 算法）求解欧拉通路

### 10. 动态规划 🔒

#### 一维序列

- 【70.爬楼梯】
- 【121.买卖股票的最佳时机】
- 【53.最大子序和】
- 【198.打家劫舍】
- 【300.最长递增子序列】
- 【2110（周赛）】
- 【2111（周赛）】

0-1 背包问题：

- 【2212（周赛）】

### 10. 排序

#### 堆排序

【347.前-k-个高频元素】 时间复杂度的要求，需要用小顶堆或者快速排序。
