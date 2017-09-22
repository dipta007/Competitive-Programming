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
#include <unordered_map>
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
#define    FOREACH(i,t)      for (auto i=t.begin(); i!=t.end(); i++)
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

struct match
{
    string t1,t2;
    int a1,a2,b1,b2,c1,c2;
    match()
    {
        a1=a2=b1=b2=c1=c2=0;
    }
};

match vm[24];

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int n,mm,ci=1;
    while(~getII(n,mm))
    {
        if(n==0 && mm==0) break;

        int nn=n;
        n=(n*mm)/2;
        mm=nn;
        //vm.clear();
        string teams[mm+4];
        map <string,bool> flg;
        int inn=0;
        FOR(i,0,n-1)
        {
            match m;
            cin >> m.t1 >> m.a1 >> m.b1 >> m.c1;
            cin >> m.t2 >> m.a2 >> m.b2 >> m.c2;
            if(flg[m.t1]==0)
            {
                teams[inn++] = m.t1;
                flg[m.t1]=1;
            }
            if(flg[m.t2]==0)
            {
                teams[inn++] = m.t2;
                flg[m.t2]=1;
            }
            vm[i]=m;
        }

        map <string, int> bestRank;
        FOR(i,0,mm-1)
        {
            string team = teams[i];
            //debug("t",team)
            bestRank[team]=INF;
        }
        int cnt=0;
        FOR(w,2,5)
        {
            FOR(d,1,w-1)
            {
                FOR(a,1,5)
                {
                    FOR(b,1,5)
                    {
                        FOR(c,1,5)
                        {
                            FOR(j,1,5)
                            {
                                FOR(k,1,10)
                                {
                                    unordered_map <string,int> mp;
                                    FOR(i,0,n-1)
                                    {
                                        cnt++;

                                        match m = vm[i];
                                        int p1 = m.a1*a + m.b1*b + m.c1*c;
                                        int p2 = m.a2*a + m.b2*b + m.c2*c;

                                        if(p1>p2)
                                        {
                                            mp[m.t1] += w;
                                            if(abs(p1-p2)<=k) mp[m.t2] += 1;
                                        }
                                        else if(p2>p1)
                                        {
                                            mp[m.t2] += w;
                                            if(abs(p1-p2)<=k) mp[m.t1] += 1;
                                        }
                                        else
                                        {
                                            mp[m.t1] += d;
                                            mp[m.t2] += d;
                                        }

                                        if(m.a1>=j) mp[m.t1] += 1;
                                        if(m.a2>=j) mp[m.t2] += 1;
                                    }

                                    pair<int, string> vpp[mm+4];
                                    int in=0;
                                    FOR(i,0,mm-1)
                                    {
                                        string team = teams[i];
                                        //if(team=="jane") debug(team)
                                        vpp[in++] = (MP(-mp[team], team));
                                    }
                                    sort(vpp, vpp+mm);

                                    FOR(i,0,mm-1)
                                    {
                                        //if(vpp[i].ss=="jane") debug(vpp[i].ss)
                                        bestRank[vpp[i].ss] = min(bestRank[vpp[i].ss], i+1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        debug(cnt)

        printf("%d\n",ci++);
        FOR(i,0,mm-1)
        {
            string team = teams[i];
            printf("%s %d\n",team.c_str(), bestRank[team]);
        }
    }

    return 0;
}



