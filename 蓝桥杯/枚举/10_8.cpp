#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
//求最大公约数
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n,d;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    d=a[1]-a[0];
    for(int i=2;i<n;i++)
    {
        d=gcd(d,a[i]-a[i-1]);
    }
    if(d==0)
    {
        cout<<n<<endl;
    }else
    {
        cout<<(a[n-1]-a[0])/n+1<<endl;
    }
    
}