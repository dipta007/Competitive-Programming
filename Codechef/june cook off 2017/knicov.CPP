#include <stdio.h>
#include <string.h>
int main()
{
    int q,i,j,flag,cont,k,flag1;
    char s[2004];
    scanf("%d",&q);
    getchar();
    for(i=1;i<=q;i++)
    {
        cont=0;
        scanf("%s",&s);
        getchar();
        for(j=0;j<strlen(s);j++)
        {
            if(j==strlen(s)-1)
                break;
            else if(s[j]=='1')
            {
                for(k=j+1,flag=0,flag1=0;k<strlen(s);k++)
                {
                    if(s[k]=='0')
                    {
                        flag1++;
                        continue;
                    }
                    else if(s[k]=='1')
                        break;
                    else
                        flag++;
                }
                if(flag==0 && flag1!=0)
                    cont++;
            }
        }
        printf("%d\n",cont);
    }
}

