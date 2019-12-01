#include<stdio.h>
const int maxn=101;
int a[maxn];
void quicksort(int left,int right)
{
    int i,j,temp;
    if(left>right)
        return ;
    i=left,j=right;
    temp=a[left];
    while(i!=j)
    {
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        int tt=a[i];
        a[i]=a[j];
        a[j]=tt;
    }
    a[left]=a[i];
    a[i]=temp;
    quicksort(left,i-1);
    quicksort(i+1,right);
    return ;
}
int main()
{
    int n,num=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
    quicksort(1,n);
    for(int i=2;i<=n;i++)
    {
        if(a[i-1]!=a[i])
           num++;
    }
    num++;
    printf("%d\n",num);
    printf("%d ",a[1]);
    for(int i=2;i<=n;i++)
        if(a[i]!=a[i-1])
           printf("%d ",a[i]);
    printf("\n");
    return 0;
}
