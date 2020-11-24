#include <iostream>
#include <string.h>
using namespace std;

struct a{
    int a;
    struct a* tmp;
}

unsigned char* RC4(unsigned char* C,unsigned char* key,int keylen,int length)
{
 int S[256];
 int T[256];

 int  count = 0;
count = keylen;

 for(int i = 0; i < 256; i++)
 {
     S[i] = i;
     int tmp = i % count;
     T[i] = key[tmp];
 }

 int j = 0;

 for(int  i = 0; i < 256; i++)
 {
     j = (j + S[i] + T[i]) % 256;
     int tmp;
     tmp = S[j];
     S[j] = S[i];
     S[i] = tmp;
 }
 
 

 int i;
 i=0,j=0;
 
 for(int p = 0; p < length; p++)
 {

    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    int tmp;
    tmp = S[j];
    S[j] = S[i];
    S[i] = tmp;
    
    int k = S[(S[i] + S[j]) % 256];
    C[p]=C[p]^k;
 }
 
 return C;
}


int main()
{

    unsigned char A[1000] = { 0x99,0x65,0xF4,0x48,0x66,0x3B,0x49,0x8B};
    unsigned char key[256] = "flag";
    size_t  count = 0;
    count = strlen((char*)A);
	

    unsigned char* B = RC4(A,key,4,8);
    for(int i=0;i<8;i++)
		printf("0x%02X,",B[i]);
    

	system("pause");
    return 0;
}