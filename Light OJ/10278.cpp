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

vi fire;
int n;
int dist[504];
vector < vector <pii> > adj;

int dj()
{
    priority_queue <pii> q;
    SET(dist);
    FOR(i,0,(int)fire.size()-1)
    {
        q.push(pii(-0,fire[i]));
        dist[fire[i]]=0;
    }

    while(!q.empty())
    {
        pii u = q.top(); q.pop();

        FOR(i,0,(int)adj[u.ss].size()-1)
        {
            pii v = adj[u.ss][i];
            if(dist[v.ff]==-1)
            {
                dist[v.ff] = -u.ff + v.ss;
                q.push(pii(-dist[v.ff],v.ff));
                continue;
            }
            if(-u.ff + v.ss < dist[v.ff])
            {
                dist[v.ff] = -u.ff + v.ss;
                q.push(pii(-dist[v.ff],v.ff));
            }
        }
    }
    int maxy = -1;
    FOR(i,1,n)
    {
        //debug(dist[i])
        maxy = max(maxy, dist[i]);
    }
    return maxy;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int f,m;
        getII(f,m);
        n=m;
        adj.assign(n+4, vector <pii> ());
        fire.clear();
        map <int, int> mp;
        FOR(i,0,f-1)
        {
            int x;
            getI(x);
            if(mp[x]==0) fire.PB(x);
            mp[x]=1;
        }
        getchar();
        string st;
        while(getline(cin,st))
        {
            if(st.size()==0) break;
            stringstream ss(st);
            int a,b,c;
            ss >> a;
            ss >> b;
            ss >> c;
            adj[a].PB(pii(b,c));
            adj[b].PB(pii(a,c));
        }

        int mini = INF;
        int in;
        FOR(i,1,n)
        {
            fire.PB(i);
            int kk = dj();
            fire.pop_back();
            if(kk<mini)
            {
                //debug(kk,i)
                mini = kk;
                in = i;
            }
        }
        printf("%d\n",in);
        if(ci<t) printf("\n");
    }

    return 0;
}




