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
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************

int mark[8][8];

int check(int row,int col)
{
    for(int i=col;i>=0;i--)
    {
        if(mark[row][i]) return 0;
    }
    for(int i=col;i<8;i++)
    {
        if(mark[row][i]) return 0;
    }
    for(int i=row;i>=0;i--)
    {
        if(mark[i][col]) return 0;
    }
    for(int i=row;i<8;i++)
    {
        if(mark[i][col]) return 0;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(mark[i][j]) return 0;
    }
    for(int i=row,j=col;i<8 && j<8;i++,j++)
    {
        if(mark[i][j]) return 0;
    }
    for(int i=row,j=col;i>=0 && j<8;i--,j++)
    {
        if(mark[i][j]) return 0;
    }
    for(int i=row,j=col;i<8 && j>=0;i++,j--)
    {
        if(mark[i][j]) return 0;
    }
    return 1;
}

int cii;
vector <string> vs;

void call(int row,int col)
{
    //debug(row,col);
    if(row>=8)
    {
        vi v;
        string st="";
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(mark[j][i])
                {
                    st+=(char)(j+48);
                    break;
                }
            }
        }
        vs.PB(st);
//        printf("%d     ",cii++);
//        for(int i=0;i<8;i++)
//        {
//            printf(" %d",v[i]);
//        }
//        printf("\n");

        return;
    }
    if(col>=8) return;

    int flg=1;
    for(int i=0;i<8;i++)
    {
        if(mark[row][i]==1)
            flg=0;
    }
    if(!flg) call(row+1,0);

//    if(check(row,col))
//    {
//        mark[row][col]=1;
//        call(row+1,0);
//        mark[row][col]=0;
//    }
//    call(row,col+1);
    for(int i=0;i<8;i++)
    {
        if(check(row,i))
        {
            mark[row][i]=1;
            call(row+1,0);
            mark[row][i]=0;
        }
    }

//    dp[row][col]=1;
    return;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        vs.clear();
        int n,m;
        getII(n,m);
        n--;
        m--;
        CLR(mark);
        mark[n][m]=1;
        cii=1;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        call(0,0);
        sort(ALL(vs));
        for(int i=0;i<vs.size();i++)
        {
            printf("%2d     ",i+1);
            for(int j=0;j<8;j++)
            {
                printf(" %c",vs[i][j]+1);
            }
            printf("\n");
        }
        if(ci<t) printf("\n");
    }

    return 0;
}

