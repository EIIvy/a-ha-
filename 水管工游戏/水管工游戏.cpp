#include<stdio.h>
int a[51][51];
int book[51][51],n,m,flag=0;
struct note //Ϊ�����·��
{
    int x;
    int y;
}s[100];
int top=0;
void dfs(int x,int y,int frontt) //x��y��ʾ��ǰ������ӵ����꣬front��ʾ��ˮ�ڷ���
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
    //ֱ�ܵĴ�����
    top++;
    s[top].x=x;
    s[top].y=y;
    if(a[x][y]>=5&&a[x][y]<=6)
    {
        if(frontt==1) //��ˮ������ߵ����
            dfs(x,y+1,1);
        if(frontt==2) //��ˮ������������
            dfs(x+1,y,2);
        if(frontt==3) //��ˮ�����ұߵ����
            dfs(x,y-1,3);
        if(frontt==4) //��ˮ�����±��������
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
    //������Ϸ��ͼ
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


