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
// #include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define FOR(i, L, R) for (int i = (int)(L); i <= (int)(R); i++)
#define ROF(i, L, R) for (int i = (int)(L); i >= (int)(R); i--)
#define ALL(p) p.begin(), p.end()
#define ALLR(p) p.rbegin(), p.rend()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define getI(a) scanf("%d", &a)
#define getII(a, b) scanf("%d%d", &a, &b)
#define getIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define getL(a) scanf("%lld", &a)
#define getLL(a, b) scanf("%lld%lld", &a, &b)
#define getLLL(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define getF(n) scanf("%lf", &n)
#define bitCheck(N, in) ((bool)(N & (1 << (in))))
#define bitOn(N, in) (N | (1 << (in)))
#define bitOff(N, in) (N & (~(1 << (in))))
#define bitFlip(a, k) (a ^ (1 << (k)))
#define bitCount(a) __builtin_popcount(a)
#define bitCountLL(a) __builtin_popcountll(a)
#define bitLeftMost(a) (63 - __builtin_clzll((a)))
#define bitRightMost(a) (__builtin_ctzll(a))
#define ranL(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define ranI(a, b) ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define ranF(a, b) (((double)rand() / RAND_MAX) * ((b) - (a)) + (a))
#define UNIQUE(V) (V).erase(unique((V).begin(), (V).end()), (V).end())
#define SETI(ar) memset(ar, 126, sizeof ar)

#define printbits(x, n) cout << #x << " = " << x << " = " << bitset<n>(x) << endl /// Least significant n bits of x, n must be constant
#define tobinary(x) string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64)
#define lastbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(64 - n, 64) << endl
#define firstbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64).substr(0, n) << endl;

#define ff first
#define ss second
#define sf scanf
#define pf printf

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
#define FMT(...) (sprintf(CRTBUFF, __VA_ARGS__) ? CRTBUFF : 0)
char CRTBUFF[30000];

#ifdef dipta007
#define debug(args...)              \
    {                               \
        cerr << __LINE__ << " D: "; \
        dbg, args;                  \
        cerr << endl;               \
    }
#define trace(...)                           \
    {                                        \
        cerr << "Line " << __LINE__ << ": "; \
        __f(#__VA_ARGS__, __VA_ARGS__);      \
    }
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(args...) /// Just strip off all debug tokens
#define trace(...)     ///yeeeee
#endif

struct debugger
{
    template <typename T>
    debugger &operator,(const T &v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args>
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args>
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
       //    ios_base::sync_with_stdio(0);cin.tie(0);

    return 0;
}
