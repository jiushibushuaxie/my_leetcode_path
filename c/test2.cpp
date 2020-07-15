#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class String{

friend ostream& operator<<(ostream& cout,const String &str);

private:
    char* m_data;
public:
    String(const char* str=NULL);
    ~String();
    String(const String& other);
    String& operator=(const String& other);
    String(String&& other) noexcept;
    String& operator=(String&& other) noexcept;
};

ostream& operator<<(ostream& cout, const String& str){
    cout<<str.m_data;
    return cout;
}

String::String(const char* str){
    if(str==NULL){
        m_data = new char[1];
        *m_data = '\0';
    }
    else{
        m_data = new char[strlen(str)+1];
        strcpy(m_data, str);
    }
}

String::~String(){
    delete[] m_data;
    m_data = NULL;
}

String::String(const String& other){
    m_data = new char[strlen(other.m_data)+1];
    strcpy(m_data, other.m_data);
}
String& String::operator=(const String& other){
    if(&other == this){
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(other.m_data)+1];
    strcpy(m_data, other.m_data);
    return *this;
}
String::String(String&& other) noexcept{        //
    m_data = other.m_data;
    other.m_data = NULL;
}
String& String::operator=(String&& other) noexcept{
    if(&other == this){
        return *this;
    }
    delete[] m_data;
    m_data = other.m_data;
    other.m_data = NULL;
    return *this;
}

int main(){
    String a("hello");            //调用普通构造函数
    String b("world");           //调用普通构造函数
    String c(a);                //调用拷贝构造函数
    c = b;                     //调用赋值函数
    cout<<c<<endl;          //重载<<运算符
    return 0;
}
