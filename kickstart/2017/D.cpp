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
const int INF = 10000;
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

int minimum, maximum, mean, median;

int check( vi v )
{
    sort(ALL(v));
    int len = v.size();
    if(v[0]!=minimum) return 0;
    if(v[len-1]!=maximum) return 0;

    FOR(i,0,len-1)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    int sum = 0;
    FOR(i,0,len-1)
    {
        sum += v[i];
    }
    if(sum%len!=0) return 0;
    if(sum/len != mean) return 0;

    if(len%2==0)
    {
        int m1 = len/2 -1;
        int m2 = m1 + 1;
        if(m1+m2/2 != median) return 0;
    }
    else
    {
        int mid = len/2;
        if(v[mid]!=median) return 0;
    }
    return 1;
}

int call(int in, vi v)
{
    if(in>14) return INF;
    if(v.size()>0 && check(v)==1)
    {
        return in;
    }

    int ret = INF;
    FOR(i,minimum, maximum)
    {
        v.PB(i);
        ret = min(ret, call(in+1, v));
        v.pop_back();
    }
    return ret;
}

vi v;
int xx[] = {3,4};

int dekh(int val, int mid, int in)
{
    int m1 = minimum * val;
    int m2 = v[mid] * val;
    int m3 = maximum * val;

    int drker = mean * (xx[in] + val*2);

    FOR(i,0,(int)v.size()-1)
    {
        drker -= v[i];
    }

    FOR(i,m1,m2)
    {
        int left = i;
        int right = drker - left;
//        if(val==2) debug(left, right, m1, m2, m3, (left >= m1 && left <= m2 && right >= m2 && right <= m3));
        if(left >= m1 && left <= m2 && right >= m2 && right <= m3)
        {
            return 1;
        }
    }
    return 0;
//    int left = drker % newMax;
//    int right = ()
}

int dekh1(int val)
{
    int m1 = minimum * val;
    int m2 = v[1] * val;
    int m3 = v[2] * val;
    int m4 = maximum * val;

    int drker = mean * (xx[1] + val*2);

    FOR(i,0,(int)v.size()-1)
    {
        drker -= v[i];
    }

    FOR(i,m1,m2)
    {
        int left = i;
        int right = drker - left;
//        if(val==1) debug(left, right, m1, m2, m3,m4, (left >= m1 && left <= m2 && right >= m3 && right <= m4));
        if(left >= m1 && left <= m2 && right >= m3 && right <= m4)
        {
            return 1;
        }
    }
    return 0;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        cin >> minimum >> maximum >> mean >> median;


        int flg = 1;
        if(maximum<minimum) flg= 0;
        if(!(mean>=minimum && mean<=maximum)) flg=0;
        if(!(median>=minimum && median<=maximum)) flg=0;

        cout << "Case #" << ci << ": ";
        if(flg==0)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        if(minimum==maximum && maximum==mean && mean==median)
        {
            cout << "1" << endl;
            continue;
        }

        int kk = minimum+maximum;
        if(kk%2==0 && kk/2==mean && kk/2==median)
        {
            cout << "2" << endl;
            continue;
        }

        v.clear();
        v.PB(minimum);
        v.PB(median);
        v.PB(maximum);

//        debug(dekh(0,1,0))
//        continue;

        int res = INF;
        FOR(i,0,5)
        {
            if(dekh(i, 1, 0)==1)
            {
//                debug(i)
                res = min(res, i*2+3);
            }
        }


        FOR(i,0,median*2)
        {
            int baki = median*2-i;
            FOR(j,0,median*2)
            {
                if((i+j)%2!=0 || (i+j)/2!=median) continue;
                v.clear();
                v.PB(minimum);
                v.PB(i);
                v.PB(j);
                v.PB(maximum);
                sort(ALL(v));

                FOR(k,0,5)
                {
//                    debug(i,j,k,dekh1(k))
                    if(dekh1(k))
                    {
                        res = min(res, k*2+4);
                    }
                }
            }
        }
//        v.clear();
//        v.PB(minimum);
//        v.PB(median);
//        v.PB(median);
//        v.PB(maximum);
//
//        FOR(i,0,5)
//        {
//            if(dekh(i, 1, 1))
//            {
//                res = min(res, i+4);
//            }
//        }

        if(res==INF) cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;

//        int low = 0, high = 100000000;
//        int res = -1;
//        while(low <= high)
//        {
//            int mid = (low + high) / 2;
//
//            if(dekh(mid))
//            {
//                res = mid;
//                high = mid-1;
//            }
//            else low = mid+1;
//        }
//        if(res==-1) cout << "IMPOSSIBLE" << endl;
//        else cout << res+3 << endl;
    }


    return 0;
}



