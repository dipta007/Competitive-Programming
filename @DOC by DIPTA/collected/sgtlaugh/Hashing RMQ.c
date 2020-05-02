#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LOG 18
#define MAX 100010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

int n, lim;
char str[MAX];
unsigned long long P[MAX], hash[MAX][LOG];
const unsigned long long base = 1968647011ULL;

void Generate(bool gen){
    int i, j, l;
    lim = 32 - __builtin_clz(n);

    if (gen){
        P[0] = 1ULL;
        for (i = 1; i < MAX; i++) P[i] = (P[i - 1] * base);
    }

    for (l = 0; l < lim; l++){
        int len = (1 << l);
        for (i = 0; (i + len) <= n; i++){
            if (l == 0) hash[i][l] = str[i];
            else{
                int d = 1 << (l - 1);
                hash[i][l] = (P[d] * hash[i][l - 1]) + hash[i + d][l - 1];
            }
        }
    }
}

unsigned long long GetHash(int i, int j){
    int d, l = (j - i + 1);
    unsigned long long res = 0;

    for (d = lim - 1; d >= 0; d--){
        if (l & (1 << d)){
            res = (res * P[1 << d]) + hash[i][d];
            i += (1 << d);
        }
    }

    return res;
}

int main(){
    scanf("%s", str);
    n = strlen(str);
    Generate();
    return 0;
}
