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
    int t,d,v;
    int mod=1000000007;
    scanf("%d",&t);
    for(int C=1;C<=t;C++)
    {
        scanf("%d %d",&d,&v);
        int k=((d%mod)+(v%mod))%mod;
        printf("Case %d: %d\n",C,k);
    }
}
