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

int indeg[30];
int cc;
vii ans;
int acc;
vi res;
int visited[100];
vii adj;
map <int,char> mpr;


int indeginc(int v)
{
    FOR(i,0,adj[v].size()-1)
    {
        int k = adj[v][i];
        indeg[k]++;
    }
}
int indegdec(int v)
{
    FOR(i,0,adj[v].size()-1)
    {
        int k = adj[v][i];
        indeg[k]--;
    }
}

void dfs(int cnt)
{
    if(cnt==cc-1)
    {
        FOR(i,0,res.size()-1)
        {
            if(i) printf(" ");
            printf("%c",mpr[res[i]]);
        }
        printf("\n");
        acc++;
        return;
    }
    //visited[u]=1;

    FOR(i,1,cc-1)
    {
        if(indeg[i]==0 && visited[i]==0)
        {
            visited[i]=1;
            indegdec(i);
            res.PB(i);

            dfs(cnt+1);

            visited[i]=0;
            indeginc(i);
            res.pop_back();
        }
    }
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    getchar();
    FOR(ci,1,t)
    {
        getchar();
        string st;
        getline(cin,st);
        stringstream ss(st);
        cc=1;
        char ch;
        map <char, int> mp;
        mpr.clear();
        vector <char> vc;
        while(ss >> ch)
        {
            vc.PB(ch);
        }
        sort(ALL(vc));
        FOR(i,0,vc.size()-1)
        {
            ch = vc[i];
            if(mp[ch]==0)
            {
                mp[ch]=cc;
                mpr[cc++]=ch;
            }
        }
        getline(cin,st);
        stringstream ss1(st);
        string now;

        CLR(indeg);
        adj.assign(34, vi());
        while(ss1 >> now)
        {
            adj[mp[now[0]]].PB(mp[now[2]]);
            indeg[mp[now[2]]]++;
        }
        acc=0;
        CLR(visited);
        res.clear();
        dfs(0);
        if(acc==0)
        {
            printf("NO\n");
        }
        if(ci<t) printf("\n");
        //debug(acc.size());
    }

    return 0;
}




