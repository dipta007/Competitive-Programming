#include <stdio.h>
int sort(int a[]);
int a[4];
int main()
{
    int T,i,l,p,x;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
        for(x=1;a[3]!=0;x++)
        {
            l=sort(a);
            a[l]++;
            a[3]--;
        }
        p=sort(a);
        printf("Case %d: %d\n",i,a[p]);
    }
}

int sort(int a[])
{
    if(a[0]<=a[1] && a[0]<=a[2])
        return 0;
    else if(a[1]<=a[0] && a[1]<=a[2])
        return 1;
    else if(a[2]<=a[1] && a[2]<=a[0])
        return 2;

}
