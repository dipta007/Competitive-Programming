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
using namespace std;

/* Function to calculate (base^exponent)%modulus */
long long int modular_pow(long long int base, int exponent,
                        long long int modulus)
{
    /* initialize result */
    long long int result = 1;

    while (exponent > 0)
    {
        /* if y is odd, multiply base with result */
        if (exponent & 1)
            result = (result * base) % modulus;

        /* exponent = exponent/2 */
        exponent = exponent >> 1;

        /* base = base * base */
        base = (base * base) % modulus;
    }
    return result;
}

/* method to return prime divisor for n */
long long int PollardRho(long long int n)
{
    /* initialize random seed */
    srand (time(NULL));

    /* no prime divisor for 1 */
    if (n==1) return n;

    /* even number means one of the divisors is 2 */
    if (n % 2 == 0) return 2;

    /* we will pick from the range [2, N) */
    long long int x = (rand()%(n-2))+2;
    long long int y = x;

    /* the constant in f(x).
    * Algorithm can be re-run with a different c
    * if it throws failure for a composite. */
    long long int c = (rand()%(n-1))+1;

    /* Initialize candidate divisor (or result) */
    long long int d = 1; 

    /* until the prime factor isn't obtained.
    If n is prime, return n */
    while (d==1)
    {
        /* Tortoise Move: x(i+1) = f(x(i)) */
        x = (modular_pow(x, 2, n) + c + n)%n;

        /* Hare Move: y(i+1) = f(f(y(i))) */
        y = (modular_pow(y, 2, n) + c + n)%n;
        y = (modular_pow(y, 2, n) + c + n)%n;

        /* check gcd of |x-y| and n */
        d = __gcd(abs(x-y), n);

        /* retry if the algorithm fails to find prime factor
        * with chosen x and c */
        if (d==n) return PollardRho(n);
    }

    return d;
}

#define ll long long 


ll f(ll y, ll c, ll n) {
    y = (y * y) % n;
    y += c;
    if (y < c)
        y += (std::numeric_limits<uint32_t>::max() - n) + 1;
    y %= n;
    return y;
}

ll rho(ll n)
{
    if (n == 1) return n;
    if (n % 2 == 0) return 2;

    ll y = rand() % n;
    ll x;
    ll ys = y;
    ll c;
    do c = rand() % n; while (c == 0 || c == n - 2);
    ll m = 1000;
    ll d = 1;
    ll q = 1;
    ll r = 1;
    do
    {
        x = y;
        for (int i = 0; i <= r; i++)
            y = f(y, c, n);

        int j = 0;
        do
        {
            ys = y;
            for (int i = 0; i <= min(m, r - j); i++)
            {
                y = f(y, c, n);
                q *= (abs(x, y) % n);
            }
            d = gcd(q, n);
            j += m;
        } while (j < r && d == 1);
        r *= 2;
    } while (d == 1);
    if (d == n)
    {
        do
        {
            ys = f(ys, c, n);
            d = gcd(abs(x, ys), n);
        } while (d == 1);
    }
    return d;
}

/* driver function */
int main()
{
    freopen("in.txt", "r", stdin);
    long long int n;
    cin >> n;
    printf("One of the divisors for %lld is %lld.", n, rho(n));
    return 0;
}
