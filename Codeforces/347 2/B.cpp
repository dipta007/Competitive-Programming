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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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
#define    bitCheck(N,in)    ((bool)(a&(1<<(k))))
#define    bitOff(N,in)      (a&(~(1<<(k))))
#define    bitOn(N,in)       (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

vi res;
int que,n,get;
vector <char> ope;

int main()
{
#ifdef dipta007
    READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007

    string st;
    while(getline(cin,st))
    {
        int len = st.size();
        ope.clear();
        que=0;
        int jog=0,biog=0;
        FOR(i,0,len-1)
        {
            if(st[i]=='?') que++;
            else if(st[i]=='=')
            {
                ope.PB(st[i]);
                string nn="";
                FOR(j,i+1,len-1)
                {
                    nn+=st[j];
                }
                //debug(nn)
                stringstream ss(nn);
                ss>>n;
                break;
            }
            else if(st[i]==' ') ;
            else
            {
                if(st[i]=='+') jog++;
                else biog++;
                ope.PB(st[i]);
            }
        }
        debug(jog,biog)
//        if(jog*n-biog<0)
//        {
//            printf("Impossible\n");
//            continue;
//        }
        if(jog>=biog)
        {
            if(jog+1-biog*n>n)
            {
                printf("Impossible\n");
            }
            else
            {
                printf("Possible\n");
                int j=1,b=jog-biog+1;
                printf("%d",n);
                FOR(i,1,que-1)
                {
                    printf(" %c ",ope[i-1]);
                    if(ope[i-1]=='+') printf("%d",j);
                    else
                    {
                        int k = min(n,b);
                        printf("%d",k);
                        b=b-k+1;
                    }
                }
                printf(" = %d\n",n);
            }
        }
        else if(jog<biog)
        {
            if(biog-jog*n>0)
            {
                printf("Impossible\n");
            }
            else
            {
                printf("Possible\n");
                int j=biog-jog+1,b=1;
                printf("%d",n);
                FOR(i,1,que-1)
                {
                    printf(" %c ",ope[i-1]);
                    if(ope[i-1]=='+')
                    {
                        int k = min(j,n);
                        printf("%d",k);
                        j=j-k+1;
                    }
                    else
                    {
                        printf("%d",b);
                        b=1;
                    }
                }
                printf(" = %d\n",n);
            }
        }
    }

    return 0;
}



