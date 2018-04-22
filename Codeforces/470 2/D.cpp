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
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

struct node
{
    bool endmark;
    int cnt;
    node *next[2];
    node()
    {
        endmark=0;
        for(int i=0; i<2; i++)
            next[i]=NULL;
        cnt = 0;
    }
}*root;

void insert(int n)
{
    node *curr=root;
    for(int i=30; i>=0; i--)
    {
        int id=bitCheck(n,i);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        debug(id);
        curr=curr->next[id];
        curr->cnt++;
    }
    curr->endmark=1;

}
int find_max(int n)
{
    node *curr=root;
    int sum=0;
    for(int i=30; i>=0; i--)
    {
        int id=bitCheck(n,i);
        int inv=1-id;       //ja ache tar inverse ta khujtasi tai inverse nilam
        if(curr->next[inv]!=NULL)
        {
            sum=sum | (1<<i);   //jdi inverse pai tahola result er oi position a 1 set hba
            curr=curr->next[inv];
        }
        else
        {
            //na paila 0 set hba
            curr=curr->next[id];
        }
    }
    debug(sum);
    return sum;
}
int find_min(int n)
{
    node *curr=root;
    int sum=0;
    for(int i=30; i>=0; i--)
    {
        int id=bitCheck(n,i);
        int inv=1-id;

        debug(i, inv)
        if(curr->next[id]!=NULL && curr->next[id]->cnt > 0)
        {
            curr=curr->next[id];  //jdi inverse pai tahola result er oi position a 0 set hba
            curr->cnt--;
        }
        else
        {
            sum=sum | (1<<i); //na paila 1
            curr=curr->next[inv];
            curr->cnt--;
        }
    }
    return sum;
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
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        int a[n+4];
        root = new node();
        FOR(i,1,n)
        {
            int x;
            getI(x);
            a[i] = x;
        }
        debug("sad")

        FOR(i,1,n)
        {
            int x;
            getI(x);
            insert(x);
//            debug(x)
//            int kk = find_min(x);
//            if(i!=1) printf(" ");
//            printf("%d", kk);
        }

        FOR(i,1,n)
        {
            int kk = find_min(a[i]);

//            int kk = find_min(x);
            if(i!=1) printf(" ");
            printf("%d", kk);
        }

        printf("\n");

        del(root);
    }

    return 0;
}

