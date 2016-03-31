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


int sale(int i,int w);

int dp[1001][31];
int cost[1001];
int wei[1001];
int N,cap;

int main()
{
    int T,G,sum;

    cin >> T;
    for(int I=1;I<=T;I++)
    {
        cin >> N;
        for(int J=1;J<=N;J++)
            cin >> cost[J] >> wei[J];
        cin >> G;
        sum=0;
        for(int J=1;J<=G;J++)
        {
            cin >> cap;
            memset(dp,-1,sizeof(dp));
            sum=sum+sale(1,0);
        }


        cout << sum << endl;
    }
}

int sale(int i,int w)
{
    if(i==N+1)
        return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    int pro1=0,pro2=0;
    if(w+wei[i]<=cap)
        pro1=cost[i]+sale(i+1,w+wei[i]);
    pro2=sale(i+1,w);
    dp[i][w]=max(pro1,pro2);
    return dp[i][w];

}
