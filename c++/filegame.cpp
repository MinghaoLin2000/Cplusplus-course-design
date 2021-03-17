#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
typedef long long int ll;

const int maxn=(1<<16)-1;
const int inf=0x3f3f3f3f;

queue<int> que;
int vis[maxn+10];
int step;
int change(unsigned int x,int i,int j)
{
    int k;
    k=(1<<(i*4+j));
    x^=k;
    if(i-1>=0)
    {
        k=(1<<(4*(i-1)+j));
        x^=k;
    }
    if(i+1<4)
    {
        k=(1<<(4*(i+1)+j));
        x^=k;
    }
    if(j+1<4)
    {
        k=(1<<(4*i+j+1));
        x^=k;
    }
    if(j-1>=0)
    {
        k=(1<<(4*i+j-1));
        x^=k;
    }
    return x;
}
int bfs(int state)
{
    
    while(!que.empty()) que.pop();
    que.push(state);
    while(!que.empty())
    {
        int t=que.size();
        que.pop();
        for(int i=0;i<t;i++)
        {
            int temp=que.front();
            if(temp==0||temp==maxn||step>16)
            {
                return step;
            }
            for(int x=0;x<16;x++)
            {
                for(int y=0;y<16;y++)
                {
                    int w=change(temp,x,y);
                    if(!vis[w])
                    que.push(w);

                }
            }
        }
        step++;

    }
    return step;
}
int main()
{
    int state=0;
    char s[10];
    int k=0;
    for(int i=0; i<4; i++)
    {
        scanf("%s",s);
        for(int j=0; j<4; j++)
        {
            if(s[j]=='b')
                state+=(1<<k);
            k++;
        }
    }
    int ans=bfs(state);
    if(ans>16) printf("Impossible\n");
    else printf("%d\n",ans);

    return 0;
}