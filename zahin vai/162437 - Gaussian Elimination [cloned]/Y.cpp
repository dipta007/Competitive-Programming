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


#define MAXROW 512
#define MAXCOL 512

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


ll modularInverse(ll a, ll modd) { 	// returns a er modular Inverse ; n dara mod kore
  pii ret = extendedEuclid(a, modd);
  return ((ret.ff % modd) + modd) % modd;
}

ll MOD(ll x, ll modd)
{
    return (x%modd+modd)%modd;
}


int gauss(int n, int m, ll ar[MAXROW][MAXCOL], ll modd, vector<ll>& res){
    res.assign(m, 0);
    vector <ll> pos(m, -1);
    int i, j, k, l, p, free_var = 0;

    for (j = 0, i = 0; j < m && i < n; j++){
        for (k = i, p = i; k < n; k++){
            if (labs(ar[k][j]) > labs(ar[p][j])) p = k;
        }

        if (labs(ar[p][j]) > 0){
            pos[j] = i;
            for (l = j; l <= m; l++) swap(ar[p][l], ar[i][l]);

            for (k = 0; k < n; k++){
                if (k != i){
                    ll upor = ar[k][j];
                    ll nich = ar[i][j];
                    nich = modularInverse(nich, modd);
                    ll x = ((ll)upor * nich)%modd;
                    for (l = j; l <= m; l++) ar[k][l] = MOD(ar[k][l] - ((ll)ar[i][l] * x)%modd , modd);
                }
            }
            i++;
        }
    }

    for (i = 0; i < m; i++){
        if (pos[i] == -1)
        {
            //cout << " free " << i << endl;

            free_var++;
        }
        else
        {
            ll upor = ar[pos[i]][m];
            ll nich = ar[pos[i]][i];
            nich = modularInverse(nich, modd);
            ll x = ((ll)upor * nich)%modd;
            res[i] = x;
        }
    }

    for (i = 0; i < n; i++) {
        ll val = 0;
        for (j = 0; j < m; j++) val = (val + ((ll)res[j] * ar[i][j])%modd )%modd;
        if (labs(val - ar[i][m]) > 0) return -1;
    }

    return free_var;
}

int n, m;
ll ar[MAXROW][MAXCOL];


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        vi v[n+4];
        FOR(i,1,n)
        {
            int x;
            while(getI(x))
            {
                if(x==-1) break;
                v[x].PB(i);
            }
        }
        FOR(i,1,n)
        {
            FOR(j,0,(int)v[i].size()-1)
            {
                int kk = v[i][j];
                ar[i-1][kk-1] = 1;
            }
            ar[i-1][n] = 1;
        }
        vector < ll > res;
        int free = gauss(n,n,ar,2,res);
        if(free==-1) printf("No solution\n");
        else
        {
            int flg=0;
            FOR(i,0,(int)res.size()-1)
            {
                if(res[i]==1)
                {
                    if(flg==0) printf("%d",i+1);
                    else printf(" %d",i+1);
                    flg=1;
                }
            }
            printf("\n");
        }
    }

    return 0;
}



