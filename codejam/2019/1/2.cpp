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

#define MAXROW 10
#define MAXCOL 10
int gauss(int n, int m, double ar[MAXROW][MAXCOL], vector<double>& res){ /// hash = 835176
    res.assign(m, 0);
    vector <int> pos(m, -1);
    int i, j, k, l, p, free_var = 0;

    for (j = 0, i = 0; j < m && i < n; j++){
        for (k = i, p = i; k < n; k++){
            if (abs(ar[k][j]) > abs(ar[p][j])) p = k;
        }

        if (abs(ar[p][j]) > EPS){
            pos[j] = i;
            for (l = j; l <= m; l++) swap(ar[p][l], ar[i][l]);

            for (k = 0; k < n; k++){
                if (k != i){
                    double x = ar[k][j] / ar[i][j];
                    for (l = j; l <= m; l++) ar[k][l] -= (ar[i][l] * x);
                }
            }
            i++;
        }
    }

    for (i = 0; i < m; i++){
        if (pos[i] == -1) free_var++;
        else res[i] = ar[pos[i]][m] / ar[pos[i]][i];
    }

    for (i = 0; i < n; i++) {
        double val = 0.0;
        for (j = 0; j < m; j++) val += (res[j] * ar[i][j]);
        if (abs(val - ar[i][m]) > EPS) return -1;
    }

    return free_var;
}


int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t, w;
    cin >> t >> w;

    FOR(ci,1,t) {
      double ar[10][10];
      
      int x;
      cout << 1 << endl;
      cin >> x;
      ar[0][0] = 2;
      ar[0][1] = 4;
      ar[0][2] = 8;
      ar[0][3] = 16;
      ar[0][4] = 32;
      ar[0][5] = 64;
      ar[0][6] = x;

      cout << 2 << endl;
      cin >> x;
      ar[1][0] = 1;
      ar[1][1] = 2;
      ar[1][2] = 2;
      ar[1][3] = 4;
      ar[1][4] = 4;
      ar[1][5] = 8;
      ar[1][6] = x;

      cout << 3 << endl;
      cin >> x;
      ar[2][0] = 1;
      ar[2][1] = 1;
      ar[2][2] = 2;
      ar[2][3] = 2;
      ar[2][4] = 2;
      ar[2][5] = 4;
      ar[2][6] = x;

      cout << 4 << endl;
      cin >> x;
      ar[3][0] = 1;
      ar[3][1] = 1;
      ar[3][2] = 1;
      ar[3][3] = 2;
      ar[3][4] = 2;
      ar[3][5] = 2;
      ar[3][6] = x;

      cout << 5 << endl;
      cin >> x;
      ar[4][0] = 1;
      ar[4][1] = 1;
      ar[4][2] = 1;
      ar[4][3] = 1;
      ar[4][4] = 2;
      ar[4][5] = 2;
      ar[4][6] = x;

      cout << 6 << endl;
      cin >> x;
      ar[5][0] = 1;
      ar[5][1] = 1;
      ar[5][2] = 1;
      ar[5][3] = 1;
      ar[5][4] = 1;
      ar[5][5] = 2;
      ar[5][6] = x;

      vector <double> res;

      gauss(6, 6, ar, res);

      cout << res[0] << " ";
      cout << res[1] << " ";
      cout << res[2] << " ";
      cout << res[3] << " ";
      cout << res[4] << " ";
      cout << res[5] << endl;

      cin >> x;
    }

    return 0;
}
