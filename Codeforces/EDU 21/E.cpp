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

vi v[4];
int a,b,c;
int minuss;

ll check(int val)
{
    if(val==1)
    {
        if(a>=v[1].size())
        {
            minuss = 0;
            return 0;
        }
        ll tmp = v[1][a];
        a++;
        minuss=1;
        return tmp;
    }
    else if(val==2)
    {
        ll sudhu1 = 0,k;
        for(k = 0;k<2 && a<v[1].size();k++,a++)
        {
            sudhu1 += v[1][a];
        }

        ll sudhu2 = 0,bf=0;
        if(b<v[2].size())
        {
            sudhu2 += v[2][b];
            bf=1;
            b++;
        }

        if(sudhu1 > sudhu2)
        {
            if(bf) b--;
            minuss = k;
            return sudhu1;
        }
        else if(sudhu2 > sudhu1)
        {
            a-=k;
            if(bf) minuss = 2;
            return sudhu2;
        }
        else if(sudhu1==sudhu2)
        {
            int m1 = k;
            int m2 = (bf==1) ? 2 : 0;
            if(m1<m2)
            {
                if(bf) b--;
                minuss = k;
                return sudhu1;
            }
            else
            {
                a-=k;
                if(bf) minuss = 2;
                return sudhu2;
            }
        }
    }
    else
    {
        ll sudhu1 = 0,k;
        int tmpA=a;
        for(k = 0;k<3 && a<v[1].size();k++,a++)
        {
            sudhu1 += v[1][a];
        }

        ll oneAndTwo = 0,af=0,bf=0;
        if(tmpA<v[1].size())
        {
            oneAndTwo += v[1][tmpA];
            tmpA++;
            af=1;
        }
        if(b<v[2].size())
        {
            oneAndTwo += v[2][b];
            b++;
            bf=1;
        }

        ll sudhu3=0,cf=0;
        if(c<v[3].size())
        {
            sudhu3 += v[3][c];
            c++;
            cf=1;
        }

        if(sudhu1 > oneAndTwo && sudhu1 > sudhu3)
        {
            if(bf) b--;
            if(cf) c--;
            minuss = k;
            return sudhu1;
        }
        else if(oneAndTwo > sudhu1 && oneAndTwo > sudhu3)
        {
            a-=k;
            if(af)
            {
                minuss +=1;
                a++;
            }
            if(cf) c--;
            if(bf) minuss+=2;
            return oneAndTwo;
        }
        else if(sudhu3 > sudhu1 && sudhu3 > oneAndTwo)
        {
            a-=k;
            if(bf) b--;
            if(cf) minuss = 3;
            return sudhu3;
        }
        else
        {
            int m1 = k;
            int m2=0;
            if(af) m2++;
            if(bf) m2 += 2;
            int m3= (cf==1) ? 3 : 0;
            if(m1 < m2 && m1 < m3)
            {
                if(bf) b--;
                if(cf) c--;
                minuss = k;
                return sudhu1;
            }
            else if(m2<m1 && m2<m3)
            {
                a-=k;
                if(af)
                {
                    minuss +=1;
                    a++;
                }
                if(cf) c--;
                if(bf) minuss+=2;
                return oneAndTwo;
            }
            else
            {
                a-=k;
                if(bf) b--;
                if(cf) minuss = 3;
                return sudhu3;
            }
        }
    }
    return 0;
}

vector < pii > vv;

int call(int in, int make)
{

}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    while(~getII(n,m))
    {
        v[1].clear();
        v[2].clear();
        v[3].clear();

        FOR(i,1,n)
        {
            int w,c;
            getII(w,c);
            v[w].PB(c);
        }

        sort(ALLR(v[1]));
        sort(ALLR(v[2]));
        sort(ALLR(v[3]));
        a=b=c=0;

        int flg=1;
        ll tot = 0;
        while(m > 200 && flg > 0)
        {
            minuss = 0;
            ll now = check(min(m,3));
            m -= minuss;
            flg = minuss;
            tot += now;
        }
        FOR(i,a)
        printf("%lld\n",tot);
    }

    return 0;
}


