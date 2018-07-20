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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
#ifdef dipta0
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

vector < vector < pii > > adj;
vi GS[30][30];

stack < int > tour;

void dfs(int u)
{
    debug(u)
    FOR(i,0,(int)adj[u].size()-1)
    {
        if(adj[u][i].ss == 1)
        {
            adj[u][i].ss = 0;
            dfs(adj[u][i].ff);
        }
    }
    tour.push(u);
}
char st[1000+4][24];
int inn[30], outt[30];
int len[1004];

int main() {
    #ifdef dipta007
        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);

        FOR(i,0,25) FOR(j,0,25) GS[i][j].clear();
        adj.assign(30, vector < pii > ());
        CLR(inn);
        CLR(outt);

        getchar();
        FOR(i,1,n)
        {
            gets(st[i]);
            len[i] = strlen(st[i]) - 1;

            int u = st[i][0] - 'a';
            int v = st[i][len[i]] - 'a';

            adj[u].PB(MP(v,1));
            GS[u][v].PB(i);
            outt[u]++;
            inn[v]++;

//            debug(char(u+'a'), char(v+'a'))
        }

//        if(n==1)
//        {
//            cout << "Case " << ci << ": ";
//            cout << "Yes" << endl;
//            cout << st[1] << endl;
//            continue;
//        }

        int flg = 1;
        int c1 = 0;
        int c2 = 0;
        int strt=-1, endd;
        FOR(i,0,25)
        {
            if(inn[i] != outt[i])
            {
                if(outt[i] > inn[i])
                {
                    c1++;
                    strt = i;
                }
                else
                {
                    endd = i;
                    c2++;
                }
//                trace(i, inn[i], outt[i], strt);

                if(abs(inn[i] - outt[i]) > 1) flg = 0;
            }
        }

        if(c1+c2 == 0 || (c1 == 1 && c2 == 1)) ;
        else flg = 0;

        cout << "Case " << ci << ": ";
        if(flg == 1)
        {
            if(strt == -1) FOR(i,0,25) if(outt[i] != 0) strt = i;
//            debug(strt, c1)
//            if(c1 != 0) adj[strt].push_back(MP(endd, 1));
            while(!tour.empty()) tour.pop();
            dfs(strt);
//            debug(tour.size());

            if(tour.size() != n+1)
            {
                pf("No\n");
                continue;
            }
            pf("Yes\n");

            int prev = tour.top();
            tour.pop();

            while(!tour.empty())
            {
                int x = tour.top();
                tour.pop();

                debug(prev, x, GS[prev][x].size())

                pf("%s", st[GS[prev][x].back()]);
                GS[prev][x].pop_back();
                prev = x;

                if(!tour.empty()) pf(" ");
            }

        }
        else pf("No");

        pf("\n");

    }

    return 0;
}

