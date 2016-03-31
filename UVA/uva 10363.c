#include <stdio.h>

int main()
{
    int N,i,r,c,c_x,c_o;
    char a[4][4];
    scanf("%d ",&N);
    for(i=1;i<=N;i++)
    {
        c_x=0;
        c_o=0;
        for(r=0;r<3;r++)
        {
            for(c=0;c<3;c++)
            {
                scanf(" %c",&a[r][c]);
                if(a[r][c]=='X')
                    c_x++;
                else if(a[r][c]=='O')
                    c_o++;
            }
        }
        if(c_x>=c_o)
            printf("yes\n\n");
        else
            printf("no\n\n");

    }
}
