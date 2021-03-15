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
void printArray(const char *name,uint8_t *v,size_t len) 
{
    printf("========%s=========\n",name);
    for(size_t i=0;i<len;i++){
        printf("0x%02X,",v[i]);
    }
    printf("\n=================\n");
}
char toHex(uint32_t a){
    if(a<=9)return a+'0';
    else return a+55;
}
void dfs(uint16_t *state,size_t start,size_t i,char *flag){
    if(i==16){
        if(start>=1&&state[start-1]!=0xffff){
            return;
        }
        start+=1;
        i=0;
    }
    if(start==16){
        if(state[start-1]==0xffff){
            printf("%ld: %s\n",strlen(flag),flag);
            fflush(stdout);
            exit(0);
        }
        return;
    }
    if(strlen(flag)>214)return;
    uint16_t *nstate = (uint16_t*)alloca(sizeof(wa));
    memcpy(nstate,state,sizeof(wa));
    uint32_t v12,v13;
    for(size_t j=0;j<5;j++){
        v12=d_40212c[j]+i;
        v13=d_402140[j]+start;
        if(v12<=0xf&&v13<=0xf){
            nstate[v13]^=1<<(15-v12);
        }
    }
    size_t len = strlen(flag);
    // 优先寻找步数少的。。
    uint16_t *nnstate=(uint16_t*)alloca(sizeof(wa));
    char *nnflag = (char*)alloca(len+1);
    memcpy(nnflag,flag,len+1);
    memcpy(nnstate,state,sizeof(wa));
    dfs(nnstate,start,i+1,nnflag);

    char *nflag=(char*)alloca(len+3);
    memcpy(nflag,flag,len+1);
    nflag[len]=toHex(i);
    nflag[len+1]=toHex(start);
    nflag[len+2]=0;
    dfs(nstate,start,i+1,nflag);
}
int main(){
    char flag[]="";
    dfs(wa,0,0,flag);
    return 0;
}