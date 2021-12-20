# leetcode😊

- [leetcode😊](#leetcode)
  - [1.知识详解😄](#1知识详解)
  - [2.知识点与对应题目 😋](#2知识点与对应题目-)
    - [数组](#数组)
      - [滑动窗口](#滑动窗口)
    - [链表](#链表)
      - [反转链表](#反转链表)
    - [查找](#查找)
      - [二分查找](#二分查找)
    - [位运算](#位运算)
    - [树](#树)
    - [图](#图)
      - [欧拉通路](#欧拉通路)
    - [动态规划](#动态规划)
      - [一维序列](#一维序列)
  - [3.周赛 😉](#3周赛-)
    - [2021.11.14 周赛](#20211114-周赛)
    - [2021.11.21 周赛](#20211121-周赛)
    - [2021.11.28 周赛](#20211128-周赛)
    - [2021.12.05 周赛](#20211205-周赛)
    - [2021.12.12 周赛](#20211212-周赛)
    - [2021.12.19 周赛](#20211219-周赛)

## 1.知识详解😄

- [C++相关知识](Knowledge/cplusplus.md)

## 2.知识点与对应题目 😋

### 数组

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

### 链表

#### 反转链表

- 24: 两两反转链表
- 92： 给定一个区间，反转区间内的链表
- 206： 反转整个链表
- 2074 （周赛）：区间值递增，反转偶数区间的链表（若最后一个区间少于递增数量那么如果是偶数个同样反转，否则不反转）

### 查找

#### 二分查找

> 可以使用 upper_bound 和 lower_bound 来实现一些查找
> 这两个函数是使用二分查找实现的
> upper_bound：在指定范围内查找大于目标值的第一个元素，不存在则返回 end
> lower_bound：在指定区域内查找大于等于目标值的第一个元素，不存在则返回 end

- 34：在排序数组中查找元素的第一个和最后一个位置
- 35：给定递增序列，插入目标元素，保持数组递增
- 2080：设计数据结构，多次查找区间内目标值出现次数

### 位运算

- 【136.只出现一次的数字】 1 个出现一次的数字，其他都是出现两次的数字，0 再异或全部数字即可。

### 树

1. 最近公共祖先

- 【2096（周赛）】
  - 基本思想：先找 root 到两个节点的路径，然后删除 root 到最近公共祖先的路径，一边全部替换成 U，然后两段路径拼接。
  - 小技巧：维护了树的父节点哈希表

### 图

#### 欧拉通路

- 【332.重新安排行程】
- 【753.破解保险箱】
- 【2097（周赛）】 深度优先搜索（Hierholzer 算法）求解欧拉通路

### 动态规划

#### 一维序列

- 【300.最长递增子序列】
- 【2110（周赛）】
- 【2111（周赛）】

## 3.周赛 😉

### 2021.11.14 周赛

- 【2073.买票需要的时间】
- 【2074.反转偶数长度组的节点】

### 2021.11.21 周赛

- 【2078.两栋颜色不同且距离最远的房子】
- 【2079.给植物浇水】
- 【2080.区间内查询数字】

### 2021.11.28 周赛

- 【2089.找出数组排序后的目标下标】
- 【2090.半径为 k 的子数组平均值 (前缀和)】
- 【2091.从数组中移除最大值和最小值】

### 2021.12.05 周赛

- 【2094.找出三位偶数】
- 【2095.删除链表中间节点】
- 【2096.从二叉树一个节点到另一个节点每一步的方向】
- 【2097.合法重新排列数对】使用有向的欧拉通路（332，753）

### 2021.12.12 周赛

- 【2103.环和杆】用三位二进制数维护三种颜色的环的出现（用 string 即可）
- 【2104.子数组范围和】滑动窗口，不断维护子数组的最大最小值
- 【2105.给植物浇水 II】注意一下边界条件

### 2021.12.19 周赛

- 【2108.找出数组中的第一个回文字符串】回文字符，简单题
- 【2109.向字符串添加空格】不 TLE 的方法：用双指针并把 string 看成 vector 使用 push_back 添加每个字符
- 【2110.股票平滑下跌阶段的数目】找最长的等差为 1 的序列并存储，然后直接数学计算；这题也可以用动态规划做
- 【2111.使数组 K 递增的最少操作次数】