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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int N,P;
        scanf("%d %d",&N,&P);
        int p[P];
        for(int i=0;i<P;i++)
            scanf("%d",&p[i]);
        bool cnt[N+1];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<P;i++)
        {
            for(int j=p[i];j<=N;j=j+p[i])
            {
                if(j%7==0)
                    continue;
                cnt[j]=1;
            }
        }
        int c=0;
        int fr=6;
        for(int i=1;i<=N;i++)
        {
            if(i%fr==0)
            {
                fr=fr+7;
                continue;
            }
            if(cnt[i]>0)
                c++;
        }
        printf("%d\n",c);
    }
}
