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
    int T,cd,cm,cy,bd,bm,by;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d/%d/%d",&cd,&cm,&cy);
        scanf("%d/%d/%d",&bd,&bm,&by);

        int p=0;
        if(cy>by)
            p=1;
        else if(cy==by)
        {
            if(cm>bm)
                p=1;
            else if(cm==bm)
            {
                if(cd>=bd)
                    p=1;
            }
        }
        if(p==0)
            printf("Case #%d: Invalid birth date\n",i);
        else if(p==1)
        {
            int re;
            if(cm>bm)
                re=cy-by;
            else if(cm==bm)
            {
                if(cd>=bd)
                    re=cy-by;
                else
                    re=cy-by-1;
            }
            else
                re=cy-by-1;

            if(re>130)
                printf("Case #%d: Check birth date\n",i);
            else
                printf("Case #%d: %d\n",i,re);

        }
    }
}
