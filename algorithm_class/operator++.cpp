//前置与后置运算符重载
#include <iostream>
using namespace std;

class Myint{
private:
    int m_Int;
public:
    Myint():m_Int(0){}
    ~Myint() = default;

    //前置++重载  
    //前置++返回类型为对象引用
    Myint& operator++(){
        ++(this->m_Int);
        return *this;
    }
    //后置++重载 多一个默认占位参数int
    //后置++返回类型为对象
    Myint operator++(int){
        Myint ret = *this;   //记录当前值
        ++*this;    //调用前置++
        return ret;
    }

    

};

void test01(){
    Myint myint;
    ++myint;
    myint++;


}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}


