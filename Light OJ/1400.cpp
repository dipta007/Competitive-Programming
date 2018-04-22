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
/** A person has an integer preference for each of the persons of the opposite
 * sex, produces a matching of each man to some woman. The matching will follow:
 *          - Each man is assigned to a different woman (n must be at least m)
 *          - No two couples M1W1 and M2W2 will be unstable.
 * Two couples are unstable if (M1 prefers W2 over W1 and W1 prefers M2 over M1)
 **/
/** INPUT: n – number of man, m – number of woman (must be at least as large as m)
*          - L[i][]: the list of women in order of decreasing preference of man i
*          - R[j][i]: the attractiveness of i to j.
* OUTPUTS: - L2R[]: the mate of man i (always between 0 and n-1)
*          - R2L[]: the mate of woman j (or -1 if single)
**/

const int MAXM = 204, MAXW = 204;
int n, m, L[MAXM][MAXW], R[MAXW][MAXM], L2R[MAXM], R2L[MAXW], p[MAXM];
void stableMarriage()
{
    memset( R2L, -1, sizeof( R2L ) );
    memset( p, 0, sizeof( p ) );
    for( int i = 0; i < n; i++ )   // Each man proposes...
    {
        int man = i;
        while( man >= 0 )
        {
            int wom;
            while( 1 )
            {
                wom = L[man][p[man]++];
                if( R2L[wom] < 0 || R[wom][man] > R[wom][R2L[wom]] )
                    break;
            }
            int hubby = R2L[wom];
            L2R[hubby] = -1;
            L2R[man] = wom;
            R2L[wom] = man;
            man = hubby;
        }
    }
}

/**
Procedure:
    1. Input N for total man and woman
    2. Input data in pref_man in decreasing order
    3. Input data in pref_woman in decreasing order
**/
const int MAX_N = 204;
int N,pref_men[MAX_N][MAX_N],pref_women[MAX_N][MAX_N];
int inv[MAX_N][MAX_N],cont[MAX_N],wife[MAX_N],husband[MAX_N];

void stable_marriage(){

    for(int i = 0 ; i < N ; i++)
        for(int j = 0;j < N; j++)
            inv[i][pref_women[i][j]] = j;

    fill(cont,cont+N,0);
    fill(wife,wife+N,-1);
    fill(husband,husband+N,-1);
    queue<int> Q;
    for(int i = 0; i < N; i++) Q.push(i);

    int m,w;

    while(!Q.empty()){
        m = Q.front();
        w = pref_men[m][cont[m]];

        if(husband[w] == -1){
            wife[m] = w;
            husband[w] = m;
            Q.pop();
        }else{
            if( inv[w][m] < inv[w][husband[w]] ){
                wife[m] = w;
                wife[husband[w]] = -1;
                Q.pop();
                Q.push(husband[w]);
                husband[w] = m;
            }
        }

        cont[m]++;
    }
}

int main() {
    #ifdef dipta007
//        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);

    FOR(ci,1,t)
    {
        int n;
        getI(n);
        N = n;
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                getI(pref_men[i][j]);
                pref_men[i][j] -= (n+1);
            }
        }

        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                getI(pref_women[i][j]);
                pref_women[i][j] --;
            }
        }

        stable_marriage();

        printf("Case %d:", ci);
        FOR(i,0,n-1)
        {
            printf(" (%d %d)",i+1, wife[i]+n+1);
//            printf(" (%d %d)",i+1, L2R[i]+1);
        }

        printf("\n");
    }


    return 0;
}

