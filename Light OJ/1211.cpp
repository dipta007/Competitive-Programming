#include <stdio.h>

int main()
{
    int T,n,x1[100],y1[100],z1[100],x2[100],y2[100],z2[100];
    int i,j,maxx1,maxy1,maxz1,minx2,miny2,minz2,x,y,z,V;
    scanf("%d",&T);
    if(T>100)
        return 0;
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        if(n<1 || n>100)
            return 0;

        for(j=0;j<n;j++)
        {
            scanf("%d %d %d %d %d %d",&x1[j],&y1[j],&z1[j],&x2[j],&y2[j],&z2[j]);
        }

        maxx1=x1[0],maxy1=y1[0],maxz1=z1[0];
        for(j=0;j<n;j++)
        {
            if(x1[j]>=maxx1)
                maxx1=x1[j];
            if(y1[j]>=maxy1)
                maxy1=y1[j];
            if(z1[j]>=maxz1)
                maxz1=z1[j];
        }

        minx2=x2[0],miny2=y2[0],minz2=z2[0];
        for(j=0;j<n;j++)
        {
            if(x2[j]<=minx2)
                minx2=x2[j];
            if(y2[j]<=miny2)
                miny2=y2[j];
            if(z2[j]<=minz2)
                minz2=z2[j];
        }

        x=minx2-maxx1;
        y=miny2-maxy1;
        z=minz2-maxz1;

        if(x>0 && y>0 && z>0)
            printf("Case %d: %d\n",i,x*y*z);
        else
            printf("Case %d: 0\n",i);

    }
    return 0;
}

