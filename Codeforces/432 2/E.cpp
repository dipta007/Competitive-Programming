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

#define M 1000000
bool marked[M];
vector <int> primes;

void sieve(int n) {
	primes.push_back(2);
	for (ll i = 3; i * i <= n; i += 2) {
		if (marked[i] == 0) {
			primes.push_back(i);
			for (ll j = i * i; j*j <= n; j += i + i) {
				marked[j] = 1;
		}
    }
  }
}

vector <int> s[100000];

map <int, int> dp[104][104];
int in;

int call(int i, int j, int now)
{
    debug(i,j,now)
    if(i >= in) return 0;
    if(j >= s[i].size()) return call(i+1, 0, 0);

    debug(i,s[i][j],now, in)

    //if(dp[j][now].find(i) != dp[j][now].end()) return dp[j][now][i];

    FOR(ik,now+1, s[i][j])
    {
        if(!call(i, j+1, ik)) return dp[j][now][i] = 1;
    }
    return dp[j][now][i] = 0;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    sieve(1e9);
    while(~getI(n))
    {
        int a[n+4];
        FOR(i,1,n)
        {
            getI(a[i]);
        }

        map <int, int> mp,rev;
        in = 1;

        FOR(i,1,n)
        {
            int x = a[i];
            int xx = sqrt(x);
            for(int j=0;j<primes.size() && primes[j] <=xx; j++)
            {
                if(x%primes[j]==0)
                {
                    int cnt = 0;
                    while(x%primes[j]==0)
                    {
                        x /= primes[j];
                        cnt++;
                    }
                    if(mp[primes[j]]==0)
                    {
                        s[in].clear();
                        rev[in] = primes[j];
                        mp[primes[j]] = in++;
                    }

                    s[mp[primes[j]]].PB(cnt);
                }
            }

            if(x!=1)
            {
                if(mp[x]==0)
                {
                    s[in].clear();
                    rev[in] = x;
                    mp[x] = in++;
                }
                s[mp[x]].PB(1);
            }
        }

        FOR(i,1,in)
        {
            sort(ALL(s[i]));
            UNIQUE(s[i]);
        }

        int res = call(1,0,0);
        debug(res);
//
//        int res = 0;
//        FOR(i,1,in-1)
//        {
//            for(auto x: s[i])
//            {
//                res ^= 1;
//                debug(i, x)
//            }
////            res += s[i].size();
////            res %= 2;
////            debug(rev[i], s[i].size())
//        }
        if(res==0) printf("Arpa\n");
        else printf("Mojtaba\n");
    }

    return 0;
}



