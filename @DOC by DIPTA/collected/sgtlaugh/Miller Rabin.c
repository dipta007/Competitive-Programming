#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

long long mul(long long a, long long b, long long m){
    long long res = 0;
    long long x = (a % m);

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

bool miller_rabin(long long p, int lim){
    if (p < 2) return false;
    if (p == 2) return true;
    if (!(p & 1)) return false;

    long long a, s, m, x, y;

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
    for (i = 0; i < 100000; i++){
        int c = isPrime(i);
        int d = miller_rabin(i, 10);

        if (c ^ d){
            counter++;
            printf("%d = %d %d\n", i, c, d);
        }
    }

    printf("counter = %d\n", counter);
    return 0;
}
