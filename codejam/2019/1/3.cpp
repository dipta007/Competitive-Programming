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

/**
Procedure:
    1. Call preCalculate(MAX) once before all test cases
    2. Call build table once for each test case
    3. Call rmq(l, r) to get the result
Time Complexity = RMQ - O(1), build(N log N)
**/
#define SIZE 400004
int arr[2][100004];
int sparse[2][30][SIZE], height;
int sparsemx[2][30][SIZE];
int b[100004];
int r[100004];

void preCalculate(int n)
{
    int xx = 1,rr=0;
    FOR(i,1,n)
    {
        if(i!=1 && !(i&(i-1)))
        {
            xx *= 2;
            rr ++;
        }
        b[i]=xx;
        r[i]=rr;
    }
}
void buildTable ( int ind, int n ) {
    ///Base Case
    for ( int i = 0; i < n; i++ ) {
        sparse[ind][0][i] = arr[ind][i];
        sparsemx[ind][0][i] = arr[ind][i];
    }
    ///Current power of 2 is cur
    ///power of 2 for previous row is prev
    int cur = 2, prev = 1;
    for ( int i = 1; i < 22; i++ ) {
        if ( cur > n ) {
            height = i;
            break;
        }
        for ( int j = 0; j < n; j++ ) {
            int k = j + prev;
            if ( k >= n ) k = n - 1;
            sparse[ind][i][j] = min ( sparse[ind][i-1][j], sparse[ind][i-1][k]);
            sparsemx[ind][i][j] = max( sparsemx[ind][i-1][j], sparsemx[ind][i-1][k]);
        }

        cur *= 2;
        prev *= 2;
    }
}
pii rmq ( int ind, int i, int j ) {
    int len = j - i + 1;
//    int row = height;
//    int two = pow ( 2, height );
//
//    while ( two > len ) {
//        two /= 2;
//        row--;
//    }
    int two = b[len];
    int row = r[len];

    int res = min ( sparse[ind][row][i], sparse[ind][row][j-two+1] );
    int res1 = max ( sparsemx[ind][row][i], sparsemx[ind][row][j-two+1] );
    return pii(res,res1);
}

int check(int x, int y, int k) {
  int C = rmq(0, x, y).ss;
  int D = rmq(1, x, y).ss;

  // cout << x << " " << y << " " << C << " " << D << endl;

  if(abs(C-D) <= k) return 1;
  else return 0;
}


int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    preCalculate(100002);
    int t;
    cin >> t;
    FOR(ci, 1, t) {
      int n, k;
      cin >> n >> k;

      FOR(i, 0, n-1) {
        cin >> arr[0][i];
      }

      FOR(i, 0, n-1) {
        cin >> arr[1][i];
      }

      buildTable(0, n);
      buildTable(1, n);

      int cnt = 0;
      FOR(i, 0, n-1) {
        FOR(j, i, n-1) {
          if(check(i, j, k)) cnt++;
        }
      }

      cout << "Case #" << ci << ": " << cnt << endl;
    }


    return 0;
}
