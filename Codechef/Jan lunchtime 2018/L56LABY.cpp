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

#define dipta007
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

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

bool vis[1004][1004];
int grid[1004][1004];
int ngrid[1004][1004];
int r, c;
// 4 direction
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

// void dfs(int x, int y, int val)
// {
//     //debug(x,y, val);
//     vis[x][y] = 1;
//     ngrid[x][y] = val;
//     FOR(i,0,3)
//     {
//         int X = x + dx[i];
//         int Y = y + dy[i];
//
//         if(X>=0 && Y>=0 && X<r && Y<c) // In range
//         {
//             if(grid[X][Y]!=-1) // Not visited or Not forbiddable
//             {
//                 if(vis[X][Y]==0 || ngrid[X][Y] <= val) // Gie lv ase
//                 {
//                     if(val >= 1)
//                     {
//                         dfs(X, Y, val-1);
//                     }
//                 }
//             }
//         }
//     }
// }

// bool visited[1004][1004];

void bfs(vector < pair < int, pii > > &vp)
{
    queue < int > q;

    FOR(i,0,(int)vp.size()-1)
    {
        int x = vp[i].ss.ff;
        int y = vp[i].ss.ss;
        int z = vp[i].ff;

        q.push(x);
        q.push(y);
        q.push(z);
        vis[x][y] = 1;
    }

    // q.push(x);
    // q.push(y);
    // q.push(val);
    // visited[x][y] = true;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        int v = q.front(); q.pop();
        int w = q.front(); q.pop();

        FOR(i,0,3)
        {
            int X = u + dx[i];
            int Y = v + dy[i];
            if(X>=0 && Y>=0 && X<r && Y<c) // In range
            {
                if(grid[X][Y]!=-1) // Not forbiddable
                {
                    if(vis[X][Y]==0 || ngrid[X][Y] < w-1) // Not visited
                    {
                        vis[X][Y] = 1;
                        ngrid[X][Y] = w-1;
                        if(w-1>=1)
                        {
                            q.push(X);
                            q.push(Y);
                            q.push(w-1);
                        }
                    }

                }
            }
        }
    }
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

   int t;
   getI(t);

   FOR(ci,1,t)
   {
       vector < pair < int, pii > > vp;
       getII(r,c);
       FOR(i,0,r-1)
       {
           FOR(j,0,c-1)
           {
               getI(grid[i][j]);
               ngrid[i][j] = grid[i][j];
               if(grid[i][j] > 0) vp.PB( MP(grid[i][j], MP(i,j)) );
           }
       }

       sort(ALLR(vp));

       CLR(vis);

       bfs(vp);

       // FOR(i,0,(int)vp.size()-1)
       // {
       //     int x = vp[i].ss.ff;
       //     int y = vp[i].ss.ss;
       //     int z = vp[i].ff;
       //
       //     if(ngrid[x][y] < grid[x][y] ||  vis[x][y]==0)
       //     {
       //         bfs(x,y,z);
       //     }
       // }

       // FOR(i,0,r-1)
       // {
       //     FOR(j,0,c-1)
       //     {
       //         if(grid[i][j] > 0 && vis[i][j]==0)
       //         {
       //             dfs(i, j, grid[i][j]);
       //         }
       //     }
       // }

       FOR(i,0,r-1)
       {
           FOR(j,0,c-1)
           {
               if(grid[i][j] == -1)
               {
                   printf("B");
                   continue;
               }
               if(vis[i][j] == 0)
               {
                   printf("N");
               }
               else printf("Y");
           }
           printf("\n");
       }
   }


    return 0;
}
