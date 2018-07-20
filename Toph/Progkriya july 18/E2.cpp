//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#ifdef dipta00
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

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int len, mod, r;
unordered_map < int, ll > mp;
string st;
int lim;
ll cnt = 0;
ll baki;

int ans1, ans2;

inline ll MOD(ll x)
{
    return ((x%mod) + mod)%mod;
}

void call(int in, ll now, int flg)
{
    if(in >= lim)
    {
        if(flg == 0)
        {
            now = ((ll)now * baki) % mod;
            trace(now);
            mp[now]++;
        }
        else
        {
            int kk = MOD(r - now);
            trace(kk, now, r-now, mp[kk]);
            cnt += mp[kk];
            if(cnt==1 && mp[kk] > 0)
            {
//                trace(kk, now, mp[kk]);
                ans1 = kk, ans2 = now;
            }
        }
        return;
    }

    trace(in, st[in], lim);
    if(st[in] == '?')
    {
        int strt = 0;
        if(in==0) strt = 1;
        FOR(i,strt, 9)
        {
            call(in+1, ((now*10LL)+i)%mod, flg);
        }
    }
    else
    {
        int kk = st[in] - '0';
        call(in+1, ((now*10LL)+kk)%mod, flg);
    }
}

vector < int > dig;
bool pathPrint(int in, ll now, int flg)
{
    if(in >= lim)
    {
        if(flg == 0)
        {
            now = ((ll)now * baki) % mod;
            if(now == ans1)
            {
                trace(now, ans1, dig.size());
                FOR(i,0,(int)dig.size()-1)
                {
                    cout << dig[i];
                }
                return true;
            }
            return false;
        }
        else
        {
            if(now == ans2)
            {
//                trace(now, ans2, dig.size());
                FOR(i,0,(int)dig.size()-1)
                {
                    cout << dig[i];
                }
                return true;
            }
            return false;
        }
    }

//    trace(in, st[in], lim, flg);
    if(st[in] == '?')
    {
        int strt = 0;
        if(in==0) strt = 1;
        FOR(i,strt, 9)
        {
            dig.push_back(i);
            if(pathPrint(in+1, ((now*10LL)+i)%mod, flg)) return true;
            dig.pop_back();
        }
    }
    else
    {
        int kk = st[in] - '0';
        dig.push_back(kk);
        pathPrint(in+1, ((now*10LL)+kk)%mod, flg);
        dig.pop_back();
    }
    return true;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin >> len >> mod >> r)
    {
        cin >> st;

        mp.clear();

        int tot = 0;
        FOR(i,0,(int)st.size()-1) tot += (st[i] == '?');
        int mid;
        int cq = 0;
        FOR(i,0,(int)st.size()-1)
        {
            if(cq == tot/2)
            {
                mid = i;
                lim = i;
                break;
            }
            if(st[i] == '?') cq++;
        }

        baki = 1;
        FOR(i,1,len-lim) baki = (baki * 10LL)%mod;

        int tmpLim = lim;
        call(0, 0, 0);

        cnt = 0;
        lim = len;
        call(mid,0,1);

        trace(ans1, ans2);

        if(cnt == 1)
        {
            lim = tmpLim;
            dig.clear();
            pathPrint(0, 0, 0);
            lim = len;
            dig.clear();            pathPrint(mid, 0, 1);
            cout << endl;
        }
        else cout << cnt << endl;
    }

    return 0;
}




