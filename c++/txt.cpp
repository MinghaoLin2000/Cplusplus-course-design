#include <stdio.h>  
#include <stdint.h>  
#define DELTA 0x9e3779b9  
#define MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (key[(p&3)^e] ^ z)))  
  
void btea(uint32_t *v, int n, uint32_t const key[4])  
{  
    uint32_t y, z, sum;  
    unsigned p, rounds, e;  
    if (n > 1)            /* Coding Part */  
    {  
        rounds = 6 + 52/n;  
        sum = 0;  
        z = v[n-1];  
        do  
        {  
            sum += DELTA;  
            e = (sum >> 2) & 3;  
            for (p=0; p<n-1; p++)  
            {  
                y = v[p+1];  
                z = v[p] += MX;  
            }  
            y = v[0];  
            z = v[n-1] += MX;  
        }  
        while (--rounds);  
    }  
    else if (n < -1)      /* Decoding Part */  
    {  
        n = -n;  
        rounds = 6 + 52/n;  
        sum = rounds*DELTA;  
        y = v[0];  
        do  
        {  
            e = (sum >> 2) & 3;  
            for (p=n-1; p>0; p--)  
            {  
                z = v[p-1];  
                y = v[p] -= MX;  
            }  
            z = v[n-1];  
            y = v[0] -= MX;  
            sum -= DELTA;  
        }  
        while (--rounds);  
    }  
}  
  
  
int main()  
{ 
    uint32_t v[35]={
    0xE74EB323, 0xB7A72836, 0x59CA6FE2, 0x967CC5C1, 0xE7802674, 0x3D2D54E6, 0x8A9D0356, 0x99DCC39C, 
    0x7026D8ED, 0x6A33FDAD, 0xF496550A, 0x5C9C6F9E, 0x1BE5D04C, 0x6723AE17, 0x5270A5C2, 0xAC42130A, 
    0x84BE67B2, 0x705CC779, 0x5C513D98, 0xFB36DA2D, 0x22179645, 0x5CE3529D, 0xD189E1FB, 0xE85BD489, 
    0x73C8D11F, 0x54B5C196, 0xB67CB490, 0x2117E4CA, 0x9DE3F994, 0x2F5AA1AA, 0xA7E801FD, 0xC30D6EAB, 
    0x1BADDC9C, 0x3453B04A, 0x00A406F9
};
    uint32_t const k[4]= {1,2,3,4};  
    int n= 35; //n的绝对值表示v的长度，取正表示加密，取负表示解密  
    // v为要加密的数据是两个32位无符号整数  
    // k为加密解密密钥，为4个32位无符号整数，即密钥长度为128位  
    btea(v,-35, k);  
    printf("解密后的数据：%x %x\n",v[0],v[1]);  
    return 0;  
}  