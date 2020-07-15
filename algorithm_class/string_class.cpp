//编写类String的构造函数、析构函数和赋值函数，已知类String的原型为：
//能够准确无误地编写出String类的构造函数、拷贝构造函数、赋值函数和析构函数的面试者至少已经具备了C++基本功的60%以上！ 
//当类中包括指针类成员变量时，一定要重载其拷贝构造函数、赋值函数和析构函数，
//这既是对C++程序员的基本要求，也是《Effective　C++》中特别强调的条款。 


/*
 (1）普通构造函数：这里判断了传入的参数是否为NULL。如果是NULL，初始化一个字节的空字符串（包括结束符'\0'）；如果不是，分配足够大小长度的堆内存保存字符串。
（2）拷贝构造函数：只是分配足够小长度的堆内存保存字符串。
（3）析构函数：为了避免产生野指针，将m_String赋为NULL。
（4）赋值函数：首先判断当前对象与引用传递对象是否是同一个对象，如果是，不做操作直接返回；否则先释放当前对象的堆内存，然后分配足够大小长度的堆内存拷贝字符串。
*/

/*
//使用noexcept表明函数或操作不会发生异常，会给编译器更大的优化空间
以下情形鼓励使用noexcept：
    移动构造函数（move constructor）
    移动赋值函数（move assignment）
*/
#include <iostream>
#include <cstring>
using namespace std;

class String{ 

friend ostream& operator<<(ostream& cout,const String &str);

public: 
    String(const char *str = NULL); // 普通构造函数 
    String(const String &other); // 拷贝构造函数 
    ~ String(); // 析构函数 
    String& operator =(const String &other); // 赋值函数 

    // 移动构造函数
   String(String&& str) noexcept {      //这里参数类型是String&& str
        m_data = str.m_data;
        str.m_data = nullptr; //不再指向之前的资源了
    }

   // 移动赋值函数 =号重载
   String& operator=(String&& str) noexcept;
private: 
    char *m_data; // 用于保存字符串 
};

//普通构造函数
String::String(const char *str) {
    cout << "Construcing" << endl;
    if(str==NULL) {             //加分点：对m_data加NULL 判断
        m_data = new char[1];   // 分配一个字节
        *m_data = '\0';         //将之赋值为字符串结束符
    } 
    else{
        m_data = new char[strlen(str)+1];        //分配空间容纳str内容  +1是放'\0'结束符
        strcpy(m_data, str); 
    }
}

// String的析构函数
String::~String(void) {
    cout << "Destructing"<< endl;
    delete [] m_data; // 或delete m_data;
    m_data = NULL;    
}

//拷贝构造函数
String::String(const String &other){  // 得分点：输入参数为const型 
    cout << "Constructing Copy" << endl;
    m_data = new char[strlen(other.m_data)+1]; 
    strcpy(m_data, other.m_data); 
}

//赋值函数,重点
String & String::operator =(const String &other){ // 得分点：输入参数为const型
    cout << "Operate = Function" << endl; 
    if(this == &other) return *this;        //得分点：检查自赋值

    delete [] m_data;                       //得分点：释放原有的内存资源

    m_data = new char[strlen(other.m_data)+1];
    strcpy( m_data, other.m_data ); 
    return *this;           //得分点：返回本对象的引用
}

String& String::operator=(String&& str) noexcept{
    if (this == &str) // 避免自我赋值!!
        return *this;

    delete[] m_data;
    m_data = str.m_data;
    str.m_data = nullptr; //不再指向之前的资源了
    return *this;
}

//定义为全局函数，同时为类的友元函数
ostream& operator<<(ostream& cout,const String &str){
    cout<<str.m_data;
    return cout;
}

int main(){
    String a("hello");            //调用普通构造函数
    String b("world");           //调用普通构造函数
    String c(a);                //调用拷贝构造函数
    c = b;                     //调用赋值函数
    cout<<c<<endl;          //重载<<运算符
    return 0;
}