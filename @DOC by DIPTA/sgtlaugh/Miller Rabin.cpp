#include <bits/stdtr1c++.h>

#define MAX 1000010
#define isprime(x) prm::miller_rabin(x)
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

namespace prm{
    bitset <MAX> flag;
    long double op = 0.0;
    int p = 0, prime[78777], lim = 15;

    void Sieve(){
        int i, j, x;
        for (i = 3; i < MAX; i += 2) flag[i] = true;
        for (i = 3, flag[2] = true; (i * i) < MAX; i += 2){
            if (flag[i]){
                for (j = (i * i), x = i << 1; j < MAX; j += x){
                    flag[j] = false;
                }
            }
        }

        for (i = 2; i < MAX; i++){
            if (flag[i]) prime[p++] = i;
        }
    }

    void init(){
        if (!flag[2]) Sieve();
    }

    void init(int n){
        lim = n;
        if (!flag[2]) Sieve();
    }

    inline long long mul(long long a, long long b, long long MOD){
       if ((MOD < 3037000500LL)) return ((a * b) % MOD);
       long double res = a;
       res *= b;
       long long c = (long long)(res * op);
       a *= b;
       a -= c * MOD;
       if (a >= MOD) a -= MOD;
       if (a < 0) a += MOD;
       return a;
    }

    inline long long expo(long long x, long long n, long long m){
        long long res = 1;

        while (n){
            if (n & 1) res = mul(res, x, m);
            x = mul(x, x, m);
            n >>= 1;
        }

        return (res % m);
    }

    inline bool miller_rabin(long long p){
        if (p < MAX) return flag[p];
        if ((p + 1) & 1) return false;
        for (int i = 1; i < 10; i++){
            if (!(p % prime[i])) return false;
        }

        long long a, m, x, s = p - 1, y = p - 1;
        op = (long double)1 / p, s = s >> __builtin_ctzll(s);

        for (int i = 0; i < lim; i++) {
            x = s, a = (rand() % y) + 1;
            m = expo(a, x, p);
            while ((x != y) && (m != 1) && (m != y)) m = mul(m, m, p), x <<= 1;
            if ((m != y) && !(x & 1)) return false;
        }
        return true;
    }

    inline long long countdiv(long long n){
        int i, j, c;
        long long x, res = 1;
        for (i = 0; i < p; i++){
            x = prime[i];
            if ((x * x * x) > n) break;

            c = 1;
            while (!(n % x)) c++, n /= x;
            res *= c;
        }

        if (miller_rabin(n)) res <<= 1;
        else if (n > 1) {
            x = sqrt((long double)0.95 + n); ///
            if ((x * x) == n && miller_rabin(x)) res *= 3;
            else res <<= 2;
        }

        return res;
    }
}

int main(){
    long long n;
    prm::init();

    while (scanf("%lld", &n) != EOF){
        printf("%lld\n", prm::countdiv(n));
    }
    return 0;
}
