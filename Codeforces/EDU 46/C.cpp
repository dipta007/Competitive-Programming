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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    long long          ll;
typedef    pair < ll, ll>   pii;
typedef    unsigned long long ull;
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

/***
    Call root = new data();
    then execute all the operations on root
***/
struct data
{
    ll from, to;
    int sum, lazy;
    bool flg;
    data *left, *right;
    data()
    {
        from=0;
        to=1000000000000000000LL;
        sum=0;
        lazy=0;
        flg = 0;
        left=NULL;
        right=NULL;
    }
    void extend()
    {
        if(left==NULL)
        {
            left=new data();
            right=new data();
            left->from=from;
            left->to=(from+to)>>1;
            right->from = left->to + 1;
            right->to=to;
        }
    }
};

data *root;

void merge(data *node, data *a, data *b)
{
    node->flg = (a->sum != b->sum || a->sum ==-1 || b->sum == -1);
    node->sum = (node->flg == 1) ? -1 : a->sum;
}

void propagate(data *node)
{
    node->sum = node->lazy;
    if(node->from != node->to)
    {
        node->extend();
        node->left->lazy = node->sum;
        node->right->lazy = node->sum;
    }
    node->lazy=0;
}

void update(data *node, ll left, ll right)
{
    if(node->lazy) propagate(node);

    /// Not in the block
    if((node->from) > (node->to) || (node->from) > right || (node->to) < left) return;

    /// Right in the block
    if(node->from >= left && node->to <= right)
    {
        node->sum++;
        if(node->from != node->to)
        {
            node->extend();
            node->left->lazy = node->sum;
            node->right->lazy = node->sum;
        }
        return;
    }
    node->extend();
    update(node->left,left,right);
    update(node->right,left,right);
    merge(node, node->left, node->right);
}

unordered_map < int, ll> mp;
void dfs(data *node)
{
    if(node->lazy) propagate(node);
    if(node->sum && node->flg==0)
        trace(node->from, node->to, node->sum);
    if(node->flg == 0)
    {
        mp[node->sum] += (node->to - node->from + 1);
        return;
    }
    if(node->from != node->to)
    {
        if(node->left != NULL)
        {
            dfs(node->left);
        }
        if(node->right != NULL)
        {
            dfs(node->right);
        }
    }
}

bool comp(const pii &a, const pii &b)
{
    if(a.ff < b.ff) return true;
    if(a.ff == b.ff) return a.ss > b.ss;
    return false;
}
vector < pii > vp;

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(cin >> n)
    {
        vp.clear();
        root = new data();
        FOR(i,1,n)
        {
            ll x,y;
            cin >> x >> y;
            vp.PB( MP(x,y) );
        }
        sort(ALL(vp), comp);
        FOR(i,0,n-1)
        {
            ll x = vp[i].ff;
            ll y = vp[i].ss;
            update(root, x, y);
        }
        mp.clear();
        dfs(root);

        FOR(i,1,n)
        {
            if(i!=1) cout << " ";
            cout << mp[i];
        }
        cout << endl;
    }

    return 0;
}


