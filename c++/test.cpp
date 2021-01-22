#include<iostream>
using namespace std;
#define M 7
#define n 8
//常量是无法修改的
int main()
{  
    //默认是double类型的
    //默认情况下，输出一个小数，会显示出6位有效数字
    float f1=3.14f;
    cout<<"f1="<<f1<<endl;
    double d1=3.14;
    cout<<"d1="<<d1<<endl;
    //统计float和double占用内存空间
    //一般float4个字节，double则为8个字节
    cout<<"float:"<<sizeof(float)<<endl;


}