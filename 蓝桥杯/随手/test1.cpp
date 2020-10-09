#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string a;
    string res;
    cin>>a;
    int counta[200]={0};
    for(int i=0;i<a.length();i++)
    {
        counta[a[i]-0]++;
        if(a[i]==' '||counta[a[i]-0]==1||counta[a[i]-0]==3||counta[a[i]-0]==6)
        {
            res+=a[i];
        }
    }
    cout<<res<<endl;
}