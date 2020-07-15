
#include <iostream>

using namespace std;

//单例模式，饿汉模式
//主席案例
class ChairMan{
private:
    //1、构造函数私有化
    ChairMan(){
        cout<<"creat chairman class"<<endl;
    }
    // 4、拷贝构造函数私有化
    ChairMan(const ChairMan& other){}

    //2、利用static全局特性  数据也是私有化，同时定义公共接口
    static ChairMan* singleMan;

public:
    //3、提供getInstance静态成员方法，访问主席
    static ChairMan * getInstance(){
        return singleMan;
    }

};
//类内声明，类外定义，注意要加作用域
ChairMan* ChairMan::singleMan = new ChairMan;

void test01(){
    //ChairMan c1;              //1、因为构造函数为private，因此不能创建对象
   // ChairMan::singleMan;      //2、因为singleMan为private，因此访问

   ChairMan* c1 = ChairMan::getInstance();      //3、 getInstance访问
   ChairMan* c2 = ChairMan::getInstance();
   if (c1==c2) cout<<"c1 same as c2"<<endl;
   else cout<<"c1 and c2 is different"<<endl;

   //ChairMan* c3 = new ChairMan(*c2);       //4、因为拷贝构造函数为private，因此不能拷贝对象
}

int main(){   
    cout<<"main"<<endl;     //ChairMan构造函数在main主函数调用之前，因为static数据成员在编译时建立内存，而不是运行时
    test01();
    return 0;
}
    
/*----------------------------------------------------------------------*/
//C++11支持
//懒汉模式
template<typename T>
class Singleton
{
public:
    //C++11局部静态变量不仅只会初始化一次，而且还是线程安全的。懒汉模式
    // 注意返回的是引用。
    static T* getInstance() {
        static T* m_instance = new T; //静态局部变量
        return m_instance;
    }

private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton&); //拷贝构造函数
    Singleton& operator=(const Singleton&); // =运算符重载
};

//懒汉模式加锁
#include <iostream>
#include "pthread.h"
using namespace std;

template<typename T>
class Singleton{
private:
    static T* instance;
    static pthread_mutex_t mutex;

    Singleton() {}  
    ~Singleton();
    Singleton(const Singleton&); //拷贝构造函数
    Singleton& operator=(const Singleton&); // =运算符重载
    
public:
    static T* GetInstance() {       //GetInstance为静态成员函数
        if (instance == NULL) {     //双重锁 1
            pthread_mutex_lock(&mutex);     
            if (instance == NULL) {         //双重锁 2
                instance = new T(3);        //初始化
            }
            pthread_mutex_unlock(&mutex);
        }
        return instance;
    }
};

template<class T>
pthread_mutex_t Singleton<T>::mutex = PTHREAD_MUTEX_INITIALIZER;

template<class T>
T* Singleton<T>::instance = NULL;

int main() {
    int* p1 = Singleton<int>::GetInstance();
    cout << *p1 << endl;     // 3

    int* p2 = Singleton<int>::GetInstance();
    cout << *p2 << endl;     // 3

    return 0;
}