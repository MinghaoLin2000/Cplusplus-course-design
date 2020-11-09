#include<stdio.h>
void base64(char* b);
int main()
{
    char a[100];
    printf("input the flag!!!!\n");
    scanf("%s",a);
    if(strlen(a)!=22)
    {
        printf("error flag1!");
        return;
    }else if(a[15]!='p')
    {
        printf("error flag2!");
        return;
    }else if(a[17]!='i')
    {
        printf("error flag3!");
        return; 
    }else
    {
        base64(a);
    }
    


}