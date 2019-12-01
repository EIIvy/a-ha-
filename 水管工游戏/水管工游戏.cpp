#include<stdio.h>
int a[51][51];
int book[51][51],n,m,flag=0;
struct note //为了输出路径
{
    int x;
    int y;
}s[100];
int top=0;
void dfs(int x,int y,int frontt) //x和y表示当前处理格子的坐标，front表示进水口方向
{
    if(x==n&&y==m+1)
    {
        flag=1;
        for(int i=1;i<=top;i++)
            printf(" (%d,%d) ",s[i].x,s[i].y);
        return;
    }
    if(x<1||x>n||y<1||y>m)
        return ;
    if(book[x][y]==1)
        return ;
    book[x][y]=1;
    //直管的处理方法
    top++;
    s[top].x=x;
    s[top].y=y;
    if(a[x][y]>=5&&a[x][y]<=6)
    {
        if(frontt==1) //进水口在左边的情况
            dfs(x,y+1,1);
        if(frontt==2) //进水口在上面的情况
            dfs(x+1,y,2);
        if(frontt==3) //进水口在右边的情况
            dfs(x,y-1,3);
        if(frontt==4) //进水口在下边这种情况
            dfs(x-1,y,4);
    }
    if(a[x][y]>=1&&a[x][y]<=4)
    {
        if(frontt==1)
        {
            dfs(x+1,y,2);
            dfs(x-1,y,4);
        }
        if(frontt==2)
        {
            dfs(x,y-1,3);
            dfs(x,y+1,1);
        }
        if(frontt==3)
        {
            dfs(x+1,y,2);
            dfs(x-1,y,4);
        }
        if(frontt==4)
        {
            dfs(x,y+1,1);
            dfs(x,y-1,3);
        }
    }
    book[x][y]=0;
    top--;
    return;
}
int main()
{
    int num=0;
    scanf("%d %d",&n,&m);
    //读入游戏地图
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
             scanf("%d",&a[i][j]);
    dfs(1,1,1);
    if(flag==0)
        printf("impossible\n");
    getchar();
    getchar();
    return 0;
}


