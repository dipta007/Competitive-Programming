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
//#include <bits/stdc++.h>
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
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

struct data
{
    int from, to;
    int sum, lazy;
    data *left, *right;
    data()
    {
        from=0;
        to=1e9;
        sum=0;
        lazy=0;
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

void propagate(data *node)
{
    node->sum = max(node->sum, node->lazy);
    if(node->from != node->to)
    {
        node->extend();
        node->left->lazy = max(node->left->lazy, node->lazy);
        node->right->lazy = max(node->lazy, node->right->lazy);
    }
    node->lazy=0;
}

void merge(data *node)
{
    node->sum = max(node->left->sum, node->right->sum);
}

void update(data *node, int left, int right, int newVal)
{
    if(node->lazy) propagate(node);

    /// Not in the block
    if((node->from) > (node->to) || (node->from) > right || (node->to) < left) return;
    /// Right in the block
    if(node->from >= left && node->to <= right)
    {
        node->sum = max(node->sum, newVal);
        if(node->from != node->to)
        {
            if(node->left == NULL) node->extend();
            node->left->lazy = max(node->left->lazy, newVal);
            node->right->lazy = max(node->right->lazy, newVal);
        }
        return;
    }
    if(node->left == NULL) node->extend();
    update(node->left,left,right,newVal);
    update(node->right,left,right,newVal);
    merge(node);
}

int query(data *node, int left, int right)
{
    /// Not in the block
    if((node->from) > (node->to) || (node->from) > right || (node->to) < left) return 0;

    if(node->lazy) propagate(node);

    if(node->from >= left && node->to <= right)
    {
        return node->sum;
    }

    if(node->left == NULL) node->extend();
    int q1=query(node->left, left, right);
    int q2=query(node->right, left, right);
    return max(q1,q2);
}

vector < pair < int, pii > > vp;

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        vp.clear();
        FOR(i,1,n)
        {
            int x,y,h;
            getIII(x,y,h);
            vp.PB(MP(x, MP(y, h)));
            vp.PB(MP(y, MP(y, 0)));
//            vp.PB(MP(y, MP(h, -1)));
        }

        root = new data();

        sort(ALL(vp));
        int px = vp[0].ff;
        ll res=  0;
        FOR(i,0,(int)vp.size()-1)
        {
            pair < int , pii > p = vp[i];
            ll h = query(root, px+1, p.ff);
            res += (h * (ll)(p.ff-px));

            trace(p.ff, p.ss.ff, p.ss.ss, h, px, res);
            px = p.ff;
            update(root, p.ff, p.ss.ff, p.ss.ss);
        }
        pf("%lld\n", res);
    }

    return 0;
}

