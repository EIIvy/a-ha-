#include<stdio.h>
#include<memory.h>
int a[10],book[10];
int n;
void dfs(int step)
{
    if(step==n+1)
    {
       for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
       printf("\n");
       return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return ;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
       memset(book,0,sizeof(book));
       dfs(1);
    }
    return 0;
}
