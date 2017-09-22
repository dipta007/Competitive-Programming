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

int n,m;
string st[34];
int dx[]={-1,1,0,0,-1,-1,1,1,0};
int dy[]={0,0,-1,1,-1,1,1,-1,0};
string res[] = { ", U", ", D", ", L", ", R", ", UL", ", UR", ", DR", ", DL" , ", *"};
vector <string> pri;
string name;
int vis[34][34][34];

int dfs(int x,int y, int in)
{
    if(in>=name.size())
    {
        printf("%s found:",name.c_str());
        FOR(i,0,(int)pri.size()-1)
        {
            printf("%s",pri[i].c_str());
        }
        printf("\n");
        return 1;
    }
    vis[x][y][in]=1;

    FOR(i,0,8)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X>=0 && Y>=0 && X<n && Y<m && st[X][Y]==name[in] && vis[X][Y][in+1]==0)
        {
            pri.PB(res[i]);
            int k = dfs(X,Y,in+1);
            pri.pop_back();
            if(k) return 1;
        }
    }
    return 0;
}

vector < vector < pii > > vp;

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("in.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        vp.assign(30, vector < pii > ());
        cin >> n >> m;
        FOR(i,0,n-1)
        {
            cin >> st[i];
        }

        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                int k = st[i][j]-'A';
                vp[k].PB(pii(i,j));
            }
        }

        int q;
        cin >> q;
        printf("Case %d:\n",ci);
        FOR(i,1,q)
        {
            cin >> name;
            int flg=0;
            int kk = (int)(name[0]-'A');
            //debug(kk,name, vp[kk].size())
            for(int jk=0; jk< vp[kk].size(); jk++)
//            FOR(jk,0,(int)(vp[k].size()-1))
            {
                //debug(kk,jk)
                int j = vp[kk][jk].first;
                int k = vp[kk][jk].second;
                //debug("*")

                string sk = " (";
                sk += NumberToString(j+1);
                sk += ",";
                sk += NumberToString(k+1);
                sk += ")";
                pri.PB(sk);
                CLR(vis);
                int kk = dfs(j,k,1);
                pri.pop_back();
                if(kk)
                {
                    flg=1;
                    break;
                }
            }
            if(flg==0) printf("%s not found\n",name.c_str());
        }
    }

    return 0;
}



