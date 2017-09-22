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

int k;
int arr[1000004];
int L[1000004];
int R[1000004];

int call(int l, int r)
{
    if(l>r) return 0;
    if(k==0)
    {
        return r-l+1;
    }
    int len = r-l+1;
    int mid = l+(len/2-1);;
    if(len%2==1) mid++;
    arr[mid]=k;
    k--;
    //debug(l,mid, r,k)

    int p2 = call(mid+1, r);
    int p1 = call(l, mid-1);
    return min(p1,p2);
}

#define piii pair <int, pii >

void bfs(int l, int r)
{
    priority_queue < piii > q;
    q.push(MP(r-l+1,MP(-l,r)));

    while(!q.empty())
    {
        piii p = q.top(); q.pop();
        p.ss.ff *= -1;
//        debug("*",p.ff,p.ss)
        if(p.ss.ff>p.ss.ss) continue;
        if(k==0) break;

        int len = p.ss.ss-p.ss.ff+1;
        int mid = (p.ss.ff+p.ss.ss)/2;
        //debug(p.ss.ff, p.ss.ss, mid)

        //if(arr[mid]!=0) debug("*")
//        debug(p.ff,p.ss,mid)
        //debug(mid)
        if(len%2==0)
        {
            arr[mid]=k;
            k--;
            q.push(MP(p.ss.ss-mid-1+1, MP(-mid-1, p.ss.ss)));
            q.push(MP(mid-1-p.ss.ff+1, MP(-p.ss.ff, mid-1)));
        }
        else
        {
            arr[mid]=k;
            k--;
            q.push(MP(mid-1-p.ss.ff+1, MP(-p.ss.ff, mid-1)));
            q.push(MP(p.ss.ss-mid-1+1, MP(-mid-1, p.ss.ss)));
        }
    }
}

int main() {
    #ifdef dipta007
        READ("inC1.txt");
        WRITE("outC.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getII(n,k);
        CLR(arr);
        CLR(L);
        CLR(R);
        bfs(1,n);

        arr[0]=1;
        FOR(i,1,n)
        {
            if(arr[i-1]>=1) L[i]=0;
            else L[i] = L[i-1]+1;
        }
        arr[n+1]=1;
        ROF(i,n,1)
        {
            if(arr[i+1]>=1) R[i]=0;
            else R[i] = R[i+1]+1;
        }

        int mini = INF;
        int maxy = -1;
        FOR(i,1,n)
        {
//            debug(i,arr[i])
            if(arr[i]==1)
            {
                //debug(i,L[i],R[i],arr[i+1])
                printf("Case #%d: %d %d\n",ci,max(L[i],R[i]), min(L[i],R[i]) );
                break;
            }
        }

//        printf("%d %d\n",maxy, mini);
    }

    return 0;
}


