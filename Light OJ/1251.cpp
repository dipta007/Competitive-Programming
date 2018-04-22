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

template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta00
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1<<" | ";
    __f(comma+1, args...);
}
#else
#define debug(args...)  /// Just strip off all debug tokens
#define trace(...) ///yeeeee
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

#define MAX 2*8000 + 5
vector <vector <int> > g, gt;
bool used[MAX];
vector <int> order;
int comp[MAX];
map < int, int > tru, fal, flip;

void dfs1 (int v)
{
    used [v] = true;
    for (int i = 0; i <g [v] .size (); ++ i)
    {
        int to = g [v] [i];
        if (! used [to])
            dfs1 (to);
    }
    order.push_back (v);
}

void dfs2 (int v, int cl)
{
    comp [v] = cl;
    for (int i = 0; i <gt [v] .size (); ++ i)
    {
        int to = gt [v] [i];
        if (comp [to] == -1)
            dfs2 (to, cl);
    }

}

int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n,m;
        cin >> n >> m;
        g.assign(m+m+4, vi());
        gt.assign(m+m+4, vi());
        tru.clear();
        fal.clear();
        flip.clear();
        order.clear();


        FOR(i,1,m)
        {
            tru[i] = i;
            fal[i] = m+i;
            flip[i] = m+i;
            flip[m+i] = i;
        }

        FOR(i,1,n)
        {
            char aa, bb;
            int a, b;
            cin >>  a >> b;

            if(a < 0)
                a = m+abs(a);
            if(b < 0)
                b = m+abs(b);


            g[flip[a]].push_back(b);
            gt[b].push_back(flip[a]);
            g[flip[b]].push_back(a);
            gt[a].push_back(flip[b]);
        }

        CLR(used);
        for (int i = 1; i <=m+m; ++i)
            if (! used [i])
                dfs1 (i);

//        debug("SAd")
        SET(comp);
        int nn = order.size();
        reverse(order.begin(),order.end());
        for (int i = 0, j = 0; i < order.size(); ++i)
        {
            int v = order[i];
            if (comp [v] == -1)
                dfs2 (v, j ++);
            debug(v, comp[v])

        }

        int flg = 1;
        cout << "Case " << ci << ": ";
        for (int i = 1; i <= m; ++ i)
            if (comp [i] == comp [flip[i]])
            {
                debug(i)
                cout << "No" << endl;
                flg = 0;
                break;
            }

        if(flg)
        {
            cout << "Yes" << endl;
            vi v;
            for (int i = 1; i <= m; ++ i)
            {
                if(comp[i] > comp[ flip[i] ])
                {
                    v.PB(i);
                }
            }
            sort(ALL(v));
            cout << v.size();
            FOR(i,0,(int)v.size()-1)
            {
                cout << " " << v[i];
            }
            cout << endl;
        }
    }



    return 0;
}
