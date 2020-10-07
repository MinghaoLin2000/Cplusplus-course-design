#include<iostream>
#include<algorithm>
using namespace std;
bool check(int x);
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(check(i))
        {
            sum+=i;
        }
    }
    cout<<sum<<endl;
}
bool check(int x)
{
    while(x)
    {
        int temp=x%10;
        if(temp==2||temp==0||temp==1||temp==9){
            return true;
        }
        x/=10;
    }
    return false;
}