#include<stdio.h>
int h[101];//������Ŷѵ�����
int n;
//��������,����������������Ԫ�ص�ֵ
void swap(int x,int y)
{
    int t;
    t=h[x];
    h[x]=h[y];
    h[y]=t;
    return;
}
//���µ�������
void siftdown(int i) //����һ����Ҫ���µ����Ľ����i,���ﴫ��1,���ӶѵĶ��㿪ʼ���µ���
{
    int t,flag=0;//flag��������Ƿ���Ҫ���µ���
    while(i*2<=n&&flag==0)
    {
        if(h[i]>h[i*2])
            t=2*i;
        else
            t=i;
        //��������Ҷ��ӣ��ٶ��Ҷ��ӽ�������
        if(i*2+1<=n)
        {
            if(h[t]>h[i*2+1])
                t=i*2+1;
        }
        if(t!=i)
        {
            swap(t,i);
            i=t;
        }
        else
            flag=1;
    }
    return ;
}
//�����ѵĺ���
void creat()
{
    int i;
    //�����һ����Ҷ��㵽��һ��������ν������µ���
    for(i=n/2;i>=1;i--)
        siftdown(i);
    return;
}
//ɾ������Ԫ��
int deletemax()
{
    int t;
    t=h[1];
    h[1]=h[n];
    n--;
    siftdown(1);
    return t;
}
int main()
{
    int i,num;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
        scanf("%d",&h[i]);
    n=num;

    creat();

    for(i=1;i<=num;i++)
            printf("%d ",deletemax());
    getchar();
    getchar();
    return 0;
}
