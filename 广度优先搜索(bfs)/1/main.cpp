#include<stdio.h>
struct node
{
    int x;
    int y;
    int f;
    int s;
};
int main()
{
    struct node que[2501];

    int a[51][51]={0},book[51][51]={0};
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int head,tail;
    int n,m,startx,starty,p,q,tx,ty,flag;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           scanf("%d",&a[i][j]);
    scanf("%d%d%d%d",&startx,&starty,&p,&q);
    head=1,tail=1;
    que[tail].x=startx;
    que[tail].y=starty;
    que[tail].f=head;
    que[tail].s=0;
    tail++;
    book[startx][starty]=1;
    flag=0;
    while(head<tail)
    {
        for(int j=0;j<=3;j++)
        {
            tx=que[head].x+next[j][0];
            ty=que[head].y+next[j][1];
            if(tx<1||ty<1||tx>n||ty>m)
                continue;
            if(a[tx][ty]==0&&book[tx][ty]==0)
            {
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].f=head;
                que[tail].s=que[head].s+1;
                tail++;
            }
            if(tx==p&&ty==q)
            {
               flag=1;
               break;
            }
        }
        if(flag)
            break;
        head++;
    }
    printf("%d\n",que[tail-1].s);
    return 0;

}
