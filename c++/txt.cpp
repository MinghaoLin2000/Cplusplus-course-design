#include<iostream>
#include<string>
using namespace std;
//1.创建一个类，c++编译器会给每个类都添加至少3个函数
// 默认构造（空实现）
// 默认析构函数（空实现）
// 拷贝构造（值拷贝）
class Person
{
    public:
    int m_B;
    static void func()
    {
        m_A=200;
        cout<<"static void func调用"<<endl;
    }
    static int m_A;//静态成员变量
};
int Person::m_A=0;
int main()
{
  Person::func();
    Person::m_A=0; 

}