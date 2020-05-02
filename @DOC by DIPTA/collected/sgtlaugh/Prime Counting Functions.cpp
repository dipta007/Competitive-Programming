#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define isprime(x) (( (x) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))

using namespace std;

namespace pcf{
    ///   Prime-Counting Function
    ///   initialize once by calling init()
    ///   Legendre(m) and Lehmer(m) returns the number of primes less than or equal to m

    #define MAXN 1000010
    #define MAX_PRIMES 1000010
    #define PHI_M 10010
    #define PHI_N 48

    unsigned int ar[(MAXN >> 6) + 5] = {0};
    int len = 0, primes[MAX_PRIMES], counter[MAXN], phi_dp[PHI_N][PHI_M];

    void Sieve(int n, unsigned int* ar, int* primes, int& len){
        /// ar must be all set to 0

        n++;
        setbit(ar, 0), setbit(ar, 1);
        int i, j, k, lim = sqrt(n) + 1;

        for (i = 3; i < lim; i++, i++){
            if (!chkbit(ar, i)){
                k = i << 1;
                for (j = (i * i); j < n; j += k) setbit(ar, j);
            }
        }

        for (i = 1; i < n; i++){
            if (isprime(i)) primes[len++] = i;
            counter[i] = len;
        }
    }

    void Sieve(int n){
        Sieve(n, ar, primes, len);
    }

    void init(){ /// Call just once
        Sieve(MAXN - 1);

        int m, n, res;
        for (n = 0; n < PHI_N; n++){
            for (m = 0; m < PHI_M; m++){
                if (!n) res = m;
                else res = phi_dp[n - 1][m] - phi_dp[n - 1][m / primes[n - 1]];
                phi_dp[n][m] = res;
            }
        }
    }

    int phi(int m, int n){ /// long long
        if (m < PHI_M && n < PHI_N) return phi_dp[n][m];

        if (n == 1) return ((++m) >> 1);
        if (primes[n - 1] >= m) return 1;
        return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
    }


    int Legendre(int m){ /// long long
        if (m < MAXN) return counter[m];

        int lim = sqrt(m) + 1;
        int n = upper_bound(primes, primes + len, lim) - primes;
        return phi(m, n) + (n - 1);
    }


    int Lehmer(int m){ /// Very fast, 100 function calls for any integer per second
        if (m < MAXN) return counter[m];

        int i, j, a, b, c, w, lim, res;
        b = sqrt(m), c = Lehmer(cbrt(m)), a = Lehmer(sqrt(b)), b = Lehmer(b);
        res = phi(m, a) + (((b + a - 2) * (b - a + 1)) >> 1);

        for (i = a; i < b; i++){
            w = m / primes[i];
            lim = Lehmer(sqrt(w)), res -= Lehmer(w);

            if (i <= c){
                for (j = i; j < lim; j++){
                    res += j;
                    res -= Lehmer(w / primes[j]);
                }
            }
        }

        return res;
    }

    #define LEGENDRE -111
    #define LEHMER 666

    void random_exec(int lim, int flag){
        int i, x, y, z;
        int* val = new int[lim];

        mt19937 generator(time(0));
        tr1::uniform_int <int> random(1e9, 2e9);
        for (int i = 0; i < lim; i++) val[i] = random(generator);

        clock_t start = 0;
        for (i = 0; i < lim; i++){
            x = val[i];
            if (flag == LEGENDRE) y = Legendre(x);
            else if (flag == LEHMER) y = Lehmer(x);
        }

        printf("%0.3f s\n", (clock() - start) / (1.0 * CLOCKS_PER_SEC));
        delete[] val;
    }
}

int main(){
    pcf::init();
    pcf::random_exec(100, LEHMER);
    return 0;
}
