#include<iostream>
#include<algorithm>
using namespace std;
bool check(int x,int y,int z)
{
    while(x)
    {
        int temp=x%10;
        if(temp==2||temp==4)
        {
            return false;
        }
        x/=10;
    }
    while(y)
    {
        int temp=y%10;
        if(temp==2||temp==4)
        {
            return false;
        }
        y/=10;
    }
    while(z)
    {
        int temp=z%10;
        if(temp==2||temp==4)
        {
            return false;
        }
        z/=10;
    }
    return true;
}
int main()
{
    int count=0;
    for(int i=1;i<2019;i++)
    {
        for(int j=1;j<2019;j++)
        {
            if(i==j) continue;
            for(int k=1;k<2019;k++)
            {
                if(i==k||j==k) continue;
                if((i+j+k)==2019&&check(i,j,k))
                {
                    count++;
                }
            }
        }
    }
    cout<<count/6<<endl;
    return 0;

}