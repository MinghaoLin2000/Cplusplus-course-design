#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//高精度本质上将大数，存为了字符串或者数组的形式来计算 
//这以下代码只适合于两个正数相加，两个负数的话，先把负号去掉，然后最后输出结果那里填个负号
int c[10000001];//记录结果的数组
string a,b;
long long k=0,r=0,i,j; //r为进位
bool flag;
int main()
{
    cin>>a>>b;
    if(a.size()<b.size()||a.size()==b.size()&&a<b)
    {
        //统一将长的字符串放到前面
        swap(a,b);
    }
    for(i=a.size()-1,j=b.size()-1;j>=0;j--,i--)
    {
        c[k++]=(a[i]-'0'+b[j]-'0'+r)%10;//两数相加，然后取各位
        r=(a[i]-'0'+b[j]-'0'+r)/10; //记录进位
    }
    while(i>=0)
    {
        c[k++]=(a[i]-'0'+r)%10;
        r=(a[i]-'0'+r)/10;
        i--;
    }
    if(r)
    {
        c[k++]=r;//如果有最终的进位
    }
    //print result
    for(int temp=k-1;temp>=0;temp--)
    {
        if(c[temp]!=0||flag)
        {
            cout<<c[temp];
            flag=true; 
        }
    }
    if(!flag) cout<<0;
}