//**����QQ��
#include<stdio.h>
int main()
{
    int a[101]={0,6,3,1,7,5,8,9,2,4};
    int head,tail;
    head=1,tail=10;
    while(head!=tail)
    {
        printf("%d ",a[head]);
        head++;
        a[tail]=a[head];
        tail++;
        head++;
    }
    printf("\n");
    return 0;
}
