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

#define M 500004
bool marked[M];
int primef[M];
vector <int> primes;

bool isPrime(int n)
{
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  return marked[n] == 0;
}

void sieve(int n)
{
    primes.push_back(2);
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    for(int i=3; i<=n; i+=2) if(marked[i] == 0) primes.push_back(i);

    CLR(primef);
    FOR(i, 0, (int)primes.size()-1)
    {
        int pp = primes[i];
        for(int j=pp; j<=n; j+=pp)
        {
            int x = j;
            int cnt = 0;
            while(x%pp==0) x/=pp, cnt++;
            primef[j] += cnt;
        }
    }
}
const int NODE = 80004;

/***
    Minimum vertex cover = Maximum matching
    Minimum edge cover = number of vertices - Maximum matching
    Maximum independent set = Minimum edge cover

    Vertex cover is the number of edges to cover all the vertices
    Edge cover is the of vertices to cover all the edges
    Independent set is the set of vertices such that no one has connection with each other
***/

//Kuhn's Algo for finding Maximum matching
struct KUHN{
    int left[NODE], right[NODE], vis[2*NODE], cc; ///Node double in vis for vertex print
    vector<int> adj[NODE];

    KUHN() : cc(1) {}

    bool tryK ( int v ) {
        if ( vis[v] == cc ) return false;
        vis[v] = cc;
//        trace(v, adj[v].size());
        for ( int i = 0; i < (int) adj[v].size(); i++ ) {
            int t = adj[v][i];
            if ( right[t] == -1 ) {
                right[t] = v; left[v] = t;
                return true;
            }
        }
        for ( int i = 0; i < (int)adj[v].size(); i++ ) {
            int t = adj[v][i];
            if ( tryK ( right[t] ) ) {
                right[t] = v; left[v] = t;
                return true;
            }
        }
        return false;
    }

    int match(int n) {
        int res = 0;
        bool done;
        SET(left); SET(right);
        do {
            done = true; cc++;
            FOR(i,0,n) {
//                trace(i, left[i]);
                if(left[i]==-1 && tryK(i)) {
//                    trace(i, left[i]);
                    done = false;
                }
            }
        } while(!done);
        FOR(i,0,n) res += (left[i]!=-1);
        return res;
    }

    void clear( int n ) {
        FOR(i,0,n) adj[i].clear();
    }

    void add_edge(int x, int y) {
        adj[x].PB(y);
        adj[y].PB(x);
    }
}kuhn;

int a[40004];

int main() {
    #ifdef dipta007
//        READ("in.txt");
//       WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    sieve(M-4);
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        map < int, int > mp;
        int mx = 0;
        FOR(i,1,n)
        {
            int x;
            getI(x);
            mx = max(mx, x);
            a[i-1] = x;
            mp[x] = i;
        }
        trace("sd");

        kuhn.clear(n);
        FOR(i,0,n-1)
        {
            FOR(j,0,(int)primes.size()-1)
            {
                int kk = a[i] * primes[j];
//                trace(kk, mx);
                if(kk > mx) break;
                if(mp[kk] == 0) continue;

//                trace(a[i], primef[a[i]],primes[j], i, mp[kk]-1+n);
                if(primef[a[i]]%2 == 0)
                    kuhn.add_edge(i, mp[kk]-1+n);
                else
                    kuhn.add_edge(mp[kk]-1, i+n);
            }
        }

//        trace(n, kuhn.match(n));

        pf("Case %d: %d\n", ci, n - kuhn.match(n-1));
    }

    return 0;
}


