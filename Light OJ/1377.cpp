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
#ifdef dipta0
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

// 4 direction
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int adj[216][216];
int dist[2][216][216];

void bfs(int x, int y, int in)
{
    queue < int > q;
    q.push(x);
    q.push(y);
    dist[in][x][y] = 0;
    while(!q.empty())
    {
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();

        FOR(i,0,3)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(vx >= 0 && vy >= 0 && vx < n && vy < m)
            {
                if(adj[vx][vy] == 0 || adj[vx][vy] == 2)
                {
                    if(dist[in][vx][vy] > dist[in][ux][uy] + 1)
                    {
                        dist[in][vx][vy] = dist[in][ux][uy] + 1;
                        if(adj[vx][vy] == 0)
                        {
                            q.push(vx);
                            q.push(vy);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    #ifdef dipta007
        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        cin >> n >> m;

        FOR(i,0,1) FOR(j,0,n+4) FOR(k,0,m+4) dist[i][j][k] = 100000;
        CLR(adj);
        vector < pii > v;

        int sx, sy, dx, dy;
        FOR(i,0,n-1)
        {
            string st;
            cin >> st;
            FOR(j,0,m-1)
            {
                if(st[j] == '#') adj[i][j] = 1;
                else if(st[j] == 'P') sx = i, sy = j;
                else if(st[j] == 'D') dx = i, dy = j;
                else if(st[j] == '*') adj[i][j] = 2, v.PB(MP(i,j));
            }
        }

        bfs(sx, sy, 0);
        bfs(dx, dy, 1);

        int res = dist[0][dx][dy];
        trace(res);

        int mn1, mn2, in;
        mn1 = mn2 = 10000;
        if(v.size() >= 2)
        {
            vector < pii > in1, in2;
            FOR(i,0,(int)v.size()-1)
            {
                int x = v[i].ff;
                int y = v[i].ss;
                if(dist[0][x][y] < mn1)
                {
                    mn1 = dist[0][x][y];
                }
                res = min(res, dist[0][x][y] + dist[1][x][y] + 2);
            }
            FOR(i,0,(int)v.size()-1)
            {
                int x = v[i].ff;
                int y = v[i].ss;
                if(dist[1][x][y] < mn2)
                {
                    mn2 = dist[1][x][y];
                }
                res = min(res, dist[0][x][y] + dist[1][x][y] + 2);
            }

            FOR(i,0,(int)v.size()-1)
            {
                int x = v[i].ff;
                int y = v[i].ss;
                if(dist[0][x][y] == mn1) in1.PB(MP(x,y));
                if(dist[1][x][y] == mn2) in2.PB(MP(x,y));
            }

            trace(in1.size(), in2.size());
            FOR(i,0,(int)in1.size()-1)
            {
                FOR(j,0,(int)in2.size()-1)
                {
                    if(in1[i] == in2[j]) continue;

                    res = min(res, dist[0][in1[i].ff][in1[i].ss] + dist[1][in2[j].ff][in2[j].ss] + 1 );
                }
            }
//            res = min(res, mn1 + mn2 + 1);
        }


        if(res < 10000) cout << FMT("Case %d: %d\n", ci, res);
        else cout << FMT("Case %d: impossible\n", ci);
    }

    return 0;
}


