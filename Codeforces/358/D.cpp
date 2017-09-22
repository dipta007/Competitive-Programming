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

string s1,s2;
int n,m,k;
//int nn,mm;
int dp[1004][1004][12];
vi v;
//int pri[1004][1004];
//int s11[1004];
//int s22[1004];

int call(int i,int j, int kk, int pi, int pj)
{
    if(i>=s1.size() || j>=s2.size())
    {
        if(pi!=-1 && pj!=-1 && kk<k)
        {
            if(i>=s1.size()) return i-pi;
            else return j-pj;
        }
        return 0;
    }

    int &ret = dp[i][j][kk];
    if(ret!=-1) return ret;

    int o1=0,o2=0,o3=0,o4=0;
    if(s1[i]==s2[j])
    {
        if(pi==-1 || pj==-1) return ret = call(i+1, j+1, kk, i, j);
        else return ret = call(i+1,j+1, kk, pi, pj);
    }
    else
    {
        if(kk<k && pi!=-1) o1 = (i-pi)+call(i+1, j, kk+1, -1, -1);
        if(kk<k && pj!=-1) o2 = (j-pj)+call(i, j+1, kk+1, -1, -1);
        else
        {
            o3 = call(i+1, j, kk, -1, -1);
            o4 = call(i, j+1, kk, -1, -1);
        }
    }
    //debug(i,j,o1,o2,o3,o4)
    return ret = max(o1,max(o2,max(o3,o4)));
}
//int call(int i,int j, int kk, int pi, int pj)
//{
//    if(i>=s1.size() || j>=s2.size())
//    {
//        if(pi!=-1 && pj!=-1 && kk<k)
//        {
//            v.PB(i-pi);
//            if(i>=s1.size()) return i-pi;
//            else return j-pj;
//        }
//        return 0;
//    }
//
//    int &ret = dp[i][j];
//    if(ret!=-1) return ret;
//
//    int o1=0,o2=0,o3=0,o4=0;
//    if(s1[i]==s2[j])
//    {
//        if(pi==-1 || pj==-1) return ret = call(i+1, j+1, kk, i, j);
//        else return ret =call(i+1,j+1, kk, pi, pj);
//    }
//    else
//    {
//        if(pi!=-1)
//        {
//            debug(i,i-pi)
//            v.PB(i-pi);
//        }
////        if(kk<k && pi!=-1) o1 = (i-pi)+call(i+1, j, kk+1, -1, -1);
////        if(kk<k && pj!=-1) o2 = (j-pj)+call(i, j+1, kk+1, -1, -1);
//        o3 = call(i+1, j, kk, -1, -1);
//        o4 = call(i, j+1, kk, -1, -1);
//    }
//    //debug(i,j,o1,o2,o3,o4)
//    return ret = max(o1,max(o2,max(o3,o4)));
//}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    while(~getIII(n,m,k))
    {
        getchar();
        getline(cin,s1);
        getline(cin,s2);
//        debug(s1,s2)
        SET(dp);
        int sum=0;

//        CLR(s11);
//        CLR(s22);
        int x = call(0,0,0,-1,-1);
//        sort(ALLR(v));
//        FOR(i,0,k-1)
//        {
//            debug(v[i])
//            sum += v[i];
//        }
        printf("%d\n",x);

//        FOR(j,0,k-1)
//        {
//            if(sum>=n || sum>=m) break;
//            SET(dp);
//            CLR(s11);
//            CLR(s22);
//
//            sum += call(0,0);
//            call1(0,0);
//
//            string ns1 = "";
//            string ns2 = "";
//            FOR(i,0,(int)s1.size()-1)
//            {
//                if(s11[i]==0) ns1 += s1[i];
//            }
//            FOR(i,0,(int)s2.size()-1)
//            {
//                if(s22[i]==0) ns2 += s2[i];
//            }
//            s1=ns1;
//            s2=ns2;
//            debug(sum,s1,s2)
//        }
//        printf("%d\n",sum);
    }

    return 0;
}



