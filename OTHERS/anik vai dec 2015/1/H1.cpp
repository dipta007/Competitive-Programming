#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)

#define bug printf("hihi\n")

#define eps 1e-8

typedef long long ll;

using namespace std;
#define N 55
#define mod  1000000007

ll dp[N][N][N][N]; //
int bit[N];

void change(char *a)  //处理对于字符串减一操作
{
    int i,j;
    int len=strlen(a);
    len--;
    while(len>=0)
    {
        a[len]--;
        if(a[len]>='0') break;
        a[len]='9';
        len--;
    }
    len=strlen(a);
    for(i=0;i<len-1;i++) if(a[i]>='1') break;
    int k=0;
    for(i;i<len;i++)
        a[k++]=a[i];
    a[k]='\0';
}

ll dfs(int pos,int le,int mid,int ri,bool bound)
{
    if(pos==0) return le==mid&&mid==ri&&le>=1 ? 1:0;
    if(!bound&&dp[pos][le][mid][ri]>=0) return dp[pos][le][mid][ri];
    int up=bound ? bit[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++)
    {
        if(i==3)
          ans=(ans+dfs(pos-1,le+1,mid,ri,bound&&i==up))%mod;
        else
          if(i==6)
           ans=(ans+dfs(pos-1,le,mid+1,ri,bound&&i==up))%mod;
        else
            if(i==9)
             ans=(ans+dfs(pos-1,le,mid,ri+1,bound&&i==up))%mod;
        else
             ans=(ans+dfs(pos-1,le,mid,ri,bound&&i==up))%mod;
    }
    if(!bound) dp[pos][le][mid][ri]=ans;
    return ans;
}


ll solve(char *c)
{
   int i,j;
   int len=strlen(c);
   for(i=1;i<=len;i++)
    bit[i]=c[len-i]-'0';

   return dfs(len,0,0,0,true)%mod;
}

int main()
{
     freopen("in.txt", "r", stdin);
    int i,j,t;
    char a[N],b[N];
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        change(a);
        printf("%lld\n",(solve(b)-solve(a)+mod+mod)%mod);//必须+mod % mod 因为可能是负数
    }
    return 0;
}
