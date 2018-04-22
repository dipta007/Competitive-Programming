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
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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


#define MAX 90016
struct SuffixArray {
    char str[MAX];
    int s0[(MAX / 3) + 10], sa0[(MAX / 3) + 10];
    int n, ar[MAX], sa[MAX], lcp[MAX], bucket[MAX], mem[MAX << 2];

    /* sa[i] is starting index of (i)th smallest suffix in str.
     * i is in range[0 .... n)
     * lcp[j] is longest common prefix of (j)th and (j-1)th suffix
     * j is in range[0 .... n-1) */

    void radixsort(int *source, int *dest, int *val, int n, int lim) {
        int i, s = 0, x;
        CLR(bucket);
        FOR(i, 0, n-1) bucket[ val[source[i]] ]++;
        FOR(i, 0, lim-1) {
            x = bucket[i];
            bucket[i] = s, s += x;
        }
        FOR(i, 0, n-1) dest[bucket[ val[source[i]] ]++] = source[i];
    }

    void DC3(int *ar, int *sa, int n, int lim, int ptr) {
        int *s12, *sa12;
        int allc = (n / 3) << 1, n0 = (n + 2) / 3;
        int i, j, k, l, c, d, p, t, m, r, counter;

        s12 = &mem[ptr], ptr += (allc + 5), sa12 = &mem[ptr], ptr += (allc + 5);

        c = 0, m = 0, r = n + ((n % 3) == 1);
        FOR(i, 0, r-1) {
            if (m == 3) m = 0;
            if (m) s12[c++] = i;
            m++;
        }
        s12[c] = sa12[c] = s12[c + 1] = sa12[c + 1] = 0;
        s12[c + 2] = sa12[c + 2] = 0;

        radixsort(s12, sa12, ar + 2, c, lim + 1);
        radixsort(sa12, s12, ar + 1, c, lim + 1);
        radixsort(s12, sa12, ar, c, lim + 1);

        counter = 0, j = -1;
        FOR(i, 0, c-1) {
            if ( (ar[sa12[i]] != j) || (ar[sa12[i] + 1] != k) ||
                (ar[sa12[i] + 2] != l) ) {

                counter++;
                j = ar[sa12[i]], k = ar[sa12[i] + 1], l = ar[sa12[i] + 2];
            }
            if ( (sa12[i] % 3) == 1 ) s12[sa12[i] / 3] = counter;
            else s12[ (sa12[i] / 3) + n0 ] = counter;
        }

        if (counter == c) {
            FOR(i, 0, c-1) sa12[s12[i] - 1] = i;
        } else {
            DC3(s12, sa12, c, counter, ptr);
            FOR(i, 0, c-1) s12[sa12[i]] = i + 1;
        }
        d = 0;
        FOR(i, 0, c-1) if (sa12[i] < n0) s0[d++] = (sa12[i] * 3);

        radixsort(s0, sa0, ar, d, lim + 1);

        k = 0;
        l = ((n % 3) == 1);

        FOR(r, 0, n-1) {
            j = sa0[k];
            i = ((sa12[l] < n0) ? (sa12[l] * 3) + 1 : ((sa12[l] - n0) * 3) + 2);
            if (l == c) sa[r] = sa0[k++];
            else if (k == d) sa[r] = i, l++;
            else {
                if (sa12[l] < n0) {
                    if ((ar[i] < ar[j]) || (ar[i] == ar[j] &&
                                            s12[sa12[l] + n0] <= s12[j / 3]))
                        sa[r] = i, l++;
                    else sa[r] = j, k++;
                } else {
                    if ( (ar[i] < ar[j]) ||
                        (ar[i] == ar[j] && ar[i + 1] < ar[j + 1]) ||
                        (ar[i] == ar[j] && ar[i + 1] == ar[j + 1] &&
                         s12[sa12[l] - n0 + 1] <= s12[(j / 3) + n0]) )
                        sa[r] = i, l++;
                    else sa[r] = j, k++;
                }
            }
        }
    }

    void LcpArray() {
        int i, j, k;
        FOR(i, 0, n-1) ar[sa[i]] = i;

        for (k = 0, i = 0; i < n; i++, k ? k-- : 0) {
            if (ar[i] == (n - 1)) k = 0;
            else {
                j = sa[ar[i] + 1];
                while ( ((i + k) < n) && ((j + k) < n) &&
                        (str[i + k] == str[j + k]) )
                    k++;
            }
            lcp[ar[i]] = k;
        }
    }

    void Generate() {
        n = strlen(str);
        int lim = 0;
        FOR(i, 0, n-1) {
            ar[i] = str[i];
            if (ar[i] > lim) lim = ar[i];
        }
        ar[n] = ar[n + 1] = ar[n + 2] = 0;
        DC3(ar, sa, n, lim, 0);
    }

    void get(string &st)
    {
        strcpy(str, st.c_str());
        Generate();
    }
} sa;

ll sub[90016];

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int in = 0;
    char ch;
    ch = getchar();
    while(islower(ch) && isalpha(ch))
    {
        debug(ch)
        sa.str[in++] = ch;
        ch = getchar();
    }
    sa.str[in] = '\n';
//    while(~scanf("%s", sa.str))
    {
//        st += "$";
        sa.Generate();
        sa.LcpArray();
        int len = in;

        sub[0] = len - sa.sa[0];
        FOR(i,1,len-1)
        {
            ll sz = len - sa.sa[i];
            sub[i] = sz - sa.lcp[i-1];
            sub[i] += sub[i-1];
        }

        int q;
        getI(q);
        debug(q);
        FOR(ii,1,q)
        {
            ll n;
            getL(n);

            int res = upper_bound(sub, sub+len, n-1) - sub;
            for(ll j=0, k=sa.sa[res]; j<(ll)len-sub[res]+n; j++, k++)
            {
                printf("%c",sa.str[k]);
            }
            printf("\n");
        }
    }

    return 0;
}

