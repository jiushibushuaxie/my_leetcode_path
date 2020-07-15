#pragma once
#include <iostream>
using namespace std;

class MyArray{
public:
    MyArray();      //默认构造
    MyArray(int capacity);      //带容量的构造函数
    MyArray(const MyArray& arr);    //拷贝构造函数
    ~MyArray();    //析构函数

    //尾插法
    void push_back(int val);

    //根据索引获取值
    int getData(int index);

    //根据索引设置值
    void setData(int index,int val);

    //获取数据大小
    int getSize();

private:
    int *pAddress;      //指向真正存储数据的指针
    int m_Size;         //数据大小
    int m_Capacity;     //数组容量

};