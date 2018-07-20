#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100010
#define MOD 1000000007
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

int fact[MAX], inv[MAX];

int expo(int a, int b){
    int res = 1;

    while (b){
        if (b & 1) res = (long long)res * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return res;
}

void Generate(){
    int i, x;
    for (fact[0] = 1, i = 1; i < MAX; i++) fact[i] = ((long long)i * fact[i - 1]) % MOD;

    inv[MAX - 1] = expo(fact[MAX - 1], MOD - 2);
    for (i = MAX - 2; i >= 0; i--) inv[i] = ((long long)inv[i + 1] * (i + 1)) % MOD;
}

int main(){
    Generate();
    printf("%d\n", inv[35]);
    printf("%d\n", expo(fact[35], MOD - 2));
    return 0;
}
