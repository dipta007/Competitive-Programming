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

///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out
const int MAX_N = 20004;
int text[MAX_N];
int N, m, SA [MAX_N], LCP [MAX_N];
int x [MAX_N], y [MAX_N], w [MAX_N], c [MAX_N];

inline bool cmp (const int a, const int b, const int l)
{
    return (y [a] == y [b] && y [a + l] == y [b + l]);
}

void Sort ()
{
    for (int i = 0; i < m; ++i)
        w [i] = 0;
    for (int i = 0; i < N; ++i)
        ++w [x [y [i]]];
    for (int i = 0; i < m - 1; ++i)
        w [i + 1] += w [i];
    for (int i = N - 1; i >= 0; --i)
        SA [--w [x [y [i]]]] = y [i];
}

void DA ()
{
    ++N;
    for (int i = 0; i < N; ++i)
        x [i] = text [i], y[i] = i;
    Sort ();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p)
    {
        for (p = 0, i = N - j; i < N; i++)
            y [p++] = i;
        for (int k = 0; k < N; ++k)
            if (SA [k] >= j)
                y [p++] = SA [k] - j;
        Sort ();
        for (swap (x, y), p = 1, x [SA [0]] = 0, i = 1; i < N; ++i)
            x [SA [i]] = cmp (SA [i - 1], SA [i], j) ? p - 1 : p++;
    }
    for (int i = 1; i < N; ++i)
        SA [i - 1] = SA [i];
    --N;
}

void kasaiLCP ()
{
    for (int i = 0; i < N; ++i)
        c [SA [i]] = i;
    LCP [0] = 0;
    for (int i = 0, h = 0; i < N; ++i)
        if (c[i] > 0)
        {
            int j = SA [c [i] - 1];
            while (i + h < N && j + h < N && text [i + h] == text [j + h])
                ++h;
            LCP [c [i]] = h;
            if (h > 0)
                --h;
        }
}

void suffixArray (int nn)
{
    m = 256;
    N = nn;
    DA ();
    kasaiLCP ();
}

int solve(int x, int n)
{
    int mn, mx;
    mn = mx = SA[0];
    FOR(i,1,n-1)
    {
        if(LCP[i] >= x)
        {
            mn = min(mn, SA[i]);
            mx = max(mx, SA[i]);

//            debug(i, mx, mn)
            if(mx - mn > x) return true;
        }
        else mx = mn = SA[i];
    }
    return false;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        if(n==0) break;
        FOR(i,0,n-1)
        {
            getI(text[i]);
        }
        if(n<10)
        {
            printf("0\n");
            continue;
        }

        FOR(i,0,n-2)
        {
            text[i] = text[i+1] - text[i] + 100;
//            debug(i, text[i])
        }
        text[n] = 0;

        suffixArray(n);

        int low = 1, high = n;
        int res = 0;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(solve(mid, n))
            {
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        if(res < 4) res = 0;
        else res = res + 1;

        printf("%d\n", res);
    }

    return 0;
}

