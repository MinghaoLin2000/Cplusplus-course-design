#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include "defs.h"
// #include <setimp.h>
uint16_t wa[] = {48885, 35772, 41193, 29456, 55568, 41901, 52406, 19934, 13388, 15318, 26385, 34447, 7290, 33829, 27405, 6988};
int32_t d_40212c[]={-1,0,0,0,1};
int32_t d_402140[]={0,0,-1,1,0};
int toHex(uint32_t t)
{
    if(t<=9)return t+'0';
    else return t+55;
}

void dfs(uint16_t *state,size_t v4,size_t v5,char *flag)
{
    if(v4==16)
    {
        if(v5>=1&&state[v5-1]!=0xffff)
        {
            return;
        }
        v5+=1;
        v4=0;
    }
    if(v5==16)
    {
        if(state[v4-1]==0xffff){
            printf("%d %s\n",strlen(flag),flag);
            return;
        }
    }
    if(strlen(flag)>214) return;
    uint16_t* nstate=(uint16_t*)alloca(sizeof(wa));
    memcpy(nstate,state,sizeof(wa));
    uint32_t v12,v13;
    for(int i=0;i<5;i++)
    {
        {
          v12 = v4 + d_40212c[i];
          v13 = v5 + d_402140[i];
          if ( v12 <= 0xF && v13 <= 0xF )
            nstate[v13] ^= 1 << (15 - v12);
    }
    size_t len=strlen(flag);
    uint16_t * nnstate=(uint16_t*)alloca(sizeof(wa));
    char *nnflag=(char*)alloca(len+1);
    memcpy(nnflag,flag,len+1);
    memcpy(nnstate,state,sizeof(wa));
    dfs(nnstate,v4+1,v5,nnflag);
    char *nflag=(char*)alloca(len+3);
    nflag[len]=v4;
    nflag[len+1]=v5;
    nflag[len+2]=0;
    dfs(nstate,v4+1,v5,nflag);


}