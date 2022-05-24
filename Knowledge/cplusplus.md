# C++知识 🤭

> 一个为周赛准备的 C++ cheatsheet

- [C++知识 🤭](#c知识-)
  - [变量存储空间大小](#变量存储空间大小)
    - [x86](#x86)
    - [x64](#x64)
    - [INT 的边界](#int-的边界)
  - [数组](#数组)
  - [字符与字符串](#字符与字符串)
  - [STL](#stl)
    - [`<vector>`](#vector)
      - [迭代器](#迭代器)
    - [`<string>`](#string)
      - [基础函数](#基础函数)
    - [`<stack>`](#stack)
      - [基础函数](#基础函数-1)
      - [栈的遍历](#栈的遍历)
    - [`<map>`](#map)
      - [`<unordered_map>`](#unordered_map)
    - [`<set>`](#set)
      - [基础函数](#基础函数-2)
      - [遍历](#遍历)

## 变量存储空间大小

注释中是变量占的字节数。

### x86

```c++
sizeof(char)  //1
sizeof(char*)  //4
sizeof(int)  //4
sizeof(int*)  //4
sizeof(double)  //8
sizeof(double*)  //4
sizeof(float)  //4
sizeof(float*)  //4
sizeof(string)  //28
sizeof(string*)  //4
```

### x64

```c++
sizeof(char)  //1
sizeof(char*)  //8
sizeof(int)  //4
sizeof(int*)  //8
sizeof(double)  //8
sizeof(double*)  //8
sizeof(float)  //4
sizeof(float*)  //8
sizeof(string)  //40
sizeof(string*)  //8
```

### INT 的边界

INT_MAX = 2^31-1=2147483647
INT_MIN = -2^31=-2147483648
也可以写成 Integer.MAX_VALUE 和 Integer.MIN_VALUE。

## 数组

数组的赋值：

```c++
//1
int mat[10][10];
memset(mat,0,sizeof(mat));
//2
int mat[10][10]={0}; //初始化为0
```

## 字符与字符串

判断字符是否是数字：`bool isNum=Character.isDigit(ch)`，是数字返回 true，不是返回 false。

## STL

### `<vector>`

#### 迭代器

定义迭代器：`vector<int>::iterator iter;`
遍历迭代器：

```c++
vector<int> ivec;
for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
```

删除迭代器指向的内容：

```c++
ivec.erase(iter);
```

**删除迭代器指向的元素之后，当前迭代器的指向的单元没有变，而是先清空当前单元，然后后面单元的内容一个接一个移动到了前一个单元。**

移动迭代器
advance() 函数用于将迭代器前进（或者后退）指定长度的距离，其语法格式如下：

```c++
template <class InputIterator, class Distance>
    void advance (InputIterator& it, Distance n);
```

其中 it 指的是目标迭代器，n 通常为一个整数。

需要注意的是，如果 it 为输入迭代器或者前向迭代器，则 n 必须为一个正数，即表示将 it 右移（前进） n 个位置；反之，如果 it 为双向迭代器或者随机访问迭代器，则 n 为正数时表示将 it 右移（前进） n 个位置，n 为负数时表示将 it 左移（后退） n 个位置。

### `<string>`

#### 基础函数

```c++
#include<iostream>
using namespace std;
int main()
{
 string str="hello";
 string s="Hahah";
 str.insert(1,s);//在原串下标为1的字符e前插入字符串s
 cout<<str<<endl;

 string str1="hello";
 char c='w';
 str1.insert(4,5,c);//在原串下标为4的字符o前插入5个字符c
 cout<<str1<<endl;

 string str2="hello";
 string s2="weakhaha";
 str2.insert(0,s2,1,3);//将字符串s2从下标为1的e开始数3个字符，分别是eak，插入原串的下标为0的字符h前
 cout<<str2<<endl;

 return 0;
}
```

删除空格：`str = str.trim();`




string 转 int `int num=stoi(str.c_str())`


### `<stack>`

#### 基础函数

```c++
stack<T> st;
st.empty();         //如果栈为空则返回true, 否则返回false;
st.size();          //返回栈中元素的个数
st.top();           //返回栈顶元素值, 不弹栈
st.pop();           //弹栈,注意不返回其值
st.push();          //压栈
```

#### 栈的遍历

想要多次遍历栈，但是又保护栈的结构，以下是一种可能的方法：

```c++
vector<T> v;
while (!st.empty())
{
    v.push_back(st.top());
    cout << st.top() << " ";
    st.pop();
}
for(int i=v.size()-1;i>=0;i--)
{
    st.push(v[i]);
}

```

### `<map>`

#### `<unordered_map>`

unordered_map 在插入键的时候不会进行排序，所以一般不需要排序的哈希表用 unordered_map 来实现。

### `<set>`

#### 基础函数

```c++
set<T> st;
st.begin(); //返回第一个元素
st.end();   //返回s最后一个元素
st.clear(); //删除s所有的元素
st.empty(); //判断s是否为空
st.size(); 　//返回元素个数
st.max_size() //可存储的最大元素个数
int element=5;
//判断元素是否在集合set中,存在返回1，不存在返回0
st.count(element);
//添加元素
st.insert(element);
//删除元素
auto it = st.begin();
st.erase(*it);

```

#### 遍历
