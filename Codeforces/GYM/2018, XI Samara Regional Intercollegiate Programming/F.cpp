//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
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
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int in[1000+4];
int mat[1004][1004];
int mat1[1004];

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(cin >> n)
    {
        CLR(mat);
        vector < int > adj[n+4];
        vector < int > rev[n+4];
        vector < int > ch[n+4];
        CLR(in);
        int ff = 1;
        FOR(i,1,n)
        {
            int x;
            cin >> x;
            while(x--)
            {
                int y;
                cin >> y;
                if(y == i) ff = 0;
                adj[i].PB(y);
                rev[y].PB(i);
                mat[i][y] = 1;
                in[i]++;
            }
        }

        FOR(i,1,n)
        {
            sort(ALL(adj[i]));
            sort(ALL(rev[i]));
        }

        queue < int > q;
        FOR(i,1,n)
        {
            if(in[i] == 0) q.push(i);
        }

        vector < pii > edges;

        while(!q.empty())
        {
            int u = q.front(); q.pop();

            for(auto v: rev[u])
            {
                in[v] --;
                if(in[v] == 0) q.push(v);
            }

            priority_queue < pii > pq;
            for(auto v: adj[u])
            {
                /// Is this one satisfy or not
                /// The children are the successsors of u
                int flg = 1;
                for(auto child: adj[v])
                {
                    if(mat[u][child] == 0)
                    {
                        flg = 0;
                        break;
                    }
                }
//                trace(u, v, flg);
                if(flg == 0)
                {
                    ff = 0;
                    break;
                }

                pq.push(MP(adj[v].size(), v));
            }


            CLR(mat1);
            for(auto v: adj[u]) mat1[v] = 1;
            int cnt = adj[u].size();
            while(!pq.empty())
            {
                pii p = pq.top(); pq.pop();

                int anyLuv = 0;
                for(auto v: adj[p.ss])
                {
                    if(mat1[v]) anyLuv = 1;
                    cnt -= mat1[v];
                    mat1[v] = 0;
                }
                if(mat1[p.ss]) anyLuv = 1;
                cnt -= mat1[p.ss];
                mat1[p.ss] = 0;
//                trace(u, p.ss, s.size(), anyLuv);

                if(anyLuv) edges.PB(MP(u, p.ss));
                if(cnt == 0) break;
            }

            if(cnt > 0)
            {
                ff = 0;
                break;
            }
        }


        ff = ff && (edges.size() == n-1);

        if(ff == 0) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            FOR(i,0,(int)edges.size()-1)
            {
                cout << edges[i].ff << " " << edges[i].ss << endl;
            }
        }
    }

    return 0;
}


