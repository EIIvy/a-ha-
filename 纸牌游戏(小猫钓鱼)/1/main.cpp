//纸牌游戏
#include<stdio.h>
#include<memory.h>
struct queue
{
    int data[1000];
    int head;
    int tail;
};
struct stack
{
    int data[10];
    int top;
}s;
int main()
{
    struct queue q1,q2;
    q1.head=1,q1.tail=1,q2.head=1,q2.tail=1;
    s.top=0;
    int book[10];
    memset(book,0,sizeof(book));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) // 输入小哼的数据
    {
       scanf("%d",&q1.data[q1.tail]);
       q1.tail++;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&q2.data[q2.tail]);
        q2.tail++;
    }
    while(q1.head<q1.tail&&q2.head<q2.tail)
    {
        int t=q1.data[q1.head];
        if(book[t]==0)
        {
           q1.head++;
           s.top++;
           s.data[s.top]=t;
           book[t]=1;
        }
        else
        {
           q1.head++;   //小哼的牌已出,应该从队列中去除
           q1.data[q1.tail]=t;//将重的牌放到后面
           q1.tail++;
           while(s.data[s.top]!=t)
           {
               q1.data[q1.tail]=s.data[s.top];
               q1.tail++;
               book[s.data[s.top]]=0;
               s.top--;
           }
           q1.data[q1.tail]=s.data[s.top];
           book[s.data[s.top]]=0;
           q1.tail++;
           s.top--;
        }
        if(q1.head==q1.tail)
            break;
        int h=q2.data[q2.head];
        if(book[h]==0)
        {
           q2.head++;
           s.top++;
           s.data[s.top]=h;
           book[h]=1;
        }
        else
        {
           q2.head++;   //小哈的牌已出,应该从队列中去除
           q2.data[q2.tail]=h;//将重的牌放到后面
           q2.tail++;
           while(s.data[s.top]!=h)
           {
               q2.data[q2.tail]=s.data[s.top];
               q2.tail++;
               book[s.data[s.top]]=0;
               s.top--;
           }
           q2.data[q2.tail]=s.data[s.top];
           book[s.data[s.top]]=0;
           q2.tail++;
           s.top--;
        }
    }
    if(q1.head==q1.tail)
    {
        printf("小哈win\n");
        printf("小哈剩余的牌为:\n");
        while(q2.head!=q2.tail)
        {
            printf("%d ",q2.data[q2.head]);
            q2.head++;
        }
        printf("\n栈里剩余的牌为:\n");
        if(s.top==0)
            printf("栈里无牌\n");
        else
        {
              for(int i=1;i<=s.top;i++)
                    printf("%d ",s.data[i]);
        }
    }
    else
    {
        printf("小哼win\n");
        printf("小哼剩余的牌为:\n");
        while(q1.head!=q1.tail)
        {
            printf("%d ",q1.data[q1.head]);
            q1.head++;
        }
        printf("\n栈里剩余的牌为:\n");
        if(s.top==0)
            printf("栈里无牌\n");
        else
            {
                for(int i=1;i<=s.top;i++)
                    printf("%d ",s.data[i]);

            }
    }
    return 0;
}
