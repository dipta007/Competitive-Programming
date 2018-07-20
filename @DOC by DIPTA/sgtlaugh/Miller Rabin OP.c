#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

const long long LIM = LONG_LONG_MAX;

long long mul(long long a, long long b, long long m){
    long long x, res;

    if (a < b){
        x = a;
        a = b;
        b = x;
    }
    if (!b) return 0;
    if (a < (LIM / b)) return ((a * b) % m);

    res = 0, x = (a % m);
    while (b){
        if (b & 1){
            res = res + x;
            if (res >= m) res -= m;
        }
        b >>= 1;
        x <<= 1;
        if (x >= m) x -= m;
    }

    return res;
}

long long expo(long long x, long long n, long long m){
    long long res = 1;

    while (n){
        if (n & 1) res = mul(res, x, m);
        x = mul(x, x, m);
        n >>= 1;
    }

    return (res % m);
}

const int small_primes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51, 53, 59, 61, 67, 71};

bool miller_rabin(long long p, int lim){
    if (p < 2) return false;
    if (p == 2) return true;
    if (!(p & 1)) return false;

    int i, val;
    long long a, s, m, x, y;
    for (i = 0; i < 20; i++){
        val = small_primes[i];
        if (p == val) return true;
        if ((p % val) == 0){
            return false;
        }
    }

    srand(time(0));
    s = p - 1, y = p - 1;
    while (!(s & 1)) s >>= 1;

    while (lim--){
        x = s;
        a = (rand() % y) + 1;
        m = expo(a, x, p);

        while ((x != y) && (m != 1) && (m != y)){
            m = mul(m, m, p);
            x <<= 1;
        }
        if ((m != y) && !(x & 1)) return false;
    }

    return true;
}

bool isPrime(long long p){
    if (p < 2) return false;

    long long i;
    for (i = 2; (i * i) <= p; i++){
        if ((p % i) == 0) return false;
    }
    return true;
}

int main(){
    srand(time(0));
    int i, j, k;
    long long x, y, z;

    int counter = 0;
    for (i = 0; i < 1000; i++){
        long long x = 1LL << 42;
        long long p = x + i;

        int c = isPrime(p);
        int d = miller_rabin(p, 10);

        if (c ^ d){
            counter++;
            printf("%d = %d %d\n", p, c, d);
        }
    }

    printf("counter = %d\n", counter);
    return 0;
}
