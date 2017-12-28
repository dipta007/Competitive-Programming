#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
        string re;
        int a[n][n];
        int b[n][2];
        memset(b,0,sizeof(b));
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                scanf("%d",&a[r][c]);
                if(a[r][c]==0)
                    b[r][0]++;
                else
                    b[r][1]++;
            }
        }
        int q;
        scanf("%d",&q);
        int rt=0;
        while(q--)
        {
            int k;
            scanf("%d",&k);
            if(k==1)
            {
                int l;
                scanf("%d",&l);
                l=l-1;
                temp=a[l][0];
                a[l][0]=a[l][1];
                a[l][1]=temp;
            }
            else if(k==2)
            {
                int l;
                scanf("%d",&l);
                l=l-1;
                for(int i=0;i<n;i++)
                {
                    a[i][l]=!a[i][l];
                }
            }
            else if(k==3)
            {
                int sum=0;
                int r=0,c=0;
                for(int i=0;i<n;i++)
                {

                    for(int j=0;j<n;j++)
                    {
                        sum=sum+a[r][j]*a[j][c];
                    }
                    r++;
                    c++;
                }
                re[rt++]=(sum&1)+48;
                if(q==0)
                    re[rt]='\0';


            }
        }
        for(int i=0;i<rt;i++)
            printf("%c",re[i]);
        printf("\n");
    }
}
