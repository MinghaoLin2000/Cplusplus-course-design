
#include <stdio.h>
int main(){
    long long result; // rax
    unsigned long long i; // rdi
    char j;
    int tmp; // edx
    int t2; // ecx
    int t7; // ecx
    char v8; // r9
    int v9; // edx
    char v10; // r8
    bool v11; // cc
    char v12; // cl
    char v13; // dl
    char a[0x30] = {0};
    char res[] =
"AC6297BD8C53021894A5EADEA1FD9E8A0F0C7845A199FF1C0D8F970DB02B6802";
    result = 0x20;
    if(result){
        i = 0LL;
        do{
            for(j = 0; j <= 0xff; ++j){
                tmp = j;
                if(j < 0)
                    tmp = 0x80 - tmp;
                t2 = tmp + 15;
                if(tmp >= 0)
                    t2 = tmp;
                t7 = t2 >> 4;
                v8 = t7 + 0x37;
                v9 = tmp % 16;
                v10 = t7 + 0x30;
                v11 = t7 < 10;
                v12 = v9 + 0x30;
                if(!v11)
                    v10 = v8;
                v11 = v9 < 0xA;
                if(res[2 * i] != v10){
                    continue;
                }
                v13 = v9 + 0x37;
                if(v11)
                    v13 = v12;
                if(res[2 * i + 1] == v13){
                    a[i] = j;
                    printf("%02hhx", j);
                    i++;
                    break;
                }
            }
        } while(i < result);
    }
    return 0;
}