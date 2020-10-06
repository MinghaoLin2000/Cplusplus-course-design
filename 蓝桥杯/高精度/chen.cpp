#include<iostream>
#include<algorithm>
using namespace std;
string a,b;
int k;
int c[10000001];
int main()
{
    cin>>a>>b;
    reverse(a.begin(),b.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            c[i+j]+=(a[i]-'0')*(b[i]-'0');
        }
    }
    for(k=0;k<=a.size()+b.size();k++)
    {
        c[k]+=c[k-1]/10,c[k-1]%=10;
    }
    while(!c[k]&&k>=1)
    {
        k--;
    }
    for(;k>=0;k--)
    {
        cout<<c[k];
    }
    return 0;
}