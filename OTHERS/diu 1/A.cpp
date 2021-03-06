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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************



#define M 1000000
bool marked[M];
vector<int> primes; // we'll preload primes once at the beginning

void sieve(int n) {
	primes.push_back(2);
	for (ll i = 3; i<= n; i += 2) {
		if (marked[i] == 0) {
			primes.push_back(i);
			for (ll j = i * i; j <= n; j += i + i) {
				marked[j] = 1;
		}
    }
  }
}

map <int,int> mp;

int countPrimeDivisor(int n)
{
    int cnt = 0;
    for (int i = 0; i < primes.size(); i++)
    {
        if (n % primes[i] == 0)
        {

            while (n % primes[i] == 0)
            {
                mp[primes[i]]++;

                n /= primes[i];

            }
            cnt++;
        }
    }
    if(n>1) mp[n]++;
    return cnt;
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    //8 128
    sieve(50000);
    int n,m;
    while(~getII(n,m))
    {
        if(m==0)
        {
            printf("0 does not divide %d!",n);
            continue;
        }
        mp.clear();
        countPrimeDivisor(m);
        int flg=1;
        for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
        {
            int konta = it->first;
            int koto = it->second;
            //debug(konta,koto);
            int c=1;
            int cnt=koto;
            for(int j=1;j<=cnt;j++)
            {
                c=j*konta;
                //debug(c);
                if(c>n)
                {
                    break;
                }
                else
                {
                    while(c%konta==0)
                    {
                        koto--;
                        c/=konta;
                    }
                }
            }
            //debug(koto);
            if(koto>0) {flg=0;break;}
        }
        if(flg) printf("%d divides %d!\n",m,n);
        else printf("%d does not divide %d!\n",m,n);
    }

    return 0;
}

