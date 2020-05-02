#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

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
///****************** template ends here ****************
int t,n,m;

int tcnt;
//Cycle contains which scc node belongs too.
#define NODE 20004
int mark[NODE];

struct SCC{
    int num[NODE], low[NODE], col[NODE], cycle[NODE], st[NODE];
    int tail, cnt, cc;
    vi adj[NODE];

    SCC():tail(0),cnt(0),cc(0) {}
    void clear () {
        cc += 3;
        SET(cycle);
        FOR(i,0,NODE-1) adj[i].clear();
        tail = 0;
    }
    void tarjan ( int s ) {
        num[s] = low[s] = cnt++;
        col[s] = cc + 1;
        st[tail++] = s;
        FOR(i,0,(int)adj[s].size()-1) {
            int t = adj[s][i];
            if ( col[t] <= cc ) {
                tarjan ( t );
                low[s]=min(low[s],low[t]);
            }
            /*Back edge*/
            else if (col[t]==cc+1)
                low[s]=min(low[s],low[t]);
        }
        if ( low[s] == num[s] ) {
            tcnt++;
            mark[s] = 1;
            while ( 1 ) {
                int temp=st[tail-1];
                tail--;
                col[temp] = cc + 2;
                cycle[temp] = s;
                if ( s == temp ) break;
            }
        }
    }
    void shrink( int n ) {
        FOR(i,0,n){
            FOR(j,0,(int)adj[i].size()-1){
                adj[i][j] = cycle[adj[i][j]]; ///Careful. This will create self-loop. Just ignore i->i edges when processing.
            }
        }
        FOR(i,0,n){
            if ( cycle[i] == i ) continue;
            int u = cycle[i];
            FOR(j,0,(int)adj[i].size()-1){
                int v = adj[i][j];
                adj[u].PB ( v );
            }
            adj[i].clear();
        }
        FOR(i,0,n){ ///Not always necessary
            sort ( ALL(adj[i]) );
            UNIQUE(adj[i]);
        }
    }

    void findSCC( int n ) {
        tcnt = 0;
        FOR(i,1,n) {
            if ( col[i] <= cc ) {
                tarjan ( i );
            }
        }
    }
}sc;

int in[NODE], out[NODE];

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,m;
        getII(n,m);

        sc.clear();

        CLR(mark);
        FOR(i,1,m)
        {
            int x,y;
            getII(x,y);
            sc.adj[x].PB(y);
        }

        if(n==1)
        {
            printf("Case %d: 0\n",ci);
            continue;
        }

        sc.findSCC(n);

        if(tcnt == 1)
        {
            printf("Case %d: 0\n",ci);
            continue;
        }

        sc.shrink(n);

        int a=0,b=0;
        CLR(in);
        CLR(out);

        FOR(i,1,n)
        {
            trace(i);
            FOR(j,0,(int)sc.adj[i].size()-1)
            {
                int x = sc.adj[i][j];
                if(i==x) continue;

//                trace(i, x);

                out[i]++;
                in[x]++;
            }
        }

        FOR(i,1,n)
        {
            if(mark[i] == 0) continue;
//            trace(i, in[i], out[i]);
            if(in[i]==0) a++;
            if(out[i]==0) b++;
        }
        printf("Case %d: %d\n",ci, max(a,b));
    }


    return 0;
}


