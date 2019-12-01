#include<stdio.h>
#include<memory.h>
int n,m,p,q,minn=99999999;
int a[51][51],book[51][51];
void bfs(int x,int y,int step)
{
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int tx,ty;
    if(x==p&&y==q)
    {
        if(step<minn)
           minn=step;
        return ;
    }
    for(int i=0;i<=3;i++)
    {
        tx=x+next[i][0];
        ty=y+next[i][1];
        if(tx<1||ty<1||tx>n||ty>m)
            continue;
        if(a[tx][ty]==0&&book[tx][ty]==0)
        {
            book[tx][ty]=1;
            bfs(tx,ty,step+1);
            book[tx][ty]=0;
        }
    }
    return ;
}
int main()
{
    memset(book,0,sizeof(book));
    int startx,starty;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          scanf("%d",&a[i][j]);
    scanf("%d%d%d%d",&startx,&starty,&p,&q);
    book[startx][starty]=1;
    bfs(startx,starty,0);
    printf("%d\n",minn);
    return 0;
}
