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


#define MAXROW 512
#define MAXCOL 512

pii extendedEuclid(int a, int b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
		return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.ss, d.ff - d.ss * (a / b));
    }
}


int modularInverse(int a, int modd) { 	// returns a er modular Inverse ; n dara mod kore
  pii ret = extendedEuclid(a, modd);
  return ((ret.ff % modd) + modd) % modd;
}

ll MOD(ll x, ll modd)
{
    return (x%modd+modd)%modd;
}

struct GAUSS {
    int row, col;
    ll a[24][24];
    int mod;
	bool valid;
	GAUSS() {
        mod = xyz;
	}
    void clear () {
        memset ( a, 0, sizeof a );
    }
	void isValid ( int st ) {
		int i;
        valid = true;
		for ( i = st; i < row; i++ ) {
    	    if ( a[i][col-1] ) {
                valid = false;
                return;
    	    }
		}
	}
    ///Return Rank of Matrix
    ///Free variable = Variable - Rank or Col - Rank - 1
    int rank(){
        int i = 0, j = 0, k, r, u;
    	while(i < row && j < col - 1){
    		r = i;
    		for(k = i; k < row; k++)
                if(a[k][j]){
                    r = k; ///Find non-zero coefficient
                    break;
                }
    		if(a[r][j]){
    			if(r != i) ///Swap row if required
    				for(k = 0; k < col; k++)
    					swap(a[r][k], a[i][k]);

               ///Neutralize if required. Depends on whether double or modular division
                vlong v = a[i][j];
                v = modInv ( v, mod );
                for ( u = j; u < col; u++ ) {
                    a[i][u] = ( a[i][u] * v ) % mod;
                }
                /*
                double v = a[i][j];
                for ( u = j; u < col; u++ ) {
                    a[i][u] /= v;
                }
                */

    			for(u = i + 1; u < row; u++)
    				if(a[u][j]) { ///Eliminate
                        int v = a[u][j];
    					for(k = j; k < col; k++) {
    						a[u][k] = ( ( a[i][k] * v ) - a[u][k] ) % mod; ///Change here if no mod
                            if ( a[u][k] < 0 ) a[u][k] += mod;
    					}
    				}
    			i++;
    		}
    		j++;
    	}
    	return i;
    }

    void print() {
        FOR(i,0,row-1){
            FOR(j,0, col-1){
                printf ( "%d ", a[i][j] );
            }
            nl;
        }
    }
}mat;


int n, m;
int ar[MAXROW][MAXCOL];

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int a[20];
    while(~getI(a[0]))
    {
        mat.row = 20;
        mat.col = 20;
        mat.
        FOR(i,1,19)
        {
            getI(a[i]);
        }
        FOR(i,0,19)
        {
            if(i==0)
            {
                mat.a[i][i] = 1;
                mat.a[i][i+1] = 1;
                FOR(j,i+2,19) mat.a[i][j]=0;
            }
            else if(i==19)
            {
                mat.a[i][i] = 1;
                mat.a[i][i-1] = 1;
                FOR(j,0,i-2) mat.a[i][j] = 0;
            }
            else
            {
                mat.a[i][i-1] = 1;
                mat.a[i][i]=1;
                mat.a[i][i+1]=1;
                FOR(j,0,i-2) mat.a[i][j]=0;
                FOR(j,i+2,19) mat.a[i][j]=0;
            }
            ar[i][20] = a[i];
        }
        vi res;
        int xx = gauss(20, 20, ar, 2, res);
        int cnt = 0;
        FOR(i,0,(int)res.size()-1)
        {
            cnt += res[i];
        }
        printf("d %d\n",cnt);
    }

    return 0;
}




