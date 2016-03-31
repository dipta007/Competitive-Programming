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
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int N,w=0,b=0,t=0,a=0;
        scanf("%d ",&N);
        char an[N];
        scanf("%s",an);
        int k=strlen(an);
        for(int j=0;j<k;j++)
        {
            if(an[j]=='B')
                b++;
            else if(an[j]=='W')
                w++;
            else if(an[j]=='T')
                t++;
            else if(an[j]=='A')
                a++;
        }
        if(a==N)
            printf("Case %d: ABANDONED\n",i);
        else if(w==N-a)
            printf("Case %d: WHITEWASH\n",i);
        else if(b==N-a)
            printf("Case %d: BANGLAWASH\n",i);
        else if(b==w)
            printf("Case %d: DRAW %d %d\n",i,b,t);
        else if(b>w)
            printf("Case %d: BANGLADESH %d - %d\n",i,b,w);
        else if(w>b)
            printf("Case %d: WWW %d - %d\n",i,w,b);
    }
}
