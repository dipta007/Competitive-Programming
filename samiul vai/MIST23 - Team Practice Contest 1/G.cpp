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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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
#define    iseq(a,b)          (fabs(a-b)<EPS)
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

#define mx 100000000
bool Check(int N,int pos){ return (bool)(N & (1<<pos));}
int Set(int N,int pos){ return N=N | (1<<pos);}
int status[(mx/32)+2];
void sieve()
{
	int i, j;
     for( i = 3; i*i <=mx; i += 2 )
     {
		 if( Check(status[i>>5],i%31)==0)
	 		 for( j = i*i; j <= mx; j += (i<<1) )
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
     }
   	 puts("2");
	 for(i=3;i<=mx;i+=2)
		 if( Check(status[i>>5],i%31)==0)
            		printf("%d\n",i);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    vector <int> st;
    st.PB(1);
    map <int,bool> mp;
    mp[1]=1;
    for(int i=2;i<=10000;i+=2)
    {
        mp[i]=1;
        st.PB(i);
    }
    for(int i=3;i<=10000;i*=3)
    {
        mp[i]=1;
        st.PB(i);
    }
    for(int i=5;i<=10000;i*=5)
    {
        mp[i]=1;
        st.PB(i);
    }
    for(int i=7;i<=10000;i*=7)
    {
        mp[i]=1;
        st.PB(i);
    }

    vi v;
    FOR(i,0,(int)st.size()-1)
    {
        FOR(j,i+1,(int)st.size()-1)
        {
            ll k = (ll)st[i]*st[j];
            if(k>2000000000) continue;
            //debug(k)
            if(mp[k]==0)
            {
                mp[k]=1;
                v.PB(k);
            }
        }
    }


    sort(ALL(st));
    debug(v.size(),v[v.size()-1])
    debug(st.size(),st[st.size()-1])
    int n;
    while(~getI(n))http://www.cplusplus.com/reference/algorithm/merge/
    {
        if(n==0) break;
//        set <int> :: iterator it = st.begin();
//        it = it + n;

        int k = n%10;
        if(k==1)
        {
            printf("The %dst humble number is %d.\n",n,st[n-1]);
        }
        else if(k==2)
        {
            printf("The %dnd humble number is %d.\n",n,st[n-1]);
        }
        else if(k==3)
        {
            printf("The %drd humble number is %d.\n",n,st[n-1]);
        }
        else
        {
            printf("The %dth humble number is %d.\n",n,st[n-1]);
        }
    }


    return 0;
}



