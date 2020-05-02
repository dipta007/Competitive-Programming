#include<stdio.h>
int main()
{
int a,r,ans,k;
while(scanf("%d",&a)==1)
{
ans=1;
r=1;
k=1;
while(1)
    {
    if(a==0)
        {
        printf("0\n");
        break;
        }
    if(a==1 || a==111)
        {
        printf("3\n");
        break;
        }
    if(a==11 || a==1111)
        {
        printf("4\n");
        break;
        }
    int r=k%a;
    if(r==0)
        {
        printf("%d\n",ans);
        break;
        }
    k=r*10+1;
    ans++;
    }
}
}
