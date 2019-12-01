//**»ØÎÄÊıÅĞ¶Ï
#include<stdio.h>
#include<string.h>
int main()
{
    char s[101],a[101];
    gets(a);
    int len=strlen(a),top,next;
    top=0;
    int mid=len/2-1;
    for(int i=0;i<=mid;i++)
        s[++top]=a[i];
    if(len%2)
        next=mid+2;
    else
        next=mid+1;
    for(int i=next;i<=len-1;i++)
    {
        if(s[top]==a[i])
            top--;
        else
            break;
    }
    if(top)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
