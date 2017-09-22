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
#define    PB(x)             push_back(x)s
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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

struct node
{
    bool endmark;
    int cnt;
    node *next[2];
    node()
    {
        cnt = 0;
        endmark=0;
        for(int i=0; i<2; i++)
            next[i]=NULL;
    }
}*root;

void insert(int n)
{
    node *curr=root;
    for(int i=30; i>=0; i--)
    {
        int id=bitCheck(n,i);
        //debug(id);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
        curr->cnt++;
    }
    curr->endmark=1;
}

void remove(int n)
{
    node *curr=root;
    for(int i=30; i>=0; i--)
    {
        int id=bitCheck(n,i);
        //debug(id);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
        curr->cnt--;
    }
    curr->endmark=1;
}

int find(int p, int l)
{
    node *curr = root;

    int res = 0;
    int in;
    ROF(i,30,0)
    {
        int flg = 0;
        int pBit = bitCheck(p,i);
        int lBit = bitCheck(l,i);
        //debug(pBit, lBit,p, l,i)


        if(curr->next[0]!=NULL)
        {
            if((pBit^0) < lBit) res += curr->next[0]->cnt;
            else if((pBit^0) == lBit)
            {
                in = 0;
                flg=1;
            }
        }
        if(curr->next[1]!=NULL)
        {
            if((pBit^1) < lBit) res += curr->next[1]->cnt;
            else if((pBit^1) == lBit)
            {
                flg=1;
                in=1;
            }
        }

        //debug(i, pBit, lBit, flg, res, pBit^1<lBit, pBit^0<lBit)
        if(flg==0) break;
        curr = curr->next[in];
    }
    return res;
}

void del(node *cur)				// send root here
{
    for(int i=0; i<2; i++)
        if(cur->next[i])
            del(cur->next[i]) ;
    delete(cur) ;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        root = new node();
        FOR(i,1,n)
        {
            int t;
            getI(t);
            if(t==1)
            {
                int x;
                getI(x);
                insert(x);
            }
            else if(t==2)
            {
                int x;
                getI(x);
                remove(x);
            }
            else
            {
                int p,l;
                getII(p,l);
                printf("%d\n",find(p,l));
            }
        }



        del(root);
    }

    return 0;
}



