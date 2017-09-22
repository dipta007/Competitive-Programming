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

const int MAX_N = 600004;
string text;
int N, m, SA [MAX_N], LCP [MAX_N];
int x [MAX_N], y [MAX_N], w [MAX_N], c [MAX_N];
int SAfrom[MAX_N];

inline bool cmp (const int a, const int b, const int l)
{
    return (y [a] == y [b] && y [a + l] == y [b + l]);
}

void Sort ()
{
    for (int i = 0; i < m; ++i) w [i] = 0;
    for (int i = 0; i < N; ++i) ++w [x [y [i]]];
    for (int i = 0; i < m - 1; ++i) w [i + 1] += w [i];
    for (int i = N - 1; i >= 0; --i) SA [--w [x [y [i]]]] = y [i];
}

void DA ()
{
    ++N;
    for (int i = 0; i < N; ++i) x [i] = text [i], y[i] = i;
    Sort ();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p)
    {
        for (p = 0, i = N - j; i < N; i++) y [p++] = i;
        for (int k = 0; k < N; ++k) if (SA [k] >= j) y [p++] = SA [k] - j;
        Sort ();
        for (swap (x, y), p = 1, x [SA [0]] = 0, i = 1; i < N; ++i) x [SA [i]] = cmp (SA [i - 1], SA [i], j) ? p - 1 : p++;
    }
    for (int i = 1; i < N; ++i) SA [i - 1] = SA [i];
    --N;
}

void kasaiLCP ()
{
    for (int i = 0; i < N; ++i) c [SA [i]] = i;
    LCP [0] = 0;
    for (int i = 0, h = 0; i < N; ++i) if (c[i] > 0)
        {
            int j = SA [c [i] - 1];
            while (i + h < N && j + h < N && text [i + h] == text [j + h]) ++h;
            LCP [c [i]] = h;
            if (h > 0) --h;
        }
}

void suffixArray ()
{
    m = 256;
    N = text.size();
    DA ();
    kasaiLCP ();
}

int main() {
    #ifdef dipta007
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,ff=0;
    while(cin >> n)
    {
        if(n==0) break;
        if(ff) cout << endl;
        ff=1;

        int len;
        text = "";
        int in = 0;
        FOR(i,1,n)
        {
            string st;
            cin >> st;
            text += st;
            if(i!=n) text +="$";
            int indx = in;
            while(indx < in+st.size()+1)
            {
                SAfrom[indx++] = i;
            }
            in=indx;
        }
        if(n==1)
        {
            cout << text << endl;
            continue;
        }
        suffixArray();
        len = text.size();
        int col[104];
        CLR(col);
        int maxy=0;

        /// more than half of total number strings e thakte hbe same pattern
        int half = n/2;
        set < string> res;

        FOR(i,0,len-1)
        {
            if(LCP[i]>=maxy)
            {
                CLR(col);
                int cnt = 1;
                int ik=1;

                /// joto pisone jaoa jai
                ROF(j,i,1)
                {
                    if(LCP[j]>=LCP[i])
                    {

                    }
                    else
                    {
                        ik=j;
                        break;
                    }
                }
                /// Oi position k color korlam
                col[SAfrom[SA[ik]]]=1;
                /// dn ar koto samne jaoa jai
                FOR(j,ik+1,len-1)
                {
                    if(LCP[j]>=LCP[i])
                    {
                        if(col[SAfrom[SA[j]]]==0 && SAfrom[SA[j]]==SAfrom[SA[j]+LCP[i]-1])
                        {
                            col[SAfrom[SA[j]]]=1;
                            cnt++;
                        }
                    }
                    else break;
                }

                debug(cnt,half)
                /// count jodi half er cheye besi hoi
                if(cnt > half)
                {
                    string now = text.substr(SA[i], LCP[i]);
                    if(now[now.size()-1]=='$' || now[0]=='$' || now.size()==0) continue;

                    /// jdi ekhnker ta ager cheye besi hoi then set clear korte hbe
                    if(LCP[i]>maxy) res.clear();
                    maxy = LCP[i];
                    res.insert(now);
                }
            }
        }

        set <string> :: iterator it;
        for(it=res.begin(); it!=res.end(); it++)
        {
            cout << *it << endl;
        }

        /// jdi na thake set e tahole '?' print
        if(res.size()==0) cout << "?" << endl;

    }

    return 0;
}




