/*加密前原始数据：1 2  
加密后的数据：1347371722 925494771  
解密后的数据：1 2  
  
Process returned 0 (0x0)   execution time : 0.020 s  
Press any key to continue.  

XTEA是TEA的升级版，增加了更多的密钥表，移位和异或操作等等，设计者是Roger Needham, David Wheeler
加密过程：



算法实现：

示例代码：

[cpp] view plain copy
*/
#include <stdio.h>  
#include <stdint.h>  
  
/* take 64 bits of data in v[0] and v[1] and 128 bits of key[0] - key[3] */  
  
void encipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {  
    unsigned int i;  
    uint32_t v0=v[0], v1=v[1], sum=0, delta=0x9E3779B9;  
    for (i=0; i < num_rounds; i++) {  
        v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);  
        sum += delta;  
        v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);  
    }  
    v[0]=v0; v[1]=v1;  
}  
  
void decipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {  
    unsigned int i;  
    uint32_t v0=v[0], v1=v[1], delta=0x9E3779B9, sum=0xC6EF3720;  
    for (i=0; i < num_rounds; i++) {  
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);  
        sum -= delta;  
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);  
    }  
    v[0]=v0; v[1]=v1;  
}  
  
int main()  
{  
    uint32_t v[2]={0xEACFC7F0,0x62A5E511};  
    uint32_t const k[4]={0xF0,0xC7,0xCF,0xEA};  
    unsigned int r=32;//num_rounds建议取值为32  
    // v为要加密的数据是两个32位无符号整数  
    // k为加密解密密钥，为4个32位无符号整数，即密钥长度为128位  
    printf("加密前原始数据：%u %u\n",v[0],v[1]);  
    //encipher(r, v, k);  
    //printf("加密后的数据：%u %u\n",v[0],v[1]);  
    decipher(r, v, k);  
    printf("解密后的数据：%u %u\n",v[0],v[1]);  
    return 0;  
}  