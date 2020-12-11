#include<iostream>
int sub_CF38D028(unsigned int a1, unsigned int a2)
{
  signed int v2; // r12
  unsigned int v3; // r3
  int v4; // r2
  int result; // r0

  v2 = a1 ^ a2;
  v3 = 1;
  v4 = 0;
  if ( (a2 & 0x80000000) != 0 )
    a2 = -a2;
  if ( (a1 & 0x80000000) != 0 )
    a1 = -a1;
  if ( a1 >= a2 )
  {
    while ( a2 < 0x10000000 && a2 < a1 )
    {
      a2 *= 16;
      v3 *= 16;
    }
    while ( a2 < 0x80000000 && a2 < a1 )
    {
      a2 *= 2;
      v3 *= 2;
    }
    while ( 1 )
    {
      if ( a1 >= a2 )
      {
        a1 -= a2;
        v4 |= v3;
      }
      if ( a1 >= a2 >> 1 )
      {
        a1 -= a2 >> 1;
        v4 |= v3 >> 1;
      }
      if ( a1 >= a2 >> 2 )
      {
        a1 -= a2 >> 2;
        v4 |= v3 >> 2;
      }
      if ( a1 >= a2 >> 3 )
      {
        a1 -= a2 >> 3;
        v4 |= v3 >> 3;
      }
      if ( !a1 )
        break;
      v3 >>= 4;
      if ( !v3 )
        break;
      a2 >>= 4;
    }
  }
  result = v4;
  if ( v2 < 0 )
    result = -v4;
  return result;
};
int main()
{
    int a[]={0x4B,0x75,0x40,0x27,0x47,0x5F,0x56,0x39,0x76,0x28,0x79,0x47,0x53};
    char b[]="Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;";
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<0xff;j++)
        {
            printf("第%d次\n",i);
            printf("%d",sub_CF38D028(j+b[i]-64,93));
            if(a[i]==sub_CF38D028(j+b[i]-64,93))
            {
                printf("%d\n",j);

            }
        }
    }
}