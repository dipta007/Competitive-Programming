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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R)        for (int i = (int)(L); i >= (int)(R); i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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
#define    vi                 vector < int >
#define    vii                vector < vector < int > >
#define    pii                pair< int, int >
#define    ff                 first
#define    ss                 second
#define    ll                 long long
#define    ull                unsigned long long
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
// int t,n,m;

//  structure for storing a cell's data
struct cell
{
    int x, y;
    ll dis;
    cell() {}
    cell(int x, int y, ll dis) : x(x), y(y), dis(dis) {}
};
 
//  Utility method returns true if (x, y) lies inside Board
bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}
 
//  Method returns minimum step to reach target position
ll minStepToReachTarget(int *knightPos, int *targetPos)
{
    //  x and y direction, where a knight can move
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
 
    //  queue for storing states of knight in board
    queue<cell> q;
 
    //  push starting position of knight with 0 distance
    q.push(cell(knightPos[0], knightPos[1], 0));
 
    cell t;
    int x, y;
    map < pii, bool> visit;
    
    visit.clear();
 
    //  visit starting state
    visit[ MP(knightPos[0], knightPos[1])] = true;
 
    //  loop untill we have one element in queue
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        visit[MP(t.x, t.y)] = true;
 
        // if current cell is equal to target cell,
        // return its distance
        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;
 
 
        //  loop for all reahable states
        for (int i = 0; i < 8; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];
 
            // If rechable state is not yet visited and
            // inside board, push that state into queue
            if(x > targetPos[0]+16 || x < targetPos[0]-16 || y > targetPos[1] + 16 || y<targetPos[1]-16) continue;

            if (!visit[MP(x,y)])
                q.push(cell(x, y, t.dis + 1));
 
        }
    }
}

ll distance(ll x, ll y)
{
    ll t;
    x = abs(x);
    y = abs(y);
    // diagonal symmetry 
    if (x < y) {
        t = x;x = y; y = t;
    }
    // 2 corner cases
    if(x==1 && y == 0){
        return 3;
    }
    if(x==2 && y == 2){
        return 4;
    }
    
    // main formula
    ll delta = x-y;
    if(y>delta){
        return delta - 2LL* floor((double)(delta-y)/3);
    }
    else{
        return delta - 2LL*floor((double)(delta-y)/4);
    }
}

pair < ll , ll > pos[20], tar[20];
ll dist[50][50];
ll dp[20][(1<<15)+1];
int n;

ll call(int in, int mask)
{
    // cout << mask << endl;
    if(bitCount(mask)==n) return 0;

    ll &ret = dp[in][mask];
    if(ret!=-1) return ret;

    ret = LONG_MAX;

    for(int i=0; i<n; i++)
    {
        if(bitCheck(mask, i)==0){ 
            ret = min(ret, dist[in][i] + call(in+1, bitOn(mask, i)));
            //debug(in, i, ret, dist[in][i])
        }
    }
    return ret;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
   ios_base::sync_with_stdio(0);cin.tie(0);

   //int n;
   int ci = 1;
   while( cin >> n )
   {
        if(n==0) break;
        for(int i=0; i<n;i ++)
        {
            cin >> pos[i].ff >> pos[i].ss;
        }
        for(int i=0; i<n;i ++)
        {
            cin >> tar[i].ff >> tar[i].ss;
        }

        CLR(dist);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                ll dx = 0 - pos[i].ff;
                ll dy = 0 - pos[i].ss;
                // int pp[] = {pos[i].ff-dx, pos[i].ss};
                ll tt[] = {tar[j].ff+dx, tar[j].ss+dy};

                dist[i][j] = distance(tt[0], tt[1]);

                //cout << i << " " << j << " " << tt[0] << " " << tt[1] << " " << dist[i][j] << endl;
            }
        }

        SET(dp);
        cout << ci++ <<  ". " << call(0,0) << endl;
   }


    return 0;
}


