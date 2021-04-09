#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
void decipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {  
    unsigned int i;  
    uint32_t v0=v[0], v1=v[1], delta=0x12345678, sum=delta*num_rounds;  
    for (i=0; i < num_rounds; i++) {  
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);  
        sum -= delta;  
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);  
    }  
    v[0]=v0; v[1]=v1;  
}  
uint32_t const keys[4]={0x00010203,0x04050607,0x08090A0B,0x0C0D0E0F};
void cipher_fuck(unsigned int *c_1,unsigned int *c_2)
{
    unsigned int flow_num=0;
    unsigned int a,b;
    unsigned c1=*c_1,c2=*c_2;
    unsigned int flow[40];
    for(int i=0;i<33;i++)
    {
        flow[i]=flow_num;
        flow_num+=0x12345678;
    }
    for(int i=32;i>0;i--)
    {
        a=c2;
        b=c1;
        c1=b-((a+((a>>5)^(a<<4)))^(flow[i]+keys[(flow[i]>>11)%4]));
        c2=a-((c1+((c1>>5)^(c1<<4)))^(flow[i-1]+keys[flow[i-1]%4]));
    }
    *c_1=c1;
    *c_2=c2;
}
int main()
{

uint32_t v[]={0x0EB7A306,0x423A8EB5,0x3BFC49CD,0x39B11F55};  
    uint32_t const k[4]={0x00010203,0x04050607,0x08090A0B,0x0C0D0E0F};  
    unsigned int r=32;//num_rounds建议取值为32  
   // cipher_fuck(&v[0],&v[1]);
    //cipher_fuck(&v[2],&v[3]);
    //printf("解密后的数据：%u %u\n",v[0],v[1]); 
    //printf("解密后的数据：%u %u\n",v[2],v[3]); 
    // v为要加密的数据是两个32位无符号整数  
    // k为加密解密密钥，为4个32位无符号整数，即密钥长度为128位  
    //printf("加密前原始数据：%u %u\n",v[0],v[1]);  
    //encipher(r, v, k);  
    //printf("加密后的数据：%u %u\n",v[0],v[1]);  
    decipher(r, v, k);  
    printf("解密后的数据：%u %u\n",v[0],v[1]);  
    decipher(r,&v[2],k);
    printf("解密后的数据：%u %u\n",v[2],v[3]); 
    return 0;  
}