#include<stdio.h>
int a[10]={6,2,5,5,4,5,6,3,7,6};
int fun(int x)
{
    int num=0;
    while(x/10!=0)
    {
        num+=a[x%10];
        x=x/10;
    }
    num+=a[x];
    return num;
}
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=0;i<1111;i++)
   {
       for(int j=0;j<1111;j++)
       {
           int k=i+j;
           if(fun(i)+fun(j)+fun(k)==n-4)
              printf("%d+%d=%d\n",i,j,k);
       }
   }
   return 0;
}
