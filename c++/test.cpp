#include<iostream>
#include<string> //用c++风格字符串
using namespace std;

//引用做函数的返回值
//1.局部变量不可以返回引用，因为栈已经被释放了
int& test01()
{
    int a=10; //局部变量存放在四区中的栈区
    return a;
}
//2.静态变量可以返回引用，因为是存放在全局区，程序结束才释放
int& test02()
{
    static int a=10;
    return a;
}
int main()
{  
 

   
}