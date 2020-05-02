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
vi a;

int petr(vi &v)
{
    vi res(v);
    vi rnd;
    FOR(i,1,n) rnd.PB(i-1);

    random_shuffle(ALL(rnd));

    int tot = 3*n;
    FOR(i,1,tot)
    {
        int x = rand() % n;
        int y = rand() % n;
        while(y == x) y = rand() % n;

        x = rnd[x];
        y = rnd[y];

        swap(res[x], res[y]);
    }

    int cnt = 0;
    FOR(i,0,n-1) if(a[i] == res[i]) cnt++;
    return cnt;
}
int umnik(vi &v)
{
    vi res(v);
    vi rnd;
    FOR(i,1,n) rnd.PB(i-1);

    random_shuffle(ALL(rnd));

    int tot = 7*n + 1;
    FOR(i,1,tot)
    {
        int x = rand() % n;
        int y = rand() % n;
        while(y == x) y = rand() % n;

        x = rnd[x];
        y = rnd[y];

        swap(res[x], res[y]);
    }

    int cnt = 0;
    FOR(i,0,n-1) if(a[i] == res[i]) cnt++;
    return cnt;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    srand(time(NULL));
    while(~getI(n))
    {
        a.assign(n, int());
        for(auto &v: a)
        {
            getI(v);
        }
        if(n < 1000 || n > 1000000)
        {
            pf("Petr\n");
            continue;
        }

        int p, u;
        p = u = 0;

        vi v;
        FOR(i,1,n) v.PB(i);

        FOR(i,1,247)
        {
            int sp = petr(v);
            int up = umnik(v);
            if(sp > up) p++;
            else if(up > sp) u++;
            else i--;

//            p += sp;
//            u += up;
        }

        if(p > u) pf("Petr\n");
        else if(u >= p) pf("Um_nik\n");
//        else
//        {
//            if(petr(v) >= umnik(v)) pf("Petr\n");
//            else pf("Um_nik\n");
//        }

    }

    return 0;
}

