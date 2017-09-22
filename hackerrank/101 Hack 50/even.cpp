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

ll arr[100004];
int mark[100004];


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    int t;
    getI(t);
    FOR(ci,1,t)
    {
        getI(n);
        FOR(i,0,n-1)
        {
            getL(arr[i]);
        }

        CLR(mark);
        int cnt = 0;
        vi v;
        FOR(i,0,n-1)
        {
            if(arr[i]%2==i%2) mark[i]=1;
            else
            {
                debug(i)
                v.PB(arr[i]);
                cnt++;
            }
        }
        if(cnt%2==1)
        {
            printf("-1\n");
            continue;
        }
        if(cnt==0)
        {
            printf("0\n");
            continue;
        }
        sort(ALLR(v));

        int lagbe = (int)v.size()/2;
        ll sum = 0;
        FOR(i,0,(int)v.size()-1)
        {
            sum += (ll)v[i];
        }
        sum -= (ll)v.size();
        debug(sum, lagbe)
        if(sum<lagbe) printf("-1\n");
        else
        {
//            int in=0,in1=v.size()-1;
            int res = 0,vlo=0;
            vi vv;
            FOR(i,0,(int)(v.size()/2)-1)
            {
                debug(i,v[i])
                if(v[i]==1) res += 2;
                else
                {
                    vv.PB(v[i]);
                    vlo++;
                    res ++;
                }
            }
            //if(vlo%2==res%2)
            {
                sort(ALL(vv));
                int ans = 0;
                FOR(i,0,(int)vv.size()-1)
                {
                    if(vv[i]%2==0)
                    {
                        int kk = min(res, vv[i]-1);
                        ans += kk;
                        res -= kk;
                    }
                    else
                    {
                        int kk = min(res, vv[i]-2);
                        ans += kk;
                        res -= kk;
                    }
                }
                if(res!=0) printf("-1\n");
                else printf("%d\n",ans);
//                printf("%d\n",res);
            }
            //else printf("-1\n");
//            printf("%d\n",res);
        }
    }

    return 0;
}



