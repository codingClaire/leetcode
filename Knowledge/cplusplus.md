# C++知识 🤭

> 一个为周赛准备的 C++ cheatsheet

- [C++知识 🤭](#c知识-)
  - [数组](#数组)
  - [STL](#stl)
    - [`<vector>`](#vector)
      - [迭代器](#迭代器)
    - [string](#string)
    - [`<stack>`](#stack)
      - [基础函数](#基础函数)
      - [栈的遍历](#栈的遍历)
    - [map](#map)
      - [unordered_map](#unordered_map)
    - [`<set>`](#set)
      - [基础函数](#基础函数-1)

## 数组

数组的赋值：

```c++
//1
int mat[10][10];
memset(mat,0,sizeof(mat));
//2
int mat[10][10]={0}; //初始化为0
```

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

### string

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

### map

#### unordered_map

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
