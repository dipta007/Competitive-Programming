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
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
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
#define    pii 	 pair< int, string >
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

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

string q,w,e,res;
pii dp[54][54][54];
bool vis[54][54][54];
string pri[54][54][54];

pii add(pii a, pii b)
{
    pii d;
    d.ff = a.ff + b.ff;
    d.ss = a.ss + b.ss;
    return d;
}

pii minimum(pii a, pii b)
{
    if(a.ff>b.ff) return a;
    if(a.ff==b.ff)
    {
        if(a.ss<b.ss) return a;
        else return b;
    }
    return b;
}

pii call(int i,int j,int k)
{
    if(i>=q.size() || j>=w.size() || k>=e.size()) return pii(0,"");

    int &ret = dp[i][j][k];
    if(vis[i][j][k]==1) return ret;
    vis[i][j][k]=1;

    int o1,o2,o3;
    if(q[i]==w[j] && w[j]==e[k])
    {
        return add(p,call(i+1,j+1,k+1));
    }
    else
    {
        o1 = call(i+1,j,k);
        o2 = call(i,j+1,k);
        o3 = call(i,j,k+1);
        return ret = minimum(o1, minimum(o2,o3));
//        if(o1>=o2 && o1>=o3)
//        {
//            if(o1==o2 && o2==o3)
//            {
//                if(o1.ss<)
//            }
//            else if(o1==o2)
//            {
//                pri[i][j][k]="12";
//            }
//            else if(o1==o3)
//            {
//                pri[i][j][k]="13";
//            }
//            else
//            {
//                pri[i][j][k]="1";
//            }
//        }
//        else if(o2>=o3 && o2>=o1)
//        {
//            if(o1==o2 && o2==o3)
//            {
//                pri[i][j][k] = "123"; ///3 ta tei jaite hbe
//            }
//            else if(o1==o2)
//            {
//                pri[i][j][k]="12";
//            }
//            else if(o2==o3)
//            {
//                pri[i][j][k]="23";
//            }
//            else
//            {
//                pri[i][j][k]="2";
//            }
//        }
//        else if(o3>=o2 && o3>=o1)
//        {
//            if(o1==o2 && o2==o3)
//            {
//                pri[i][j][k] = "123"; ///3 ta tei jaite hbe
//            }
//            else if(o3==o2)
//            {
//                pri[i][j][k]="23";
//            }
//            else if(o1==o3)
//            {
//                pri[i][j][k]="13";
//            }
//            else
//            {
//                pri[i][j][k]="3";
//            }
//        }
//        return ret = max(o1, max(o2,o3));
    }
}

void print(int i,int j,int k, string st)
{
    if(i>=q.size() || j>=w.size() || k>=e.size())
    {
        res = min(res, st);
        return;
    }
    //debug(i,j,k,st,pri[i][j][k])
    if(q[i]==w[j] && w[j]==e[k])
    {
        return print(i+1,j+1,k+1, st+q[i]);
    }
    else
    {
        string stt = pri[i][j][k];
        //debug(stt)
        FOR(ik,0,(int)stt.size()-1)
        {
            if(stt[ik]=='1')
            {
                print(i+1,j,k,st);
            }
            else if(stt[ik]=='2')
            {
                print(i,j+1,k,st);
            }
            else
            {
                print(i,j,k+1,st);
            }
        }
    }
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    getchar();
    FOR(ci,1,t)
    {
        getline(cin,q);
        getline(cin,w);
        getline(cin,e);
        CLR(vis);
        pii re = call(0,0,0);
        printf("Case %d: ",ci);
        //debug(re)
        if(re.ff==0)
        {
            printf("0 T.A.T\n");
        }
        else
        {
            printf("%d %s\n",re.ff,re.ss.c_str());
        }
    }

    return 0;
}



