//***用快速排序为10个数排序***//
int a[101];
void quicksort(int left,int right)
{
    if(left>right)
        return ;
    int temp=a[left];
    int i=left,j=right;
    while(i!=j)
    {
        while(a[j]>=temp&&j>i)
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
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(1,n);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
