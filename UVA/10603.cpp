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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    rep(i,n)          for(i=1;i<=n;i++)
#define    repI(i,n)         for(i=0;i<n;i++)
#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< ll, ll >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
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

int bitOn(int N,int pos)
{
    return N=N | (1<<pos);
}
int bitOff(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool bitCheck(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
//
//int ext_gcd ( int A, int B, int *X, int *Y ){
//    int x2, y2, x1, y1, x, y, r2, r1, q, r;
//    x2 = 1; y2 = 0;
//    x1 = 0; y1 = 1;
//    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
//        q = r2 / r1;
//        r = r2 % r1;
//        x = x2 - (q * x1);
//        y = y2 - (q * y1);
//    }
//    *X = x2; *Y = y2;
//    return r2;
//}
//
//bool linearDiophantine ( int A, int B, int C, int *x, int *y ) {
//    int g = gcd ( A, B );
//    if ( C % g != 0 ) return false; //No Solution
//
//    int a = A / g, b = B / g, c = C / g;
//    ext_gcd( a, b, x, y ); //Solve ax + by = 1
//
//    if ( g < 0 ) { //Make Sure gcd(a,b) = 1
//        a *= -1; b *= -1; c *= -1;
//    }
//
//    *x *= c; *y *= c; //ax + by = c
//    return true; //Solution Exists
//}

pii extendedEuclid(ll a, ll b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
		return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.ss, d.ff - d.ss * (a / b));
    }
}


ll modularInverse(ll a, ll n) { 	// returns a er modular Inverse ; n dara mod kore
  pii ret = extendedEuclid(a, n);
  return ((ret.ff % n) + n) % n;
}

int dist[204][204][204];
int water[204][204][204];
bool visited[204][204][204];
int result[204];
int a,b,c,d;

void bfs3d(int i,int j,int k)
{
    CLR(visited);
    visited[i][j][k]=1;
    water[i][j][k]=0;
    result[i]=0;
    result[j]=0;
    result[k]=0;

    queue <int> q;
    q.push(i);
    q.push(j);
    q.push(k);

    while(!q.empty())
    {
        int aa = q.front(); q.pop();
        int bb = q.front(); q.pop();
        int cc = q.front(); q.pop();

//        visited[aa][bb][cc]=1;

        int x,y,z;
        ///a to b
        y=bb+min(aa,b-bb);
        x=aa-min(aa,b-bb);
        z=cc;
        if(visited[x][y][z]==0)
        {
            visited[x][y][z]=1;
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(aa,b-bb);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        else if(water[x][y][z]>water[aa][bb][cc]+min(aa,b-bb))
        {
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(aa,b-bb);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        ///a to c
        z=cc+min(aa,c-cc);
        y=bb;
        x=aa-min(aa,c-cc);
        if(visited[x][y][z]==0)
        {
            visited[x][y][z]=1;
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(aa,c-cc);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        else if(water[x][y][z]>water[aa][bb][cc]+min(aa,c-cc))
        {
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(aa,c-cc);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        ///b to a
        x=aa+min(bb,a-aa);
        y=bb-min(bb,a-aa);
        z=cc;
        if(visited[x][y][z]==0)
        {
            visited[x][y][z]=1;
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(bb,a-aa);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        else if(water[x][y][z]>water[aa][bb][cc]+min(bb,a-aa))
        {
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(bb,a-aa);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        ///b to c
        z=cc+min(bb,c-cc);
        y=bb-min(bb,c-cc);
        x=aa;
        if(visited[x][y][z]==0)
        {
            visited[x][y][z]=1;
            q.push(x); q.push(y); q.push(z);
            water[x][y][z]=water[aa][bb][cc]+min(bb,c-cc);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        else if(water[x][y][z]>water[aa][bb][cc]+min(bb,c-cc))
        {
            q.push(x); q.push(y); q.push(z);
            water[x][y][z]=water[aa][bb][cc]+min(bb,c-cc);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        ///c to a
        x=aa+min(cc,a-aa);
        y=bb;
        z=cc-min(cc,a-aa);
        if(visited[x][y][z]==0)
        {
            visited[x][y][z]=1;
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(cc,a-aa);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        else if(water[x][y][z]>water[aa][bb][cc]+min(cc,a-aa))
        {
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(cc,a-aa);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        ///c to b
        x=aa;
        y=bb+min(cc,b-bb);
        z=cc-min(cc,b-bb);
        if(visited[x][y][z]==0)
        {
            visited[x][y][z]=1;
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(cc,b-bb);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
        else if(water[x][y][z]>water[aa][bb][cc]+min(cc,b-bb))
        {
            q.push(x); q.push(y); q.push(z);

            water[x][y][z]=water[aa][bb][cc]+min(cc,b-bb);
            if(water[x][y][z]<result[x]) result[x]=water[x][y][z];
            if(water[x][y][z]<result[y]) result[y]=water[x][y][z];
            if(water[x][y][z]<result[z]) result[z]=water[x][y][z];
        }
    }
}

int main() {
//    READ("in.txt");
//    WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        getII(a,b);
        getII(c,d);
        for(int i=0;i<=200;i++) result[i]=INF;
        bfs3d(0,0,c);
        int res=INF,steps;
        int flg=0,i;
        for(i=d;i>=0;i--)
        {
            if(result[i]<res)
            {
                res=result[i];
                break;
            }
        }
//        for(i=d;!flg && i>=0;i--)
//        {
//            for(int j=0;j<=b;j++)
//            {
//                for(int k=0;k<=c;k++)
//                {
//                    if(visited[i][j][k])
//                    {
//                        flg=1;
//                        if(water[i][j][k]<res)
//                        {
//                            res=water[i][j][k];
//                            steps=dist[i][j][k];
//                        }
//                    }
//                }
//            }
//            for(int j=0;j<=a;j++)
//            {
//                for(int k=0;k<=c;k++)
//                {
//                    if(visited[j][i][k])
//                    {
//                        flg=1;
//                        if(water[j][i][k]<res)
//                        {
//                            res=water[j][i][k];
//                            steps=dist[j][i][k];
//                        }
//                    }
//                }
//            }
//            for(int j=0;j<=b;j++)
//            {
//                for(int k=0;k<=a;k++)
//                {
//                    if(visited[k][j][i])
//                    {
//                        flg=1;
//                        if(water[k][j][i]<res)
//                        {
//                            res=water[k][j][i];
//                            steps=dist[k][j][i];
//                        }
//                    }
//                }
//            }
//        }
        printf("%d %d\n",res,i);
    }

    return 0;
}

