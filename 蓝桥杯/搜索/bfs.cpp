#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
bool vis[5][5]; //判断是否走过
int map[5][5]; //需要一张地图
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0}; //记录坐标的
struct Node{
    int x;
    int y;
    int s;
    int l[100];
};
//check 是否可走
bool check(int x,int y)
{
    if(x<0||x>=5||y<0||y>5) return true;
    if(vis[x][y]) return true;
    if(map[x][y]==1) return true;
    return false;
}
Node bfs()
{
    queue<Node> q;
    Node cur,next; //当前节点和下一个节点
    cur.x=0;
    cur.y=0;
    cur.s=0;
    vis[cur.x][cur.y]=true;
    q.push(cur);
    while (!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.x==4&&cur.y==4) //到达终点
        {
            return cur;
        }
        int i,nx,ny;
        for(int i=0;i<4;i++)
        {
            nx=cur.x+dx[i];
            ny=cur.y+dy[i];
            if(check(nx,ny)) continue;
            vis[nx][ny]=true;
            next=cur;
            next.x=nx;
            next.y=ny;
            next.s=cur.s+1;
            next.l[cur.s]=i;  //保存到达的路径
            q.push(next); 
        }
    }
    
}
int main()
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    memset(vis,0,sizeof(vis));
    Node ans=bfs();
    int x,y;
    x=0,y=0;
    for(i=0;i<ans.s;i++)
    {
        printf("(%d %d)\n",x,y);
        x+=dx[ans.l[i]];
        y+=dy[ans.l[i]];

    }
    return 0;
}