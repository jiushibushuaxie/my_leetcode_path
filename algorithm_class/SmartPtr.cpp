//实现智能指针   与shared_ptr一样
#include <iostream>
#include <memory>
using namespace std;

template<typename T>
class SmartPointer {

public:
    //构造函数，默认参数为空指针，如果_ptr是空指针，_count为0
    SmartPointer(T* ptr = nullptr) : _ptr(ptr) {  
        if (_ptr) _count = new int(1);   
        else _count = new int(0);
    }
    //拷贝构造函数，注意为形参const
    SmartPointer(const SmartPointer& ptr) {
        if (this != &ptr) {             //拷贝指向的不是本身
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            (*this->_count)++;
        }
    }
    //重载operator=  返回类型为&  形参为const &常量引用
    SmartPointer<T>& operator=(const SmartPointer<T>& ptr) {
        if (this->_ptr == ptr._ptr) {       //指向的是本身  直接返回
            return *this;
        }

        if (this->_ptr) {               //赋值左边对象指针非空，
            (*this->_count)--;          //先对赋值左边对象count--
            if (this->_count == 0) {       //赋值左边对象count为0，delete赋值左边对象数据
                delete this->_ptr;          
                delete this->_count;
            }
        }

        this->_ptr = ptr._ptr;          //执行赋值操作
        this->_count = ptr._count;
        (*this->_count)++;              //++赋值右边对象count
        return *this;
    }

    // 重载 operator* 实现指针功能   返回值为T&
    T& operator*() {
        assert(this->_ptr == nullptr);
        return *(this->_ptr);

    }
    // 重载 operator-> 实现指针功能     返回值为T*
    T* operator->() {
        assert(this->_ptr == nullptr);
        return this->_ptr;
    }

    //析构函数
    ~SmartPointer() {
        (*this->_count)--;              //离开作用域时，先减减_count
        if (*this->_count == 0) {       //做个判断
            delete this->_ptr;
            delete this->_count;
        }
    }

    int use_count(){                //打印_count接口
        return *this->_count;
    }

private:
    T* _ptr;
    int* _count;
};

//测试用例
int main() {
    {
        SmartPointer<int> sp(new int(10));
        SmartPointer<int> sp2(sp);
        SmartPointer<int> sp3(new int(20));
        sp2 = sp3;
        std::cout << sp.use_count() << std::endl;
        std::cout << sp2.use_count() << std::endl;
        std::cout << sp3.use_count() << std::endl;
    }
    //delete operator
}