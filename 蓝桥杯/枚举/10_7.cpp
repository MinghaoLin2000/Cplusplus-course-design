#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int main()
{
    int n;//二叉树总节点数
    cin>>n;
    LL maxsum=INT_MIN;
    LL maxIndex=1;
    for(int i=0,length=1,depth=1;i<n;depth++,length*=2)
    {
        LL tempsum=0;
        int t;
        for(int j=1;j<=length&&i<n;j++,i++) //这里注意一个细节i<N，因为这里不一定是满二叉树
        {
            cin>>t;
            tempsum+=t;
        }
        if(tempsum>maxsum)
        {
            maxsum=tempsum;
            maxIndex=length;
        }
    }
    cout<<maxIndex<<endl;
    
}