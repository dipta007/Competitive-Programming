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
#include <unordered_map>
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

#define dipta00
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

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out
#define M 1000004
bool marked[M];
vector <int> primes;

void sieve(ll n) {
	primes.push_back(2);
	for (ll i = 3; i * i <= n; i += 2) {
		if (marked[i] == 0) {
			for (ll j = i * i; j * j <= n; j += i + i) {
				marked[j] = 1;
		}
    }
  }

  for(int i=3; i*i<=n; i+=2) if(marked[i] == 0) primes.PB(i);
}

// prime number sob serially "primes" vector e save hobe
// like primes[0]=2,primes[1]=3 and so on

vector < ll > v;
ll a[3];


//struct HASH{
//  size_t operator()(const pair< pii ,int>&x)const{
//    ll kk = hash<long long>()(((long long)x.ff.ff)^(((long long)x.ff.ss)<<32));
//    return hash<long long>()(((long long)kk)^(((long long)x.second)<<32));
//  }
//};
//unordered_map<pair<pii,int>,int,HASH>mp;
//unordered_map < int, int > mark[3][70];
//
//ll call(ll in, ll x, ll y, ll z)
//{
////        debug(in, x,y,z)
//    if(in >= v.size())
//    {
////        if(mp[MP(MP(x,y), z)] == 0)
////        {
////            mp[MP(MP(x,y), z)]  = 1;
////            return 1;
////        }
//        return 0;
//    }
//
//    ll ret = 0;
//    if(x * v[in] <= a[0] )//&& mark[0][in][v[in]] == 0)
//    {
////        mark[0][in][v[in]] = 1;
//        ret += call(in+1, x*v[in], y, z);
//    }
//    if(y * v[in] <= a[1])// && mark[1][in][v[in]] == 0)
//    {
////        mark[1][in][v[in]] = 1;
//        ret += call(in+1, x, y*v[in], z);
//    }
//    if(z * v[in] <= a[2])// && mark[2][in][v[in]] == 0)
//    {
////        mark[2][in][v[in]] = 1;
//        ret += call(in+1, x, y, z*v[in]);
//    }
//    return ret;
//}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    sieve(1000000000);
    FOR(ci,1,t)
    {
        ll n;
        getL(n);
        FOR(i,0,2) getL(a[i]);

        if(n==1)
        {
            printf("1\n");
            continue;
        }

        sort(a,a + 3);

        int nn = sqrt(n);

        v.clear();

        FOR(i,1,nn)
        {
            if(n%i == 0)
            {
                v.PB(i);
                if(n/i != i) v.PB(n/i);
            }
        }

        sort(ALL(v));

        debug(v.size())

        int cnt = 0;

        FOR(i,0,(int)v.size()-1)
        {
//            debug(v[i])
            if(v[i] > a[0]) break;
            if(v[i] <= a[0])
            {
                FOR(j,0,(int)v.size()-1)
                {
                    if(v[j] > a[1]) break;

                    ll kk = n/ v[i];

                    if(kk % v[j] != 0) continue;
                    ll now = kk / v[j];

                    if(now <= a[2]) cnt++;
//                    if(v[j] <= a[1] && v[i]*v[j] <= n && i!=j)
//                    {
//                        FOR(k, 0, (int)v.size()-1)
//                        {
//                            if(v[k] > a[2]) break;
//                            if(j!= k && i!=k && v[i] * v[j] * v[k] == n) cnt++;
//                        }
//                    }
                }
            }
        }

        printf("%d\n",cnt);
        continue;

//        v.clear();
//        map <int, int > mp;
//        for(int i=0; i<primes.size(); i++)
//        {
//            if( n % primes[i] == 0)
//            {
//                while( n % primes[i] == 0 )
//                {
//                    v.PB(primes[i]);
//                    n /= primes[i];
//                    mp[ primes[i] ] ++;
//                }
//
//                nn = sqrt(n);
//            }
//        }
//
//        if(n != 1) v.PB(n);
//        debug(v.size())
//
//        mp.clear();
//        ll res = call(0, 1, 1, 1);

//        debug(res)
//
//        for(auto x: mp)
//        {
//            debug(x.ff, x.ss)
//            FOR(i,2,x.ss)
//            {
//                res /= i;
//            }
//        }


//        printf("%lld\n", res);
    }

    return 0;
}

