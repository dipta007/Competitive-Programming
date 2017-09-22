#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }


char a[110],b[110];
//int dp[110][110];
//string dir[110][110];
//int m,n;
//int cal_LCS()
//{
//
//    m=strlen(a);
//    n=strlen(b);
//    for(int i=1;i<=m;i++){
//        dp[i][0]=0;
//        dir[i][0]="";
//    }
//    for(int i=0;i<=n;i++){
//        dp[0][i]=0;
//        dir[0][i]="";
//    }
//
//    for(int i=1;i<=m;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            if(a[i-1]==b[j-1])
//            {
//                dp[i][j]=dp[i-1][j-1]+1;
//                dir[i][j]=dir[i-1][j-1]+a[i-1];
//            }
//            else if(dp[i-1][j]>dp[i][j-1])
//            {
//                dp[i][j]=dp[i-1][j];
//                dir[i][j]=dir[i-1][j];
//            }
//            else if(dp[i-1][j]<dp[i][j-1])
//            {
//                dp[i][j]=dp[i][j-1];
//                dir[i][j]=dir[i][j-1];
//            }
//            else if(dp[i-1][j]==dp[i][j-1])
//            {
//                dp[i][j]=dp[i][j-1];
//                dir[i][j]=min(dir[i-1][j],dir[i][j-1]);
//            }
//        }
//    }
//    //debug(dir[m][n]);
//
//    string res = a;
//    //debug(res);
//    string temp=dir[m][n];
//    int i=0,j=0;
//    while(i<n)
//    {
//        if(temp[j]==b[i])
//        {
//            j++;
//        }
//        else
//        {
//            res+=b[i];
//        }
//        i++;
//    }
//    cout<< res << endl;
//    return dp[m][n];
//}

int dp[104][104];
int pri[104][104];

int call(int i,int j)
{
    if(i>=strlen(a) || j>=strlen(b)) return 0;
    int &ret = dp[i][j];
    if(ret!=-1) return ret;

    int o1,o2;
    if(a[i]==b[j])
    {
        pri[i][j]=1;
        return ret = 1 + call(i+1,j+1);
    }
    else
    {
        o1 = call(i+1,j);
        o2 = call(i,j+1);
    }
    if(o1>=o2) pri[i][j]=2;
    else pri[i][j]=3;

    return ret = max(o1,o2);
}

int cnt;
void print(int i,int j, string res,int pa, int pb)
{
    if(cnt) return;
    if(i>=strlen(a) || j>=strlen(b))
    {
        FOR(ii,pa+1,(int)strlen(a)-1)
        {
            res += a[ii];
        }
        FOR(ii,pb+1,(int)strlen(b)-1)
        {
            res += b[ii];
        }
        printf("%s\n",res.c_str());
        cnt=1;
    }
    if(pri[i][j]==1)
    {
        FOR(ii,pa+1,i-1)
        {
            res += a[ii];
        }
        FOR(ii,pb+1,j-1)
        {
            res += b[ii];
        }
        res += a[i];
        print(i+1, j+1, res, i, j);
    }
    else if(pri[i][j]==2)
    {
        print(i+1,j, res, pa, pb);
    }
    else
    {
        print(i,j+1, res, pa, pb);
    }
}

int main() {
    #ifdef howcum
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // howcum

    while(~scanf("%s %s",a,b))
    {
        SET(dp);
        call(0,0);
        cnt=0;
        print(0,0,"",-1,-1);
        //debug(a,b,cal_LCS());
    }

    return 0;
}



