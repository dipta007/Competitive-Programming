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

// #define dipta007
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

int getLength(int x)
{
    int len = 0;
    while (x)
    {
        len++;
        x /= 10;
    }
    return len;
}

int getZero(string &st)
{
    int zero = 0;
    FOR(i, 0, (int)st.size() - 1)
    {
        if (st[i] == '0')
            zero++;
        else
            break;
    }
    return zero;
}

string jog(string a, string b)
{
    FOR(i, 0, (int)b.size() - 1)
    {
        string tb = b.substr(i);
        if (tb.size() >= a.size())
            continue;
        string ta = a.substr(0, tb.size());

        if (ta == tb)
        {
            return b + a.substr(tb.size());
        }
    }
    return b + a;
}

bool check(string st)
{
    if (st.size() > 19)
        return false;

    FOR(i, 1, (int)st.size() - 1)
    {
        string a = st.substr(0, i);
        string b = st.substr(i);

        b = jog(a, b);
        a = b;

        if (a[0] == '0')
            continue;

        debug(a, b);

        stringstream aa(a);
        ll x;
        aa >> x;

        stringstream bb(b);
        ll y;
        bb >> y;
        y++;

        debug(i, x, y);
        if (x <= 1000000000 && y <= 1000000000)
        {
            return true;
        }
    }
    return false;
}

int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    FOR(ci, 1, t)
    {
        string st;
        cin >> st;

        if (st.size() < 10)
        {
            cout << "YES" << endl;
            continue;
        }

        int flg = 0;
        FOR(skip, 0, 9)
        {
            FOR(i, 1, 18)
            {
                if (skip + i > st.size())
                    break;

                string tmp = st.substr(skip, i);
                int z = getZero(tmp);
                stringstream ss1(tmp);
                ll prev;
                ss1 >> prev;

                if (z > 0)
                {
                    ll age = prev - 1;
                    while (age)
                    {
                        ll kk = age % 10;
                        if (kk == 0)
                            z--;
                        else
                            break;
                        age /= 10;
                    }
                }

                if (z || prev > 1000000000)
                    continue;

                if (skip > 0)
                {
                    string skips = st.substr(0, skip);
                    int leb = (int)skips.size() - 1;

                    ll age = prev - 1;
                    while (age && leb >= 0)
                    {
                        int b = skips[leb] - '0';
                        int a = age % 10;
                        if (a != b)
                            break;
                        age /= 10;
                        leb--;
                    }

                    if (leb >= 0)
                    {
                        continue;
                    }
                }

                int nf = 1;
                for (int j = skip + i; j < st.size();)
                {
                    prev++;
                    if (prev > 1000000000)
                    {
                        nf = 0;
                        break;
                    }

                    int nl = getLength(prev);
                    string tmp = st.substr(j, nl);
                    j += nl;
                    stringstream ss(tmp);
                    ll x;
                    ss >> x;
                    if (prev == -1 || x == prev)
                        prev = x;
                    else
                    {
                        if (j > st.size())
                        {
                            string now = to_string(prev);
                            int nnf = 1;
                            FOR(k, 0, (int)tmp.size() - 1)
                            {
                                if (tmp[k] != now[k])
                                {
                                    nnf = 0;
                                    break;
                                }
                            }
                            if (nnf == 1)
                            {
                                break;
                            }
                        }
                        nf = 0;
                        break;
                    }
                }

                if (nf)
                {
                    debug(skip, i);
                    flg = 1;
                    break;
                }
            }

            if (flg)
                break;
        }

        if (flg)
            cout << "YES" << endl;
        else
        {
            if (st.size() == 10)
            {
                stringstream ss(st);
                ll x;
                ss >> x;
                if (x == 1000000000)
                    cout << "YES" << endl;
                else if (check(st))
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (check(st))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
