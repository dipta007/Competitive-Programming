/**
Procedure:
    1. Call bin::binomial(n, r, mod)
**/
#define MAXP 9767550
const long long MOD = 10000000000LL;

namespace crt{
    long long extended_gcd(long long a, long long b, long long& x, long long& y){
        if (!b){
            y = 0, x = 1;
            return a;
        }

        long long g = extended_gcd(b, a % b, y, x);
        y -= ((a / b) * x);
        return g;
    }

    long long mod_inverse(long long a, long long m){
        long long x, y;
        extended_gcd(a, m, x, y);
        return (x + m) % m;
    }

    long long chinese_remainder(vector <long long> ar, vector <long long> mods){
        long long x, y, res = 0, M = 1;
        for (int i = 0; i < ar.size(); i++) M *= mods[i];
        for (int i = 0; i < ar.size(); i++){
            x = M / mods[i], y = mod_inverse(x, mods[i]);
            res = (res + (((x * ar[i]) % M) * y)) % M;
        }
        return res;
    }
}

namespace bin{
    long long mod = 0, dp[MAXP];

    long long trailing(long long x, long long p){
        long long res = 0;
        while (x){
            x /= p;
            res += x;
        }
        return res;
    }

    long long expo(long long a, long long b, long long m){
        long long res = 1;

        while (b){
            if (b & 1) res = res * a % m;
            a = a * a % m, b >>= 1;
        }
        return res;
    }

    long long factorial(long long x, long long p){
        long long res = expo(dp[mod - 1], x / mod, mod);
        if (x >= p) res = res * factorial(x / p, p) % mod;
        return res * dp[x % mod] % mod;
    }

    long long binomial(long long n, long long k, long long p, long long q){
        if (k > n || k < 0) return 0;
        if (n == k || k == 0) return 1;

        int i, j;
        for (i = 0, mod = 1; i < q; i++) mod *= p;
        long long t = trailing(n, p) - trailing(k, p) - trailing(n - k, p);
        if (t >= q) return 0;

        assert(mod < MAXP);
        for (dp[0] = 1, i = 1; i < mod; i++){
            dp[i] = (long long)dp[i - 1] * ((i % p) ? i : 1) % mod;
        }

        long long res = factorial(n, p) * expo(factorial(k, p) * factorial(n - k, p) % mod, (mod / p) * (p - 1) - 1, mod) % mod;
        for (i = 0; i < t; i++) res = res * p % mod;
        return res;
    }

    long long binomial(long long n, long long k, long long m){
        if (k > n || m == 1 || k < 0) return 0;
        if (n == k || k == 0) return 1;

        vector <pair<int, int>> factors;
        for (long long i = 2; i * i <= m; i++){
            int c = 0;
            while (m % i == 0){
                c++;
                m /= i;
            }
            if (c) factors.push_back(make_pair(i, c));
        }
        if (m > 1) factors.push_back(make_pair(m, 1));

        vector <long long> ar, mods;
        for (int i = 0; i < factors.size(); i++){
            long long x = 1;
            for (int j = 0; j < factors[i].second; j++) x *= factors[i].first;
            mods.push_back(x), ar.push_back(binomial(n, k, factors[i].first, factors[i].second));
        }
        return crt::chinese_remainder(ar, mods);
    }
}

bool add_dots(long long n, long long k){
    if (k < 0 || k > n) return false;

    k = min(k, n - k);
    long long u = n, v = 1;
    pair <long long, long double> x = make_pair(1, 1);

    for (int i = 0; i < k; i++, u--, v++){
        x = make_pair(x.first * u, x.second * u);
        x = make_pair(x.first / v, x.second / v);
        if (x.first >= MOD || x.second >= (2.0 * MOD)) return true;
    }
    return false;
}

