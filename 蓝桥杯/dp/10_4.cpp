#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod =1e4;
ll dp[20190325];
int main(){
    dp[1]=dp[2]=dp[3]=1;
    for(int i=4;i<=20190324;i++){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;
    }
    cout<<dp[20190324]<<endl;
    return 0;
}