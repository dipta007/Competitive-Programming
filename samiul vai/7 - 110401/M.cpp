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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    rep(i,n)          for(i=1;i<=n;i++)
#define    repI(i,n)         for(i=0;i<n;i++)
#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
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

int bitOn(int N,int pos)
{
    return N=N | (1<<pos);
}
int bitOff(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool bitCheck(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

map <string,int> mps;

vector < vector <int> > AdjList;
vector <int> visited,dist;

void BFS(int src)
{
    visited[src]=1;
    dist[src]=0;
    queue <int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        //debug(u)
        for(int i=0;i<AdjList[u].size();i++)
        {
            int v = AdjList[u][i];
            if(visited[v]==0)
            {
                dist[v] = dist[u]+1;
                visited[v]=1;
                q.push(v);
            }
        }
    }
}

vector < vector<int> > vv;

string normalize(string st)
{
    while(st[st.size()-1]==' ')
    {
        st.erase(st.size()-1);
    }
    return st;
}

int main() {
//    READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        int p,n;
        getII(p,n);
        getchar();
        mps.clear();
        mps["Erdos, P."]=1;
        int in=2;
        vv.assign(p+4,vi());
        for(int i=0;i<p;i++)
        {
            string st;
            getline(cin,st);
            string author="";
            int koma =0;
            for(int j=0;j<st.size();j++)
            {
                if(st[j]==':')
                {
                    koma=0;
                    j++;
                    author = normalize(author);
                    if(mps[author]==0) mps[author]=in++;
                    vv[i].PB(mps[author]);
                    author="";
                    break;
                }
                if(st[j]==',') koma++;
                if(koma==2)
                {
                    koma=0;
                    j++;
                    author = normalize(author);
                    if(mps[author]==0) mps[author]=in++;
                    vv[i].PB(mps[author]);
                    author="";
                    continue;
                }
                author+= st[j];
            }
        }
        AdjList.assign(in+4,vi());
        for(int i=0;i<p;i++)
        {
            int len=vv[i].size();
            for(int j=0;j<len;j++)
            {
                for(int k=0;k<len;k++)
                {
                    if(j==k) continue;
                    AdjList[vv[i][j]].PB(vv[i][k]);
                }
            }
        }
        visited.assign(in+4,0);
        dist.assign(in+4,-1);
        BFS(1);
        printf("Scenario %d\n",ci);
        for(int i=0;i<n;i++)
        {
            string st;
            getline(cin,st);
            if(dist[mps[st]]==-1) printf("%s infinity\n",st.c_str());
            else printf("%s %d\n",st.c_str(),dist[mps[st]]);
        }
    }

    return 0;
}


