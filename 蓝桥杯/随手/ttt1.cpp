#include<stdio.h>
int main()
{
    int len=32;
    int v5;
    int v6;
    int v7;
    char v8;
    int v9;
    char v10;
    bool v11;
    char v13;
    char v14;
    char j;
    unsigned long long i=0;
    char a[0x30]={0};
    char res[]="AC6297BD8C53021894A5EADEA1FD9E8A0F0C7845A199FF1C0D8F970DB02B6802";
    int v4=0;
    do{
        for(j=0;j<=0xff;j++)
        {
            v5=j;
            if(j<0)
            {
                v5=128-v5;
            }
            v6=v5+15;
            if(v5>=0)
            v6=v5;
            v7=v6>>4;
            v8=v7+55;
            v9=v5%16;
            v10=v7+48;
            v11=v7<10;
            v13=v9+48;
            if(!v11)
            {
                v10=v8;
            }
            if(v10!=res[2*i])
            {
                continue;
            }
            v14=v9+55;
            v11=v9<10;
            if(v11)
            {
                v14=v13;
            }
            if(v14==res[2*i+1])
            {
                a[i]=j;
                printf("%02hhx",j);
                i++;
                break;
            }

        }
    }while(i<len);
    


}