#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int h,l;

    while(1)
    {

        scanf("%d",&h);
        if(h==0)
            break;
        scanf("%d",&l);
        vector < vector < int > > bl(l,vector < int > (h));
        int k;
        for(int i=0;i<l;i++)
        {
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                bl[i][j]=1;
            }
        }

        int cnt=0;
        int flg;
        for(int i=0;i<h;i++)
        {
            flg=0;
            for(int j=0;j<l;j++)
            {
                if(bl[j][i]==0 && flg==0)
                {
                    cnt++;
                    flg++;
                }
                else if(bl[j][i]==1 && flg>0)
                {
                    flg=0;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
