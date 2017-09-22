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

struct data
{
    int num,male;
};

struct node
{
    data a[10];
    int step;
};

int check(node x)
{
    FOR(i,0,7)
    {
        if(x.a[i].num!=i+1) return 0;
    }
    return 1;
}

int vis[400004];
int fac[]={1,1,2,6,24,120,720,5040,40320};

int getHash(node x)
{
    int a[10],val=0,cnt;
	for(int i=0;i<8;i++)a[i]=abs(x.a[i].num);
	for(int i=0;i<8;i++){
		cnt=0;
		for(int j=0;j<i;j++){
			if(a[j]>a[i])cnt++;
		}
		val+=cnt*fac[i];
	}
	return val;
//    int val = 0;
//    FOR(i,0,7)
//    {
//        val += x.a[i].num * hashArr[i];
//    }
//    return val;
}

bool isPrime(int x)
{
    if(x==2 ) return true;
    if(x==3 ) return true;
    if(x==5 ) return true;
    if(x==7 ) return true;
    if(x==11) return true;
    if(x==13) return true;
    if(x==17) return true;
    if(x==19) return true;
    return false;
}

int find(node now, int val)
{
    FOR(i,0,7)
    {
        if(now.a[i].num==val) return i;
    }
}

node getNode(node now, int p1, int p2, int left)
{
    int pos1 = find(now, p1);
    int pos2 = find(now, p2);

    node next;
    next.step = now.step + 1;
    if(left) ///left e insert korbo p2 k
    {
        //if(pos1<pos2)
        {
            int in=0;
            FOR(i,0,pos1-1)
            {
                if(i==pos2) continue;
                next.a[in].num = now.a[i].num;
                next.a[in++].male = now.a[i].male;
            }
            next.a[in].male = now.a[pos2].male;
            next.a[in++].num = p2;

            FOR(i,pos1,7)
            {
                if(i==pos2) continue;
                next.a[in].male = now.a[i].male;
                next.a[in++].num = now.a[i].num;
            }
        }
    }
    else ///right e insert korbo p2 k
    {
        int in=0;
        FOR(i,0,pos1)
        {
            if(i==pos2) continue;
            next.a[in].male = now.a[i].male;
            next.a[in++].num = now.a[i].num;
        }
        next.a[in].male = now.a[pos2].male;
        next.a[in++].num = p2;
        FOR(i,pos1+1,7)
        {
            if(i==pos2) continue;
            next.a[in].male = now.a[i].male;
            next.a[in++].num = now.a[i].num;
        }
    }
    return next;
}

int BFS(node s)
{
    queue <node> q;
    q.push(s);
    CLR(vis);
    vis[ getHash(s) ] = 1;

    while(!q.empty())
    {
        node u = q.front(); q.pop();
        if(check(u))
        {
            //FOR(i,0,7) debug(u.a[i].num)
            return u.step;
        }

        FOR(i,0,7)
        {
            FOR(j,0,7)
            {
                if(i==j) continue;
                if(u.a[i].male!=u.a[j].male && isPrime(u.a[i].num + u.a[j].num))
                {
                    FOR(k,0,1)
                    {
                        node v = getNode(u, u.a[i].num, u.a[j].num, k);
                        int hh = getHash(v);
                        if(vis[ hh ]==0)
                        {
                            vis[hh]=1;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("in.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        node s;
        s.step=0;
        FOR(i,0,7)
        {
            int x;
            getI(x);
            if(x<0)
            {
                s.a[i].male=0;
                s.a[i].num=-x;
            }
            else
            {
                s.a[i].male=1;
                s.a[i].num=x;
            }
        }
        printf("Case %d: %d\n",ci,BFS(s));
    }

    return 0;
}


