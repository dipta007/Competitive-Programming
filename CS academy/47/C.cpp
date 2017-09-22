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

int m1[304],m2[304];

vi factorize(int n)
{
    vi v;
    int nn = sqrt(n);
    for(int i=0; i<primes.size() && primes[i] <= nn; i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
            {
                n/=primes[i];
                v.PB(primes[i]);
            }
            nn= sqrt(n);
        }
    }
    if(n!=1) v.PB(n);
//    v.PB(1);
    return v;
}

vi a[304],b[304];

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    sieve(1e9);
    debug(primes.size())
    int n,m;
    while(~getII(n,m))
    {
        FOR(i,0,n)
        {
            a[i].clear();
            a[i].PB(1);
        }
        FOR(i,0,m)
        {
            b[i].clear();
            b[i].PB(1);
        }

        int gc[n][m];
        SET(m1);
        SET(m2);

        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                int x;
                getI(x);
                gc[i][j] = x;

                int tmp = x;
                if(m1[i]==-1)
                {
                    m1[i] = 1;
                    a[i] = factorize(x);
                    sort(ALL(a[i]));
                }
                else
                {
                    FOR(ik,0,(int)a[i].size()-1)
                    {
                        if(x%a[i][ik]==0) x/=a[i][ik];
                    }
                    int xx = sqrt(x);
                    for(int ii=0; ii<primes.size() && primes[ii] <= xx; ii++)
                    {
                        if(x%primes[ii]==0)
                        {
                            while(x%primes[ii]==0)
                            {
                                x/=primes[ii];
                                a[i].PB(primes[ii]);
                            }
                            xx = sqrt(x);
                        }
                    }
                    if(x!=1) a[i].PB(x);
                    sort(ALL(a[i]));
                }

                x = tmp;
                if(m2[j]==-1)
                {
                    m2[j] = 1;
                    b[j] = factorize(x);
                    sort(ALL(b[j]));
                }
                else
                {
                    FOR(ik,0,(int)b[j].size()-1)
                    {
                        if(x%b[j][ik]==0) x/=b[j][ik];
                    }
                    int xx = sqrt(x);
                    for(int ii=0; ii<primes.size() && primes[ii] <= xx; ii++)
                    {
                        if(x%primes[ii]==0)
                        {
                            while(x%primes[ii]==0)
                            {
                                x/=primes[ii];
                                b[j].PB(primes[ii]);
                            }
                            xx = sqrt(x);
                        }
                    }
                    if(x!=1) b[j].PB(x);
                    sort(ALL(b[j]));
                }
            }
        }

        int flg =1;

        ll na[n],nb[m];
        FOR(i,0,n-1)
        {
            na[i] = 1;
            FOR(j,0,(int)a[i].size()-1)
            {
                na[i] *= a[i][j];
            }
            if(na[i] > 1e9 || na[i]<1) flg = 0;
        }
        FOR(i,0,m-1)
        {
            nb[i] = 1;
            FOR(j,0,(int)b[i].size()-1)
            {
//                cout << a[i][j] << " ";
                nb[i] *= b[i][j];
            }
            if(nb[i] > 1e9 || nb[i]<1) flg = 0;
//            cout << endl;
        }
        if(flg){
        FOR(i,0,n-1)
        {
//            cout << i << " ";
            FOR(j,0,m-1)
            {
                ll gg = gcd(na[i], nb[j]);
                if(gg != gc[i][j])
                {
                    flg = 0;
                    break;
                }
            }
        }
        }

        if(flg)
        {
            FOR(i,0,n-1)
            {
                if(i) printf(" ");
                printf("%d",na[i]);
            }
            printf("\n");
            FOR(i,0,m-1)
            {
                if(i) printf(" ");
                printf("%d",nb[i]);
            }
            printf("\n");
        }
        else printf("-1\n");
    }

    return 0;
}



