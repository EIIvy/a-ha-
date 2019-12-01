//此链表有点缺陷

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
int main()
{
    NODE *head,*tail,*pnew,*t,*p,*q;
    int score;
    head=(NODE*)malloc(sizeof(NODE));
    if(head==NULL)
    {
        printf("no enough memory\n");
        return 0;
    }
    head->next=NULL;
    tail=head;

    printf("Please input the scores of students:\n");
    while(1)                                  //链表的创建
    {
        scanf("%d",&score);
        if(score<0)
            break;
        pnew=(NODE*)malloc(sizeof(NODE));
        if(pnew==NULL)
        {
            printf("no enough memory\n");
            return 0;
        }
        pnew->data=score;
        pnew->next=NULL;

        tail->next=pnew;
        tail=pnew;
    }
    scanf("%d",&score);    //数据的插入
    t=head;
    while(t!=NULL)
    {
        if(t->next==NULL||t->next->data>score)
        {
           p=(NODE*)malloc(sizeof(NODE));
           p->data=score;
           p->next=t->next;
           t->next=p;
           break;
        }
        t=t->next;
    }
    t=head->next;                    //数据的输出
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    scanf("%d",&score);
    t=head;                         //特定数据的销毁
    while(t->next!=NULL&&t->data!=score)
        t=t->next;
    q=t->next;
    t->next=q->next;
    free(q);
    t=head->next;                    //数据的输出
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    t=head;    //链表的销毁
    while(t->next!=NULL)
    {
        q=t->next;
        t->next=q->next;
        free(q);
    }
    free(head);
    return 0;
}
