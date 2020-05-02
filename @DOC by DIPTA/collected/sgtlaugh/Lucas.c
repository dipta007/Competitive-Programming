#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

int t, a, b;
long long int p, factorial[MAX], inv[MAX], A[100], B[100], temp[100];

long long int P(int x, int n, int MOD){
    if (n == 0) return 1;
    else if (n & 1) return ((P(x, n - 1, MOD) * x) % MOD);
    else{
        long long int y = P(x, n >> 1, MOD);
        return ((y * y) % MOD);
    }
}

long long int Lucas(long long int n, long long int k){
    int i, j;
    long long int x, y, z, m, r;

    factorial[0] = 1;
    for (i = 0; i < p; i++){
        if (i) factorial[i] = (factorial[i - 1] * i) % p;
    }

    a = 0, i = 0, x = n;
    for (; ;){
        temp[i++] = (x % p);
        x /= p;
        if (x == 0) break;
    }
    for (j = i - 1; j >= 0; j--) A[a++] = temp[j];

    b = 0, i = 0, x = k;
    for (; ;){
        temp[i++] = (x % p);
        x /= p;
        if (x == 0) break;
    }
    for (j = i - 1; j >= 0; j--) B[b++] = temp[j];

    long long int res = 1;
    for (j = b - 1, i = a - 1; i >= 0; i--, j--){
        m = A[i];
        if (j < 0) r = 0;
        else r = B[j];

        if ((m - r) < 0){
            res = 0;
            break;
        }

        x = factorial[m];
        z = (factorial[r] * factorial[m - r]) % p;
        y = P(z, p - 2, p);
        long long int v = (x * y) % p;
        res = (res * v) % p;
    }

    return res;
}

int main(){
    int i, j;
    long long int n, k;

    while (scanf("%d", &t) != EOF){
        while (t--){
            scanf("%lld %lld %lld", &n, &k, &p);
            long long int res = Lucas(n + 1, n - k);
            printf("%lld\n", res);
        }
    }
    return 0;
}
