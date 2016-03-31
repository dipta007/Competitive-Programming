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
    for(int l=1;l<=T;l++)
    {
        int N;
        scanf("%d ",&N);
        char a[N];
        int cnt=0;
        for(int j=0;j<N;j++)
        {
            scanf("%c",&a[j]);
        }

        for(int i=0;i<N;i++)
        {
            if(a[i]=='.' || a[i]=='#')
            {
                if(i>0 && a[i-1]=='.' && a[i+1]=='.')
                {
                    a[i]=1;
                    a[i-1]=1;
                    a[i+1]=1;
                    cnt++;
                }
                else if(i>0 && a[i-1]=='.' && a[i+1]=='#')
                {
                    a[i]=1;
                    a[i-1]=1;
                    a[i+1]=1;
                    cnt++;
                }
                else if(i>0 && a[i-1]=='.')
                {
                    a[i]=1;
                    a[i-1]=1;
                    cnt++;
                }

            }


        }
        if(a[N-1]=='.')
                cnt++;
        printf("Case %d: %d\n",l,cnt);
    }
}
