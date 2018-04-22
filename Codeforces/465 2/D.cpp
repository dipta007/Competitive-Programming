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
#define pll pair <ll, ll >

template< class T > inline T gcd(T a, T b)
{
    if(a==0 && b==0)
        return 1;
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    if(a==0 && b==0)
        return 1;
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#define dipta00
#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1<<" | ";
    __f(comma+1, args...);
}
#else
#define debug(args...)  /// Just strip off all debug tokens
#define trace(...) ///yeeeee
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

class Fraction
{
public:
    ll num, denom;

    void simplify()
    {
        debug(num , denom)
        ll g = gcd ( (num), (denom) );
        if(g == 0)
            return;
        num /= g;
        denom /= g;
        if ( denom < 0 )
        {
            num *= -1;
            denom *= -1;
        }

        ll mod = 1e9 + 7;
        num %= mod;
        denom %= mod;
    }


    ///First deal with initiation of the class
    Fraction ()
    {
        num = 0;
        denom = 1;
    }
    Fraction ( ll a, ll b )
    {
        num = a;
        denom = b;
        simplify();
    }
    Fraction ( ll x )
    {
        num = x;
        denom = 1;
    }
    Fraction ( pll x )
    {
        num = x.ff;
        denom = x.ss;
        simplify();
    }
    Fraction ( const Fraction &b )
    {
        num = b.num;
        denom = b.denom;
    }
    void operator = ( ll x )
    {
        num = x;
        denom = 1;
    }
    void operator = ( pll x )
    {
        num = x.ff;
        denom = x.ss;
        simplify();
    }
    void operator = ( Fraction b )
    {
        num = b.num;
        denom = b.denom;
    }

    ///Basic Arithmetic operations
    Fraction operator - ()   ///Negation
    {
        return Fraction( -num, denom );
    }
    Fraction operator + ( Fraction b )   ///Addition
    {
        Fraction res;
        res.denom = ( lcm(denom,b.denom) );
        res.num = (res.denom/denom)*num + (res.denom/b.denom)*b.num;
        res.simplify();
        return res;
    }
    Fraction operator - ( Fraction b )   ///Subtraction
    {
        return (*this) + (-b);
    }
    Fraction operator * ( Fraction b )
    {
        Fraction res ( b.num / gcd(b.num,denom), b.denom / gcd(b.denom,num) );
        res.num *= num / gcd(num,b.denom);
        res.denom *= denom / gcd(denom,b.num);
        res.simplify();
        return res;
    }
    Fraction operator / ( Fraction b )   ///Division
    {
        Fraction rev ( b.denom, b.num );
        if ( rev.denom < 0 )
        {
            rev.denom *= -1;
            rev.num *= -1;
        }
        return (*this)*rev;
    }

    ///Basic Arithmetic Operations overloaded
    void operator += ( Fraction b )
    {
        *this = *this + b;
    }
    void operator -= ( Fraction b )
    {
        *this = *this - b;
    }
    void operator *= ( Fraction b )
    {
        *this = *this * b;
    }
    void operator /= ( Fraction b )
    {
        *this = *this / b;
    }

    ///Comparison
    bool operator == ( Fraction b )
    {
        if ( num == b.num && denom == b.denom )
            return true;
        else
            return false;
    }
    bool operator < ( Fraction b )
    {
        if ( num * b.denom < b.num * denom )
            return true;
        else
            return false;
    }
    bool operator > ( Fraction b )
    {
        return ( b < *this );
    }
    bool operator <= ( Fraction b )
    {
        if ( *this == b || *this < b )
            return true;
        else
            return false;
    }
    bool operator >= ( Fraction b )
    {
        return ( b <= *this );
    }

    ///Output
    void print()
    {
        printf ( "%lld/%lld %f\n",num, denom, num/(denom-0.0) );
    }

    // Fraction getAbs()
    // {
    //     return Fraction(abs(num),denom);
    // }
};

ll s1[100004];
ll s2[100004];
Fraction dp[100004];
int vis[100004];
ll n,m;

Fraction cum[100004];


Fraction call(int in)
{
    debug("d", in)
    if(in >= n)
    {
        return Fraction(0,1);
    }
    Fraction &ret = dp[in];
    debug(in, vis[in])
    if(vis[in] == 1)
        return dp[in];

    vis[in] = 1;

    ret = Fraction(0,1);
//    debug(in, n, m)
    if(s1[in]==0 && s2[in]==0)
    {
        ret = cum[m];
        ret += Fraction(m, m*m) * call(in+1);
    }
    else if(s1[in]==0)
    {
        ret = ret + Fraction(1, m) * call(in+1);
        ret += Fraction(m-s2[in], m);
    }
    else if(s2[in] == 0)
    {
        ret = ret + Fraction(1, m) * call(in+1);
        ret += Fraction(s1[in]-1, m);
    }
    else
    {
        if(s1[in] == s2[in])
            (ret = call(in+1));
        else if(s1[in] > s2[in])
            (ret = Fraction(1,1));
        else
            return Fraction(0,1);
    }

    return ret;

}


pll extendedEuclid(ll a, ll b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
        return pll(1, 0);
    else
    {
        pll d = extendedEuclid(b, a % b);
        return pll(d.ss, d.ff - d.ss * (a / b));
    }
}


ll modularInverse(ll a, ll n)   	// returns a er modular Inverse ; n dara mod kore
{
    pll ret = extendedEuclid(a, n);
    return ((ret.ff % n) + n) % n;
}

ll mod = 1e9 + 7;


int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin >> n >> m)
    {
        FOR(i,0,n-1)
        {
            cin >> s1[i];
        }
        FOR(i,0,n-1)
        {
            cin >> s2[i];
        }

        cum[0] = Fraction(0, 1);
        Fraction kk = Fraction(1, m);
        FOR(i,1,m)
        {
            cum[i] = Fraction(1, m) * Fraction(i-1, m);
//            cum[i] =  Fraction(i-1, m);

//            debug(i)
//            cum[i].print();
            cum[i] += cum[i-1];
        }

        CLR(vis);

        dp[n] = Fraction(0,1);
        ROF(in,n-1,0)
        {
            debug(in)
            Fraction ret;
            if(s1[in]==0 && s2[in]==0)
            {
                ret = cum[m];
                ret += Fraction(1, m) * dp[in+1];
            }
            else if(s1[in]==0)
            {
                ret = ret + Fraction(1, m) * dp[in+1];
                ret += Fraction(m-s2[in], m);
            }
            else if(s2[in] == 0)
            {
                ret = ret + Fraction(1, m) * dp[in+1];
                ret += Fraction(s1[in]-1, m);
            }
            else
            {
                if(s1[in] == s2[in])
                    (ret = dp[in+1]);
                else if(s1[in] > s2[in])
                    (ret = Fraction(1,1));
                else
                    ret = Fraction(0,1);
            }

            dp[in] = ret;
        }

        Fraction res = dp[0];
//
//        res.print();

        ll ans = res.num%mod * modularInverse(res.denom, mod)%mod;
        ans %= mod;

        cout << ans << endl;
    }

    return 0;
}
