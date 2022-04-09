# leetcode😊

- [leetcode😊](#leetcode)
  - [一、知识详解 😄](#一知识详解-)
  - [二、知识点与对应题目 😋](#二知识点与对应题目-)
    - [1. 数组 🔢](#1-数组-)
      - [简单模拟](#简单模拟)
      - [贪心](#贪心)
      - [滑动窗口](#滑动窗口)
      - [双指针](#双指针)
    - [2. 字符串 🔡](#2-字符串-)
      - [贪心](#贪心-1)
    - [3. 链表 ➡️](#3-链表-️)
      - [反转链表 ⬅️](#反转链表-️)
    - [4. 栈](#4-栈)
      - [栈模拟](#栈模拟)
      - [单调栈](#单调栈)
    - [5. 队列](#5-队列)
    - [6. 查找 🔎](#6-查找-)
      - [二分查找](#二分查找)
        - [一些二分查找的应用](#一些二分查找的应用)
    - [7. 位运算 0️⃣1️⃣](#7-位运算-0️⃣1️⃣)
    - [8. 树 🌴](#8-树-)
      - [最近公共祖先](#最近公共祖先)
      - [二叉树](#二叉树)
    - [9. 图 🧩](#9-图-)
      - [欧拉通路](#欧拉通路)
    - [10. 动态规划 🔒](#10-动态规划-)
      - [一维序列](#一维序列)
  - [三、周赛记录 😉](#三周赛记录-)
    - [2021.11.14 周赛](#20211114-周赛)
    - [2021.11.21 周赛](#20211121-周赛)
    - [2021.11.28 周赛](#20211128-周赛)
    - [2021.12.05 周赛](#20211205-周赛)
    - [2021.12.12 周赛](#20211212-周赛)
    - [2021.12.19 周赛](#20211219-周赛)
    - [2022.02.06 周赛](#20220206-周赛)
    - [2022.02.21 周赛（#281）](#20220221-周赛281)
    - [2022.02.27 周赛（#282）](#20220227-周赛282)
    - [2022.03.06 周赛（#283）](#20220306-周赛283)
    - [2022.03.20 周赛（#285）](#20220320-周赛285)
  - [四、LeetBook 学习记录](#四leetbook-学习记录)
    - [初级算法](#初级算法)
      - [2022.03.27-04.03 数组](#20220327-0403-数组)
      - [2022.04.04-04.10 字符串](#20220404-0410-字符串)

## 一、知识详解 😄

- [C++相关知识](Knowledge/cplusplus.md)

## 二、知识点与对应题目 😋

### 1. 数组 🔢

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

【26.删除有序数组中的重复项】

### 2. 字符串 🔡

#### 贪心

【2182.构造限制重复的字符串】

### 3. 链表 ➡️

#### 反转链表 ⬅️

- 24: 两两反转链表
- 92： 给定一个区间，反转区间内的链表
- 206： 反转整个链表
- 2074 （周赛）：区间值递增，反转偶数区间的链表（若最后一个区间少于递增数量那么如果是偶数个同样反转，否则不反转）

### 4. 栈

#### 栈模拟

【2211（周赛）】

#### 单调栈

### 5. 队列

### 6. 查找 🔎

#### 二分查找

> 可以使用 upper_bound 和 lower_bound 来实现一些查找
> 这两个函数是使用二分查找实现的
> upper_bound：在指定范围内查找大于目标值的第一个元素，不存在则返回 end
> lower_bound：在指定区域内查找大于等于目标值的第一个元素，不存在则返回 end

- 34：在排序数组中查找元素的第一个和最后一个位置
- 35：给定递增序列，插入目标元素，保持数组递增
- 2080：设计数据结构，多次查找区间内目标值出现次数

##### 一些二分查找的应用

- 【2187.完成旅途的最少时间】（\#281)

### 7. 位运算 0️⃣1️⃣

- 【136.只出现一次的数字】 1 个出现一次的数字，其他都是出现两次的数字，0 再异或全部数字即可。

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

- 【300.最长递增子序列】
- 【2110（周赛）】
- 【2111（周赛）】

0-1 背包问题：

- 【2212（周赛）】

---

## 三、周赛记录 😉

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

### 2022.02.06 周赛

- 【2164.对奇偶下标分别排序】AC
- 【2165.重排数字的最小值】AC
- 【2166.设计位集】 直接模拟就好了，不知道我在想什么省空间的操作结果搞得没时间了。

### 2022.02.21 周赛（#281）

- 【2180.统计各位数字之和为偶数的整数个数】 AC，简单模拟，我花了一些时间把时间复杂度降到了 O(1)，其实不需要的，可以直接用位运算或者 while 循环来模拟。
- 【2181.合并零之间的节点】AC，链表删除，将 0 之间的值加到左边的 0，然后不断删除非 0 的值，直到下一个 0。
- 【2182.构造限制重复的字符串】贪心，每次选取最大的字符，直到最大的字符用完。但是注意结尾会有两种情况，一种是遍历到最小的字符时不够了，另一种时遍历到某一个字符时最小的字符已经不够了，这两种情况就直接跳出循环即可。（题解里还有用双指针和优先队列的做法，也可以参考)。

### 2022.02.27 周赛（#282）

- 【2185.统计包含给定前缀的字符串】AC，找字符串前缀，满足条件的就累加，我还写了一个条件，直接调用 C++的函数即可 word.find(pref)在找到前缀时为 0，否则为 1。Python 也可以用 word.startswith(pref)来判断。
- 【2186.使两字符串互为字母异位词的最少步骤数】AC，字母异位词（字母相同但是顺序不一定相同的字符串），求两者转换的步骤数。我比赛时使用了一个两个`map<char,int>`，既耗空间也不快。之后看了讨论区，可以直接用一个 26 个元素的 int 数组，然后遍历两次（第一次累加，第二次累减）就可以求出两个词的每个字符的差值，然后去绝对值求和即可，非常优雅的想法了。
- 【2187.完成旅途的最少时间】二分搜索。周赛时根本没想到用二分搜索，一直在纠结怎么贪心才能实现最少的时间，看了讨论区之后才知道思路完全走偏了。其实做的时候隐约的感觉到有一个最大的时间上界，但是根本没想到可以直接用二分来求解。枯坐将近一小时也没什么好的思路(...)，实际上根本不需要考虑贪心，因为二分搜索时，只需要计算在 mid 时间内，把所有小于 mid 时间的车跑满就可以了，这时候考虑的视角并不是给定旅途数求最小时间，而是在给定时间下求旅程数，这个视角一转化马上就豁然开朗了。

### 2022.03.06 周赛（#283）

- 【2194. Excel 表中某个范围内的单元格】AC，从上到下从左到右遍历 Excel 表的单元格，没什么好说的。
- 【2195. 向数组中追加 K 个整数】比赛的时候看到提交数和通过数的比值非常高。但这个题的思路其实并不复杂，还是因为有太多边界条件了。这题是说给定数组，从小到大追加不在数组中的 K 个数，然后求追加数的和。这里我没写出来主要是因为两个原因：1. 没有考虑一个重要的情况，给定数组排序后会出现相同元素的情况，周赛时完全没考虑这一点，主要还是没有自己看题目中到底有没有说元素互不相同。2. 最开始考虑的解法是按顺序一个一个添加，但是，即使考虑情况 1，也仍然会 TLE，因为时间复杂度会更高。其实周赛快结束时我已经想到了可以逆向解决，减去原有的元素数值，但是那时候又在卡第三题，也没时间重新写了。之后重新借鉴了一下官方题解，完善了我自己的版本。还有一个要注意的点：求和时是需要用`static_cast<long long>`进行隐式类型转换。

- 【2196. 根据描述创建二叉树】这个题其实也不难，但是周赛时思路不太清晰，也花了一些时间。描述是一个三元组（父节点，子节点，左右关系），根据三元组构建树，然后返回根节点。主要的问题在于怎么样返回根节点，我这里的解法是通过用一个 unordered_map 保存整个树的信息，然后再用一个 set 来保存所有子节点的 id，最后排除出不是子节点的 id 来确定 root。评论区还有一些方法是保存入度值来确定，入度值为 0 的节点就是根节点。

### 2022.03.20 周赛（#285）

- 【2210. 统计数组中峰和谷的数量】AC，确定波峰和波谷，需要注意一些情况下，长期的平台期会导致无法立即确定波峰波谷，所以这里用两个 flag 来记录潜在的波峰和波谷。
- 【2211. 统计道路上的碰撞次数】左右静止的三种状态的车，LR 碰撞算 2 次，SL 是 1 次，RS 是 1 次，计算总的碰撞次数。这里周赛时用了一种很慢的办法，不断用正则表达式找到三个规则并替换成 SS，直到整个字符串都是 S，果然 TLE 了。看了一下讨论区，普遍有两种算法，一种是栈模拟，我借鉴了思想写出了自己的一版，不过时间复杂度和空间复杂度都是中后段；另一种是观察出来的讨巧的方法。
  首先第一个算法是通过模拟一个栈，通过一次遍历计算出所有的碰撞次数。当前的车为`directions[i]`，这个栈维护着当前可能和`directions[i]`发生碰撞的车。那么分情况讨论，1）如果当前的车为 R，那么直接入栈，2）如果当前的车为 L，那么可以再分情况讨论，如果栈顶为 R，那么会发生 RL 碰撞；如果为 S，那么会发生 RS 碰撞。但是这里需要注意一个情况，如果栈中从栈顶开始有多个 R 的话，那么除了第一次是 RL，之后的都会是 RS 碰撞，所以用一个 flag 来记录。在碰撞后，我们都加一个 S 作为当前的栈顶的元素。3）如果当前的车为 S，那么同样分栈顶为 S 和 R 来讨论。如果是 R 才会发生碰撞，这里同样考虑栈中多个连续 R 的情况，但是每次的碰撞数都加 1 即可。

## 四、LeetBook 学习记录

2022.03.27 开始做 LeetBook，每周争取一个章节。

### 初级算法

#### 2022.03.27-04.03 数组

这周完成了 Leetbook 初级算法中的数组专题，每天晚上睡前做一题，因为很多都是简单题，所以花不了多长的时间，感觉还不错。感觉在慢慢养成每天做力扣的习惯。

【26.删除有序数组中的重复项】双指针解法。用一个缓慢的指针来逐渐地替换重复的元素，如果当前元素不满足的话，就按照指针的位置进行替换。

【122.买卖股票的最佳时机 II】这是我能想到的吗？看了题解的贪心解法，大为震惊，太巧妙了。实际上不需要求真正的买入卖出的过程，只需要把这个题简化成寻找多个不相交区间的最大值即可。贪心的方法用了分治的思想，我要求不相交区间的最大值，那么最小的单元就是只有一个元素的区间，我只要每次都获取单个区间的最大贡献就好。（因为区间数最多的情况就是一个元素分一个区间。）贪心的思想就是每个区间都取到最大的贡献，这样整个区间的最大值也就会是最大的贡献了。

【189. 轮转数组】给定 k，确定向右轮转 k 步的数组。1）哈希法：构建一个新的数组，这个数组的第`(i + k) % nums.size()`个元素就是原始数组的第 i 个元素，类似哈希的算法。比如原始第 0 个会向右走`k % nums.size()`步，比较优雅巧妙的做法了。 2）翻转法：首先`k %= nums.size()`，因为如果 k 大于数组长度，会轮转到原始的数组，所以把余数赋给 k 就行。然后一个经典的两只手翻转法，先整个翻转数组，然后翻转前 k-1 个，再翻转 k 到最后一个。这样就能够得到一个轮转 k 次的数组了。

【217. 存在重复元素】简单题，两种方法：1)使用一个`unordered_set<int>`来记录出现过的数字，注意这里要用 unordered_set 才会快，如果用 set 会自动排序，时间消耗会大。2）先把数组排序，如果当前数等于下一个数，那么就返回有重复。

【136.只出现一次的数字】数组里只有 1 个出现一次的数字，其他都是出现两次的数字，找到出现一次的数字。位运算，用 0 异或全部数字即可。

【350.两个数组的交集-II】计算两个数组的交集。用一个哈希表`unordered_map<int, int>`来记录第一个数组的数字出现的次数，然后再遍历第二个数组，如果是在哈希表中的数字的话，那么就加入最终的结果数组中，并更新哈希表。

【66.加一】一个元素只有 0-9 的数组，表示一个大数，将这个数加一。我的思路是用一个整数记录进位，然后直接模拟加法，但是其实这样时间会花的更多。官方题解给的思路是，从后往前找第一个不是 9 的数，然后把它的下一位加 1，然后把从当前的数到数组末尾的数全部置 0。这个方法确实会比较适合这个题目，因为它每次都只是加 1，完全可以不整个模拟一遍加法。

【283.移动零】把数组的所有的 0 放到数组最后。我的解法：遍历一边数组，一遍找 0 一边删除，然后统计 0 的个数，并最后添加相应数量的 0，这个解法不够快。看了一下题解，自己写了一个双指针的方法：初始两个指针都指向第一个元素，然后左边的指针始终指向排好顺序的数组的下一个数（可能是 0，也可能不是）。右指针用来探索当前的数是不是 0。如果不是 0，那么就和左指针指向的元素交换（如果左指针指向的不是 0，那么这个情况只能说明目前还没有 0 找到，那么右指针肯定是和左指针指向的是同一个数，所以不影响），然后再右移左右指针，直到右指针找到最后一个数。

【1.两数之和】给定 target，求满足和为 target 的两个数的 index。用一个`unordered_map<int, int>`记录剩余数值和对应的已取元素的 index。然后遍历一次数组，如果当前 index 的数取了之后，剩余部分能够在哈希表的键中中找到，那么就知道两个数分别是当前 index 和哈希表相应的 index 值。如果找不到的话，就把当前的 index 的数值作为键，index 作为值，存储进哈希表中。这个解法比暴力显然是更好的，时空复杂度都是 O(N)。

【36.有效的数独】判断给定数组的有效性。这里主要是用三个二维数组来记录 1-9 数字的个数，行和列都很简单，但每个九宫格的编号需要用`(rowidx / 3) * 3 + colidx / 3`来计算，注意要乘 3，相当于`colidx / 3`是一个偏移量，`(rowidx / 3)` 每次要包含偏移量导致多出来的 3 个位置，这样才能准确编码出九宫格。基本的思路就是遍历二维数组，然后每次先判断一下三个数组的对应的数是不是已经有了（值为 1），如果有直接返回 false，如果没有就更新数组。

【48.旋转图像】顺时针旋转 90 度的二维方阵。这里我想到可以直接翻转两次得到答案：第一次是类似矩阵的转置，斜 45 度反转，第二次是上下 180 度反转，可以用 C++中的 reverse 函数做到，不过我如果不用 reverse 函数，直接写一个上下翻转的话，就会快一些。这里需要注意一下矩阵转置和上下翻转都只用遍历一部分元素，而不是全部，不然会得到和原来的矩阵一样的矩阵。

#### 2022.04.04-04.10 字符串

【344.反转字符串】原地返回字符串。力扣评论笑死了：“做完这道题我又有自信了。”总之就是非常简单的一道题，但也能实在说到双指针的解法，一个前一个后，然后用一个 tmp 字符来进行交换操作。

【7.整数翻转】（目前仅有一个比较丑的版本，周末再优化）

【387.字符串中的第一个唯一字符】用 unordered_map 做一个哈希，用`<char,int>`的存储空间会比`<int,int>`的存储空间更高，因为 char 只占 1 个字节而 int 占 4 个字节。 官方还提供了其他的解法， 比如用哈希表存储单独出现的位置，如果重复的话就置为-1，然后再次遍历找最小的不为-1 的值。还有一个解法是用队列。不过三种解法时间空间复杂度都一样。

【242.有效的字母异位词】异位词就是字符出现次数都相等的词。我刚开始考虑用`unordered_map<char, int>`来存储出现的字符和对应的次数，这样的话，就需要判断键是否存在在 map 中，所以会更耗时间。题解是用一个`vector<int> ch(26,0)`就能够达到同样的功能，这个确实是多写就能自然而然想到的点。

【125.验证回文串】有混着非数字和字母的字符串，判断除开其余字符是否是回文串。这里我考虑的是双指针的想法，一个从右到左，一个从左到右，如果是非字母数字的字符就再向中间走，如果都是数字字母就比较，不相等就返回 false，直到`i>=j`，最后返回 true。题解的想法也不错，先把所有的字母数字挑出来，同时用`tolower()`函数转化为小写字母，然后 reverse 字符串，再比较两个字符串是否相等。但是确实没有双指针法快。

【8.字符串转换整数 (atoi)】这个题很费劲，各种意义上，而且借由这个题能 get 很多知识点，而且最后力扣给的官方题解竟然使用 DFA，枉学自动机好多年。就记录一下用普通的算法需要考虑的点：

1. 起始是字符，直接返回 0。
2. 起始是空格，删除空格：我使用了 while 循环，实际上只需要用`str = str.trim();`函数就可以删除所有空格。
3. 当前起始是数字或加号/当前起始是符号：记录负号，如果是符号就考虑符号后的（我是连续用了 idx 记录，到最后再用一个`string tmp = s.substr(idx, s.length() - idx);`来保存 idx 到结尾的字符串。
4. 删除数字后续的字符串：找到往下的第一个非数字的 idx，然后再用`substr(pos,length)`来截取。
5. 调用`strToNum`函数获取字符对应的数字。

`long strToNum(string s, long num)`的逻辑：

1. num 参数是 1 或-1，表示正数或负数。
2. 如果 s 的长度大于 10，正数返回 INT_MAX，负数返回 INT_MIN。这是为了避免超级长的字符串不进行后续的运算，导致数字太大，但是，注意并不是 10 位数以下都是不越界的。
3. s 长度小于等于 10 时，正常计算对应的数，这里要用 long 来存储，并乘 num 来表示正负数。
4. 判断当前计算的结果是否小于 INT_MIN 或大于 INT_MAX，如果是就修改为边界值，如果不是就用 int()强制类型转换，并最后返回。


【28.实现 strStr()】BF/KMP 算法。

【38.外观数列】

【14.最长公共前缀】
