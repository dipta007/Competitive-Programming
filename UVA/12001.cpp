#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#define dipta00
#ifdef dipta007
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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

ll ncr[304][304];

void pre()
{
    CLR(ncr);
    ncr[0][0] = 1 ;
    int limncr = 300 ;
    for (int i = 1 ; i <= limncr ; i++)
        for (int j = 0 ; j <= limncr ; j++)
        {
            if ( j > i )
                ncr[i][j] = 0 ;
            else if ( j == i || j == 0 ) ncr[i][j] = 1 ;
            else
                ncr [i][j] = ncr[i-1][j - 1] + ncr[i-1][j] ;
        }
}

ll con[54];

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    pre();
    while(~getII(n,m))
    {
        if(n==0 && m==0) break;
        int a[n+4];
        CLR(con);
        FOR(i,0,n-1)
        {
            getI(a[i]);
            con[a[i]]++;
        }

        ll cnt = 0;

        /// different 3
        FOR(i,1,m)
        {
            FOR(j,i+1,m)
            {
                FOR(k,j+1,m)
                {
                    if(i == j) continue;
                    if(j == k) continue;
                    cnt += (ll)con[i] * con[j] * con[k];
//                    trace(i,j,k,cnt, con[i], con[j], con[k]);
                }
            }
        }
        trace(cnt);
        /// same 3
        FOR(i,1,m)
        {
            cnt += (ll)ncr[con[i]][3];
        }
        trace(cnt);

        ll r3 = cnt;

        cnt = 0;
        /// different 3
        FOR(i,1,m)
        {
            FOR(j,i+1,m)
            {
                FOR(k,j+1,m)
                {

                    ll baki = con[i] + con[j] + con[k] - 3;
                    cnt += ((ll)con[i] * con[j] * con[k] * baki) / 2;
                    trace(i, j, k, cnt);
                }
            }
        }
        trace(cnt);
        /// Different 4
        int cum[m+4];
        FOR(i,1,m+1)
        {
            cum[i] = cum[i-1] + con[i];
        }
        FOR(i,1,m)
        {
            FOR(j,i+1,m)
            {
                FOR(k,j+1,m)
                {
//                    FOR(l, k+1, m)
//                    {
//                        cnt += (ll)con[i] * con[j] * con[k] * con[l];
//                    }
                    ll baki = cum[m] - cum[k];
                    debug(i, j, k, baki)
                    cnt += (ll)con[i] * con[j] * con[k] * ncr[baki][1];
                }
            }
        }
        debug(cnt)

        /// same 3
        FOR(i,1,m)
        {
            ll baki = n - con[i];
            cnt += (ll)ncr[con[i]][3] * baki;
        }
        /// same 4
        FOR(i,1,m)
        {
            cnt += (ll)ncr[con[i]][4];
        }

        pf("%lld %lld\n",r3, cnt);
    }

    return 0;
}

