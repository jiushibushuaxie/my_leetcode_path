//实现数组
#include "ArrayClass.h"

//默认构造函数,利用初始化列表
// MyArray::MyArray():m_Capacity(100), m_Size(0), pAddress(new int[m_Capacity])  {}

//默认构造函数,利用this指针
MyArray::MyArray() {
    this->m_Capacity = 100; 
    this->m_Size = 0; 
    this->pAddress = new int[m_Capacity];
}

//有参构造函数,利用初始化列表
MyArray::MyArray(int Capacity):m_Capacity(Capacity), m_Size(0), pAddress(new int[m_Capacity])  {}

//拷贝构造 
MyArray::MyArray(const MyArray& arr){
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    this->pAddress = new int[arr.m_Capacity];

    for(int i=0;i<arr.m_Size;i++){
        this->pAddress[i] = arr.pAddress[i];
    }
}

//析构构造
MyArray::~MyArray(){
    if(this->pAddress!=nullptr){
        delete []this->pAddress;
        this->pAddress = nullptr;
    }
}

void MyArray::push_back(int val){
    this->pAddress[this->m_Size] = val;
    this->m_Size +=1;

    //越界？用户自己处理
}


int MyArray::getData(int index){
    return this->pAddress[index];
}

void MyArray::setData(int index,int val){
    this->pAddress[index] = val;
}

int MyArray::getSize(){
    return this->m_Size;
}