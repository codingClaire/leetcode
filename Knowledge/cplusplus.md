# C++知识 🤭

> 一个为周赛准备的 C++ cheatsheet

- [C++知识 🤭](#c知识-)
  - [数组](#数组)
  - [STL](#stl)
    - [vector](#vector)
    - [string](#string)
    - [`<stack>`](#stack)
      - [基础函数](#基础函数)
      - [栈的遍历](#栈的遍历)
    - [map](#map)
      - [unordered_map](#unordered_map)
    - [set](#set)

## 数组

## STL

### vector

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
while (!st.empty()) {
    v.push_back(st.top()); 
    cout << st.top() << " ";
    st.pop();
}
for(int i=v.size()-1;i>=0;i--){
    st.push(v[i]);
}

```

### map

#### unordered_map

### set
