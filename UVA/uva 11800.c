#include <stdio.h>
#include <math.h>

int main()
{
    int T,i,ax,ay,bx,by,cx,cy,dx,dy,A,B,C,D,O,Os;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);

        A=sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
        B=sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by));
        C=sqrt((dx-cx)*(dx-cx)+(dy-cy)*(dy-cy));
        D=sqrt((ax-dx)*(ax-dx)+(ay-dy)*(ay-dy));

        O=sqrt((bx-dx)*(bx-dx)+(by-dy)*(by-dy));

        Os=O*O;

        if(A==B && B==C && C==D && D==A && Os==A*A+B*B)
            printf("Case %d: Square\n",i);
    }
}
