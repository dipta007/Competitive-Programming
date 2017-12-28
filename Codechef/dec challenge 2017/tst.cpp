
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

#define dipta007
#ifdef dipta007
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

ll x,y,z;
ll a,b,c;

ll f1()
{
	// a
	ll aa = x+y+z;
	return aa * a;
}

// ll f2()
// {
// 	// b -> a
// 	vi v;
// 	v.PB(x);
// 	v.PB(y);
// 	v.PB(z);

// 	sort(ALL(v));

// 	ll bb = v[1];
// 	v[2] -= bb;
// 	v[1] = 0 ;

// 	ll tmp = min(v[0], v[2]);
// 	v[0] -= tmp;
// 	v[2] -= tmp;

// 	if(v[0] > 0)
// 	{
// 		ll baraiteParbo = min(bb, (ll)(v[0]/2));
// 		bb -= baraiteParbo;
// 		v[1] += baraiteParbo;
// 		v[2] += baraiteParbo;

// 		bb += baraiteParbo*2;

// 		v[0] -= baraiteParbo*2;
// 		v[1] -= baraiteParbo;
// 		v[2] -= baraiteParbo;

// 		bb += tmp;

// 		trace(v[0], v[1], v[2]);
// 	}

// 	debug(bb);
// 	ll aa = v[0] + v[1] + v[2];
// 	return aa*a + bb*b;
// }


ll f2()
{
	// b -> a
	vi v;
	v.PB(x);
	v.PB(y);
	v.PB(z);

	sort(ALL(v));

	ll bb = min(v[2] - v[1], v[0]);
	v[0] -= bb;
	v[2] -= bb;

	sort(ALL(v));

	if(v[0]==0)
	{
		bb += v[1];
		v[2] -= v[1];
		v[1] = 0;
	}
	else
	{
		ll mid = v[0]/2;
		bb += (mid*2);

		v[2] -= mid;
		v[1] -= mid;

		if(v[0]%2==1)
		{
			bb++;
			v[1]--;
		}
		v[0] = 0;

		sort(ALL(v));
		bb += v[1];
		v[2] -= v[1];
		v[1] = 0;

		//debug(bb);
	}

	ll aa = v[0] + v[1] + v[2];

	return aa*a + bb*b;
}


ll f6()
{
	//b -> c
	vi v;
	v.PB(x);
	v.PB(y);
	v.PB(z);

	sort(ALL(v));

	ll bb = min(v[2] - v[1], v[0]);
	v[0] -= bb;
	v[2] -= bb;

	sort(ALL(v));

	if(v[0]==0)
	{
		bb += v[1];
		v[2] -= v[1];
		v[1] = 0;
	}
	else
	{
		ll mid = v[0]/2;
		bb += (mid*2);

		v[2] -= mid;
		v[1] -= mid;

		if(v[0]%2==1)
		{
			bb++;
			v[1]--;
		}
		v[0] = 0;
		sort(ALL(v));
		bb += v[1];
		v[2] -= v[1];
		v[1] = 0;
	}

	//trace(v[0], v[1], v[2]);

	sort(ALL(v));
	if(v[0]==v[1] && v[1]==v[2])
	{
		ll cc = v[0];
		return bb*b + cc*c;
	}
	else return LONG_MAX;
}

ll f3()
{
	// c -> a
	vi v;
	v.PB(x);
	v.PB(y);
	v.PB(z);	

	sort(ALL(v));

	ll cc = v[0];
	v[0] -= cc;
	v[1] -= cc;
	v[2] -= cc;

	ll aa = v[0] + v[1] + v[2];

	return aa*a + cc*c;
}

ll f4()
{
	// c -> b -> a
	vi v;
	v.PB(x);
	v.PB(y);
	v.PB(z);	

	sort(ALL(v));

	ll cc = v[0];
	v[0] -= cc;
	v[1] -= cc;
	v[2] -= cc;

	sort(ALL(v));

	ll bb = v[1];
	v[1]-=bb;
	v[2]-=bb;

	ll aa = v[0] + v[1] + v[2];

	return aa*a + bb*b + cc*c;
}

ll f5()
{
	// c -> b
	vi v;

	v.PB(x);
	v.PB(y);
	v.PB(z);	

	sort(ALL(v));

	ll cc = v[0];
	v[0] -= cc;
	v[1] -= cc;
	v[2] -= cc;

	sort(ALL(v));

	ll bb = v[1];
	v[1] -= bb;
	v[2] -= bb;

	sort(ALL(v));

	//debug(bb,cc);

	if(cc >= v[2])
	{
		cc -= v[2];
		bb += v[2] * 2;

		//debug(bb,cc)
		return bb*b + cc*c;
	}
	else return LONG_MAX;
}
ll f7()
{
	// c -> b
	vi v;

	v.PB(x);
	v.PB(y);
	v.PB(z);	

	sort(ALL(v));

	ll cc = v[0];
	v[0] -= cc;
	v[1] -= cc;
	v[2] -= cc;

	sort(ALL(v));

	ll bb = v[1];
	v[1] -= bb;
	v[2] -= bb;

	sort(ALL(v));


	if(cc >= v[2])
	{
		cc -= v[2];
		bb += v[2] * 2;

		int tmp = cc/2;
		cc -= tmp * 2;
		bb += tmp * 3;

		return bb*b + cc*c;
	}
	else return LONG_MAX;
}


ll f()
{
	// trace(f1());
	// trace(f2());
	// trace(f3());
	// trace(f4());
	// trace(f5());
	// trace(f6());
	return min(f1(), min(f2(), min(f3(), min(f4(), min(f5(),min(f6(), f7()))))));
}

ll dp[104][104][104];

ll call(int i, int j, int k)
{
	if(i>x || j>y || k>z) return 100000;

	ll &ret = dp[i][j][k];
	if(ret!=-1) return ret;

	if(i==x && j==y && k==z) return ret = 0;

	ret = a + call(i+1, j, k);
	ret = min(ret, a + call(i, j+1, k));
	ret = min(ret, a + call(i, j, k+1));
	ret = min(ret, b + call(i+1, j+1, k));
	ret = min(ret, b + call(i+1, j, k+1));
	ret = min(ret, b + call(i, j+1, k+1));
	ret = min(ret, c + call(i+1, j+1, k+1));

	return ret;
}

int main() {
    #ifdef dipta007
        READ("out.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

	int t;
	getI(t);
	FOR(ci,1,t)
	{

		getLLL(x,y,z);
		getLLL(a,b,c);

		SET(dp);

		// debug(call(0,0,0), f());
		if(call(0,0,0) != f())
		{
			debug(call(0,0,0), f());
			trace(x,y,z,a,b,c);
		}

	}	

    return 0;
}


