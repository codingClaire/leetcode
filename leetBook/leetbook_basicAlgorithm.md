# LeetBook 初级算法

2022.03.27 开始做 LeetBook 初级算法，每周争取一个章节。

<!-- TOC -->

- [LeetBook 初级算法](#leetbook-初级算法)
  - [2022.03.27-04.03 数组](#20220327-0403-数组)
    - [【26.删除有序数组中的重复项】](#26删除有序数组中的重复项)
    - [【122.买卖股票的最佳时机 II】](#122买卖股票的最佳时机-ii)
    - [【189. 轮转数组】](#189-轮转数组)
    - [【217. 存在重复元素】](#217-存在重复元素)
    - [【136.只出现一次的数字】](#136只出现一次的数字)
    - [【350.两个数组的交集-II】](#350两个数组的交集-ii)
    - [【66.加一】](#66加一)
    - [【283.移动零】](#283移动零)
    - [【1.两数之和】](#1两数之和)
    - [【36.有效的数独】](#36有效的数独)
    - [【48.旋转图像】](#48旋转图像)
  - [2022.04.04-04.10 字符串](#20220404-0410-字符串)
    - [【344.反转字符串】](#344反转字符串)
    - [【7.整数翻转】](#7整数翻转)
    - [【387.字符串中的第一个唯一字符】](#387字符串中的第一个唯一字符)
    - [【242.有效的字母异位词】](#242有效的字母异位词)
    - [【125.验证回文串】](#125验证回文串)
    - [【8.字符串转换整数 (atoi)】](#8字符串转换整数-atoi)
    - [【28.实现 strStr()】](#28实现-strstr)
    - [【38.外观数列】](#38外观数列)
    - [【14.最长公共前缀】](#14最长公共前缀)
  - [2022.04.11-04.17 链表](#20220411-0417-链表)
    - [【206.反转链表】](#206反转链表)
    - [【21.合并两个有序链表】](#21合并两个有序链表)
    - [【234.回文链表】](#234回文链表)
    - [【141.环状链表】](#141环状链表)
  - [2022.04.18-04.24 树](#20220418-0424-树)
    - [【104.二叉树的最大深度】](#104二叉树的最大深度)
    - [【98.验证二叉搜索树】](#98验证二叉搜索树)
    - [【101.对称二叉树】](#101对称二叉树)
    - [【102.二叉树的层序遍历】](#102二叉树的层序遍历)
    - [【104.将有序数组转换为二叉搜索树】](#104将有序数组转换为二叉搜索树)
  - [2022.04.25-05.01 排序和搜索](#20220425-0501-排序和搜索)
    - [【88.合并两个有序数组】](#88合并两个有序数组)
    - [【278.第一个错误的版本】](#278第一个错误的版本)
  - [2022.05.02-05.08 动态规划](#20220502-0508-动态规划)
    - [【70.爬楼梯】](#70爬楼梯)
    - [【121.买卖股票的最佳时机】](#121买卖股票的最佳时机)
    - [【53.最大子序和】](#53最大子序和)
    - [【198.打家劫舍】](#198打家劫舍)
  - [2022.05.09-05.15 设计问题](#20220509-0515-设计问题)
    - [【384.打乱数组】](#384打乱数组)
    - [【155.最小栈】](#155最小栈)
  - [2022.05.16-05.22 数学](#20220516-0522-数学)
    - [【412.Fizz Buzz】](#412fizz-buzz)
    - [【204.计数质数】](#204计数质数)
    - [【326.3 的幂】](#3263-的幂)
    - [【13.罗马数字转整数】](#13罗马数字转整数)
  - [2022.05.23-05.29 其他](#20220523-0529-其他)
    - [【191.位 1 的个数】](#191位-1-的个数)
    - [【461.汉明距离】](#461汉明距离)
    - [【190.颠倒二进制位】](#190颠倒二进制位)
    - [【118.杨辉三角】](#118杨辉三角)
    - [【20.有效的括号】](#20有效的括号)
    - [【268.丢失的数字】](#268丢失的数字)

<!-- /TOC -->

## 2022.03.27-04.03 数组

这周完成了 Leetbook 初级算法中的数组专题，每天晚上睡前做一题，因为很多都是简单题，所以花不了多长的时间，感觉还不错。感觉在慢慢养成每天做力扣的习惯。

### 【26.删除有序数组中的重复项】

双指针解法。用一个缓慢的指针来逐渐地替换重复的元素，如果当前元素不满足的话，就按照指针的位置进行替换。

### 【122.买卖股票的最佳时机 II】

这是我能想到的吗？看了题解的贪心解法，大为震惊，太巧妙了。实际上不需要求真正的买入卖出的过程，只需要把这个题简化成寻找多个不相交区间的最大值即可。贪心的方法用了分治的思想，我要求不相交区间的最大值，那么最小的单元就是只有一个元素的区间，我只要每次都获取单个区间的最大贡献就好。（因为区间数最多的情况就是一个元素分一个区间。）贪心的思想就是每个区间都取到最大的贡献，这样整个区间的最大值也就会是最大的贡献了。

### 【189. 轮转数组】

给定 k，确定向右轮转 k 步的数组。1）哈希法：构建一个新的数组，这个数组的第`(i + k) % nums.size()`个元素就是原始数组的第 i 个元素，类似哈希的算法。比如原始第 0 个会向右走`k % nums.size()`步，比较优雅巧妙的做法了。 2）翻转法：首先`k %= nums.size()`，因为如果 k 大于数组长度，会轮转到原始的数组，所以把余数赋给 k 就行。然后一个经典的两只手翻转法，先整个翻转数组，然后翻转前 k-1 个，再翻转 k 到最后一个。这样就能够得到一个轮转 k 次的数组了。

### 【217. 存在重复元素】

简单题，两种方法：1)使用一个`unordered_set<int>`来记录出现过的数字，注意这里要用 unordered_set 才会快，如果用 set 会自动排序，时间消耗会大。2）先把数组排序，如果当前数等于下一个数，那么就返回有重复。

### 【136.只出现一次的数字】

数组里只有 1 个出现一次的数字，其他都是出现两次的数字，找到出现一次的数字。位运算，用 0 异或全部数字即可。

### 【350.两个数组的交集-II】

计算两个数组的交集。用一个哈希表`unordered_map<int, int>`来记录第一个数组的数字出现的次数，然后再遍历第二个数组，如果是在哈希表中的数字的话，那么就加入最终的结果数组中，并更新哈希表。

### 【66.加一】

一个元素只有 0-9 的数组，表示一个大数，将这个数加一。我的思路是用一个整数记录进位，然后直接模拟加法，但是其实这样时间会花的更多。官方题解给的思路是，从后往前找第一个不是 9 的数，然后把它的下一位加 1，然后把从当前的数到数组末尾的数全部置 0。这个方法确实会比较适合这个题目，因为它每次都只是加 1，完全可以不整个模拟一遍加法。

### 【283.移动零】

把数组的所有的 0 放到数组最后。我的解法：遍历一边数组，一遍找 0 一边删除，然后统计 0 的个数，并最后添加相应数量的 0，这个解法不够快。看了一下题解，自己写了一个双指针的方法：初始两个指针都指向第一个元素，然后左边的指针始终指向排好顺序的数组的下一个数（可能是 0，也可能不是）。右指针用来探索当前的数是不是 0。如果不是 0，那么就和左指针指向的元素交换（如果左指针指向的不是 0，那么这个情况只能说明目前还没有 0 找到，那么右指针肯定是和左指针指向的是同一个数，所以不影响），然后再右移左右指针，直到右指针找到最后一个数。

### 【1.两数之和】

给定 target，求满足和为 target 的两个数的 index。用一个`unordered_map<int, int>`记录剩余数值和对应的已取元素的 index。然后遍历一次数组，如果当前 index 的数取了之后，剩余部分能够在哈希表的键中中找到，那么就知道两个数分别是当前 index 和哈希表相应的 index 值。如果找不到的话，就把当前的 index 的数值作为键，index 作为值，存储进哈希表中。这个解法比暴力显然是更好的，时空复杂度都是 O(N)。

### 【36.有效的数独】

判断给定数组的有效性。这里主要是用三个二维数组来记录 1-9 数字的个数，行和列都很简单，但每个九宫格的编号需要用`(rowidx / 3) * 3 + colidx / 3`来计算，注意要乘 3，相当于`colidx / 3`是一个偏移量，`(rowidx / 3)` 每次要包含偏移量导致多出来的 3 个位置，这样才能准确编码出九宫格。基本的思路就是遍历二维数组，然后每次先判断一下三个数组的对应的数是不是已经有了（值为 1），如果有直接返回 false，如果没有就更新数组。

### 【48.旋转图像】

顺时针旋转 90 度的二维方阵。这里我想到可以直接翻转两次得到答案：第一次是类似矩阵的转置，斜 45 度反转，第二次是上下 180 度反转，可以用 C++中的 reverse 函数做到，不过我如果不用 reverse 函数，直接写一个上下翻转的话，就会快一些。这里需要注意一下矩阵转置和上下翻转都只用遍历一部分元素，而不是全部，不然会得到和原来的矩阵一样的矩阵。

## 2022.04.04-04.10 字符串

### 【344.反转字符串】

原地返回字符串。力扣评论笑死了：“做完这道题我又有自信了。”总之就是非常简单的一道题，但也能实在说到双指针的解法，一个前一个后，然后用一个 tmp 字符来进行交换操作。

### 【7.整数翻转】

数学处理，给出 32 位有符号整数，将每位的数字进行翻转。自己写的比较繁琐，题解会比较简洁：先弹出数字，然后依次判断正负溢出的情况，最后推入数字。

一些知识：

1. %求模和求余的不同：-7 求模 10 =-7；-7 求余 10 =3 （C++是求模）
2. 弹出和推入数字的写法：弹出：`num=x%10;x/=10;` 推入：`result=result*10+num;`
3. 考虑溢出：INT_MAX/INT_MIN（推入）

### 【387.字符串中的第一个唯一字符】

用 unordered_map 做一个哈希，用`<char,int>`的存储空间会比`<int,int>`的存储空间更高，因为 char 只占 1 个字节而 int 占 4 个字节。 官方还提供了其他的解法， 比如用哈希表存储单独出现的位置，如果重复的话就置为-1，然后再次遍历找最小的不为-1 的值。还有一个解法是用队列。不过三种解法时间空间复杂度都一样。

### 【242.有效的字母异位词】

异位词就是字符出现次数都相等的词。我刚开始考虑用`unordered_map<char, int>`来存储出现的字符和对应的次数，这样的话，就需要判断键是否存在在 map 中，所以会更耗时间。题解是用一个`vector<int> ch(26,0)`就能够达到同样的功能，这个确实是多写就能自然而然想到的点。

### 【125.验证回文串】

有混着非数字和字母的字符串，判断除开其余字符是否是回文串。这里我考虑的是双指针的想法，一个从右到左，一个从左到右，如果是非字母数字的字符就再向中间走，如果都是数字字母就比较，不相等就返回 false，直到`i>=j`，最后返回 true。题解的想法也不错，先把所有的字母数字挑出来，同时用`tolower()`函数转化为小写字母，然后 reverse 字符串，再比较两个字符串是否相等。但是确实没有双指针法快。

### 【8.字符串转换整数 (atoi)】

这个题很费劲，各种意义上，而且借由这个题能 get 很多知识点，而且最后力扣给的官方题解竟然使用 DFA，枉学自动机好多年。就记录一下用普通的算法需要考虑的点：

1. 起始是字母，直接返回 0。
2. 起始是空格，删除空格：我使用了 while 循环，实际上只需要用`str = str.trim();`函数就可以删除所有空格。
3. 当前起始是数字或加号/当前起始是符号：记录负号，如果是符号就考虑符号后的（我是连续用了 idx 记录，到最后再用一个`string tmp = s.substr(idx, s.length() - idx);`来保存 idx 到结尾的字符串。
4. 删除数字后续的字符串：找到往下的第一个非数字的 idx，然后再用`substr(pos,length)`来截取。
5. 调用`strToNum`函数获取字符对应的数字。

`long strToNum(string s, long num)`的逻辑：

1. num 参数是 1 或-1，表示正数或负数。
2. 如果 s 的长度大于 10，正数返回 INT_MAX，负数返回 INT_MIN。这是为了避免超级长的字符串不进行后续的运算，导致数字太大，但是，注意并不是 10 位数以下都是不越界的。
3. s 长度小于等于 10 时，正常计算对应的数，这里要用 long 来存储，并乘 num 来表示正负数。
4. 判断当前计算的结果是否小于 INT_MIN 或大于 INT_MAX，如果是就修改为边界值，如果不是就用 int()强制类型转换，并最后返回。

其他的一些知识：

1. 判断字符是否是数字：`bool isNum=Character.isDigit(ch)`，是数字返回 true，不是返回 false。
2. `Integer.MIN_VALUE=INT_MIN=-2^32`，`Integer.MAX_VALUE=INT_AX=2^32-1`。

### 【28.实现 strStr()】

在 haystack 字符串中找出 needle 字符串出现的第一个位置，如果不存在就输出-1，如果 needle 是空字符串就返回 0。主要有两种算法，暴力和 KMP 算法（之后再专门梳理 KMP 算法的理解）。

### 【38.外观数列】

下一个字符串是根据上一个字符串作为描述生成的，给定 n 求第 n 个生成的数列。写的时候稍微思路有点乱，实现了给定描述生成字符串和给定字符串生成描述的两个函数，结果发现后一个根本不需要。还有一个要注意的点是：最开始写的时候把描述搞错了，用了一个 10 个数字的数组作为哈希表，但是实际上统计次数还要符合数字的出现顺序，所以用一个外部的变量循环地记录当前数字出现的次数，如果当前数字和下一个数字不符时，更新输出的字符串和外部变量即可。

### 【14.最长公共前缀】

茴有几种写法，最长公共前缀有几种写法？看官方题解的话，明明是个简单题，会发现有 4 种解法。

1. 横向扫描: 依次遍历，每个遍历的字符串更新公共前缀。时间：O(mn)，空间 O(1)。m 是字符串平均长度，n 是字符串数量，后续相同。
2. 纵向扫描：遍历每一列，这个思路和我的解法比较类似。时间：O(mn)，空间 O(1)。
3. 分治法：LCP 满足结合律，分治法求最长前缀，分解成两个子问题分别求解，然后再计算最长前缀。时间：O(mn)，空间 O(mlogn)。
4. 二分查找法：最长公共前缀的长度不会超过字符串数组中的最短字符串的长度，用二分查找来确定即可。时间：O(mnlogm)，空间 O(1)。

## 2022.04.11-04.17 链表

一些常用技巧：

1. 链表增加哑结点 dummy，就不用单独判断 head 节点了。`ListNode* dummy = new ListNode(0, head);`
2. 删除节点 dummy： `delete dummy;`
3. 区分`cur.val`和`cur->val`：使用`cur.val`时，cur 是一个结构体，而使用`cur->val`时，cur 是一个指向结构体的指针。
4. 基于 3，注意区分节点和节点的指针的初始化：
   - 初始化节点`ListNode* Node = new ListNode(0，NULL);`
   - 初始化一个节点的指针 `ListNode* node = head;`

【237.删除链表中的节点】
只能访问删除节点的情况下把该节点删除。因为一般来说要删除一个节点，更方便的方法是找到它的前驱节点。这题就要稍微绕一点弯，只需要把下一个节点的值赋给当前的节点，然后把下一个节点删除即可。

【19.删除链表的倒数第 N 个结点】
我用的方法就很朴素，找要删除节点的前驱节点（第`length-n-1`个节点）。需要特别考虑链表有 n 个元素，删除倒数第 n 个的情况，这时候没法找到前驱，所以直接返回`head->next`。看了下题解，比较值得借鉴的方法是双指针法，也是只用遍历一次的方法：使用两个指针同时遍历，first 比 second 超前 n 个节点，当 first 遍历到链表的末尾时，second 就恰好处于待删除的节点，很妙。

### 【206.反转链表】

反转整个链表，用三个指针遍历反转链表，这里需要注意的一个地方是：反转第一个节点时，不能让第二个节点再指向第一个节点，否则第一个和第二个节点会形成一个环。在我的解法里，增添了一个尾部的哑节点，这样可以少一些判断，而且第三个指针也可以重复更新，不用每个循环重新定义一个指针，减少空间开销。

### 【21.合并两个有序链表】

注意返回的节点需要是原来的节点，所以相当于需要改变两个链表指向的节点，因此需要两个指针分别指向链表的还未排序的节点，然后比较当前的节点，直到遍历完至少有一个链表。

### 【234.回文链表】

判断链表是否是回文的，最简单的办法就是遍历一次链表，然后把值存储在一个数组中，然后问题转换成判断一个数组是否是回文串，双指针迎刃而解。我写这题的想法略麻烦，我用数组存储了一半元素，然后它们再逐个和后半段数组进行比较，虽然确实时空复杂度都提高了一些，但代码属实不够优雅，因为需要考虑奇数个和偶数个序列的差别。

### 【141.环状链表】

判断链表有没有环。朴素的方法就是用一个哈希表`unordered_set<ListNode*>`来存储链表的元素，然后不断遍历判断。更巧妙的方法就是用一快一慢两个指针（一个每次指向下一个元素，另一个每次指向下两个元素），如果两个指针重合的话，那么就说明是有环的。

## 2022.04.18-04.24 树

树相关的题目主要是能够快速找出思路，有了思路其实递归函数也就能够很快地找到。比较值得多看一下的题目是层次遍历和对称二叉树，这两题没有能很快地找到思路。

### 【104.二叉树的最大深度】

给定二叉树找最大深度。一个值得记忆的内容就是，最大深度等于左子树的最大深度，右子树的最大深度中较大的再加 1，这种递归的思想可以让解法变得非常简便。另一种做法就是用广度优先搜索，每次取一整层的节点，并添加下一层的全部节点，每次循环结束后对层数进行计数。

### 【98.验证二叉搜索树】

这里要注意二叉搜索树的定义，并不是只判断单个节点就可以了，还需要判断整个区间内的节点中序遍历是升序的。所以递归函数需要有三个参数；节点、区间最小值和区间最大值，然后用当前节点的值更新最值，不断递归缩小左右两个区间。

### 【101.对称二叉树】

对称二叉树就是同层的左子树的左节点等于右子树的右节点，并且左子树的右节点等于右子树的左节点。递归函数主要就是判断上面这两个条件是否成立，然后不断地递归即可。

### 【102.二叉树的层序遍历】

层次遍历返回的是一个二维的 vector。这里可以使用 BFS 算法，不断扩展每层的节点。先处理当前层的节点，然后全部把节点弹出队列，再把下一层的节点全部放进队列。

### 【104.将有序数组转换为二叉搜索树】

数组是有序的，所以每次递归时都选择区间的中点`(left + right)/2`来作为根节点，然后分别递归，不断找到左节点和右节点。

## 2022.04.25-05.01 排序和搜索

### 【88.合并两个有序数组】

两种双指针的方法，一种是从小到大正向的双指针，另一种是从大到小的反向的双指针。后面一种双指针的方法就不需要重新开一个 vector 来避免数组的覆盖，比较巧妙。

### 【278.第一个错误的版本】

典型二分查找题，这里需要注意一个点：mid 的计算应该是`left + (right - left) / 2`，这样会避免数组越界。

## 2022.05.02-05.08 动态规划

动态规划章节里的经典题，且都是一维数组的动态规划，它们的套路非常相似，都是定义一个动态规划数组，然后找到初值，再一次遍历参数的数组，用状态方程来更新动态规划数组。而且，由于动态规划的无后效性（后面的计算不会改变前面计算的结果），因此有些一维数组的动态规划题很适合压缩成一个整数或多个整数，比如第 70 题可以压缩成 3 个整数，第 121 题和第 53 题可以压缩成一个整数，从而一定程度上降低空间复杂度。

### 【70.爬楼梯】

每次能上一层或者两层台阶，求解爬楼梯的方法数。动态规划的数组`dp[i]`表示在第`i`层楼梯时的方法数。有点类似递归，但是可以直接正向计算，一个 for 循环搞定。动态规划的转移方程是`dp[i]=dp[i-1]+dp[i-2]`。因为每层楼梯可以有两种到达的方式。

### 【121.买卖股票的最佳时机】

这题需要两个动态规划数组`dp_minv[i]`和`dp_totalv[i]`，`dp_minv[i]`表示第 `i `天时的买入的最小值，`dp_totalv[i]`表示第 `i` 天时能够赚到的最多的钱。在 for 循环中，转移方程分别是`dp_minv[i] = min(prices[i], dp_minv[i - 1])`，和`dp_totalv[i] = max(dp_totalv[i - 1], prices[i] - dp_minv[i - 1]);`。前一个转移方程很好理解，后一个转移方程就是取之前的能够赚到的总价值和第`i`天卖掉第 `i` 天前买入最小值赚到的总价值这两者的较大值。这题可以不用动态规划数组来做，可以只用一个整数来记录买入最小值和总体的最大值。

### 【53.最大子序和】

只用一个整数循环记录最大子序和。`dp = max(dp + nums[i], nums[i]);`表示有两种选择，要么加当前的数字，要么不加，取二者中较大的一项。如果比当前 `res` 大，就更新`res`，最后返回 `res`。这题还可以用线段树求解，我只看了一下题解，还没有自己写一遍。

### 【198.打家劫舍】

中等难度题，需要考虑一下。由于不能偷相邻的房子，所以可以想到会有两种情况，一个是偷三个房子里中间的，另一个是偷两边的。`dp[i]`表示前`i`间房屋能偷到的最高总金额，很自然地能写出`i`为 0 和 1 的情况。状态转移方程是`dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])` 因为每次在第`i`间房的时候，可以有两个选择：偷第`i-1`间房，或者偷第`i`间和第 i-2 间但不偷第`i-1`间。就是像在第`i`间房时，需要考虑还要不要偷第`i-1`间房，如果不投的话，就得回退到`dp[i-2]`再加上当前第 i 间房可偷的，如果不如偷`i-1`的话，就不投第`i`间。

## 2022.05.09-05.15 设计问题

### 【384.打乱数组】

洗牌算法的经典题。主要有三种做法。

- 暴力算法：一个辅助的数组`w`，包含所有的数字。然后遍历`len`次，在第`i`个循环，用`rand() % w.size()`生成随机数`k`，然后将辅助数组的第`k`个元素放到打乱数组的第`i`个。为了避免重复选取，每次删除选取过的`w[k]`(算法复杂度为`O(n)`)。
- Fisher-Yates 洗牌算法：我看了很久官方题解没理解它的意思，参考了其他的一些资料，才搞懂这个算法。它整体的思路是不断向前打乱数组，也就是说还没有打乱的数组会从最后一个元素到第一个不断地被打乱。打乱数组的长度为`len`。遍历`len`次，在第`i`个循环，用`rand() % (len-i)`生成随机数`k`，然后将打乱数组的第`k`个和第`len-i-1`个交换。
- Knuth 洗牌算法： Knuth 的算法就是对上面算法的改进，但是反过来，它是随机选取后半段的数组，然后和前面的第`i`个进行交换。这样每次循环第`i`个元素都会是被打乱了的，所以是前半段的数组都是打乱后的。

### 【155.最小栈】

简单题，我用了一个`vector<int>`来模拟栈，这样不可避免地在返回最小值的时候要反复计算。
题解的做法是用一个辅助的栈结构来快速地获得最小值。这个辅助栈的第`i`个元素是原始的栈的前 i 个元素中的最小值。它的增减和原始栈同步，这样每次调用求最小值的函数只需要返回栈顶元素就可以了。

## 2022.05.16-05.22 数学

初级算法数学章节的四题都是简单题，值得多次看的还是计数质数这一题，比较经典了。

### 【412.Fizz Buzz】

C++里数字转字符串的函数是`to_string(i)`，我写这题的时候搞忘了，还自己写了一个数字转字符串的函数。整体来说就是非常简单的模拟题。

### 【204.计数质数】

如果用最基础的方法逐个判断是否是质数，那么就会 TLE。所以需要使用比较典型的做法：埃氏筛和线性筛。**埃氏筛**的基本思路是：如果一个数是质数，那么就标记`x*x`，`x*(x+1)`...不断遍历。这样不需要用基本的方法来判断是否是质数，只需要用一个标记的数组来更新即可。**线性筛**就是对埃氏筛的优化，保证每个合数只被标记一次，就是用之前已经确定的质数集合来与当前的数相乘，作为要标记的数。当$x \;\; mod \;\; prime_i = 0$时就结束标记。

### 【326.3 的幂】

第一种方法就是最基础的，不断除以 3，直到 `n` 为 0 或者 `n%3` 为 0。显然如果 n 为 0 的情况就是 n 没能被 3 整除，如果最后 n 为 1 的情况就说明能被 3 整除。
第二种简便的方法就是考虑大于给定数的最大范围的最小的一个 3 的幂，也就是 3 的 19 次方，这样如果 n 是 3 的 19 次方的约数，那么就能够被 3 整除。

### 【13.罗马数字转整数】

简单模拟题，看起来有点复杂实际上逻辑非常简单，从最后一位遍历到第一位，如果发现前一个数比后一个数小，就用结果减去这个数，反之就用结果加上这个数。

## 2022.05.23-05.29 其他

这一章节虽然叫“其他”，但是有好几题都是位运算的题目，刚好可以做一个复习。

### 【191.位 1 的个数】

主要有两种方法，第一种就是循环检查二进制的每一位是否都是 1，第二种方法就是不断翻转 n 的二进制位的最低位的 1 变为 0，在这个操作中翻转一次就记录一次 1 的个数，直到最后 n 变为 0。

### 【461.汉明距离】

汉明距离就是两个数二进制上数字不同的位数，所以可以先进行一个异或操作，这样问题就转化为异或后的结果的 1 的个数，和上一题非常类似。这里可以使用一个函数`__builtin_popcount`来直接调用内置的计数功能，但也可以用上一题的方法来计数，或者可以不断右移移位 n ，然后用`n & 1`来统计 1 的个数。

### 【190.颠倒二进制位】

把 n 的二进制位从右到左写出来，即为颠倒二进制位的结果。这里可以不断右移 n，然后取出从右到左的第 i 位，再将最后一位左移 31-i 位，累加到 ans 中。整个式子可以写成`ans = ans | (n&1)<<(32-i);`。
第二种方法比较巧妙，就是用掩码来递归式地翻转二进制位，是一种分治的思想。从最大的两个区间，然后再把小的区间再分为两个区间翻转，最后分治到一个数就是一个区间，翻转两个区间就变为交换两个相邻的数。可以具体看看这题的官方题解和后面的代码就很容易理解了。

### 【118.杨辉三角】

简单模拟题，没什么好说的，就是一行一行地计算即可。

### 【20.有效的括号】

检测括号是不是前后对应。这里就用栈的数据结构来存储即可。主要需要注意的是一些边界条件，比如开始就是反括号，还有最后如果栈不为空的情况也需要考虑。

### 【268.丢失的数字】

这个题很简单，因为只缺少一个数字，所以把所有的数累加起来，然后用不少这个数字的总和减去它，就可以得到缺少的那一个数字。
另一个巧妙的做法就是位运算，只需要在 n 个数后再添加 0 到 n 这 n+1 个数然后用按位异或运算就可以得到丢失的数字。
