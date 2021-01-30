#include<iostream>
#include<string>
using namespace std;
//重载递增运算符
//自定义整型
class MyInteger
{
    //友元
    friend ostream& operator<<(ostream& cout,MyInteger myint);
    public:
    MyInteger()
    {
        m_Num=0;
    }
    //重载前置 ++运算符
    MyInteger& operator++()
    {
        m_Num++;
        return *this;
    }
    //重载后置 ++运算符
    //void operator(int) int 代表占位参数，可以用于区分前置和后置
    MyInteger operator++(int)
    {
        //先 记录当时结果
        MyInteger temp=*this;
        //递增
        m_Num++;
        // 最后将记录结果作返回
        return temp;
    }
    private :
    int m_Num;
};
//重载下左移运算符
ostream& operator<<(ostream& cout,MyInteger myint)
{
    cout<<myint.m_Num;
    return cout;
}
void test01()
{
    MyInteger myint;
    cout<<myint<<endl;
}

int main()
{
    
}