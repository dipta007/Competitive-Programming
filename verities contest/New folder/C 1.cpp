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
                if(a[r][c]==1)
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
                for(int i=0;i<n;i++)
                {
                    if(a[l][i]==0)
                    {
                        b[l][1]++;
                    }
                    else
                    {
                        b[l][1]--;
                    }
                }

            }
            else if(k==2)
            {
                int l;
                scanf("%d",&l);
                l=l-1;
                for(int i=0;i<n;i++)
                {
                    if(a[i][l]==0)
                    {
                        b[i][1]++;
                    }
                    else
                    {
                        b[i][1]--;
                    }
                }
            }
            else if(k==3)
            {
                int sum=0;
                if(q==0)
                {
                    for(int i=0;i<n;i++)
                    cout << b[i][1] <<" ";
                }
                for(int i=0;i<n;i++)
                {
                    sum=sum+b[i][1];
                }
                cout << sum << endl;
                re[rt++]=(sum%2)+48;
                if(q==0)
                    re[rt]='\0';


            }
        }
        for(int i=0;i<rt;i++)
            printf("%c",re[i]);
        printf("\n");
    }
}

