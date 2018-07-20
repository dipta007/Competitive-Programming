#include <bits/stdtr1c++.h>

#define MAX 131072 /// Must be a power of 2
#define MOD 1000000007

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

long long ptr = 0;
long long temp[128];
long long buffer[MAX * 6];
const long long INF = 8000000000000000000LL;

void karatsuba(int n, long long *a, long long *b, long long *res){ /// n is a power of 2
    int i, j, s;
	if (n < 33){ /// Reduce recursive calls by setting a threshold
        for (i = 0; i < (n + n); i++) temp[i] = 0;
        for (i = 0; i < n; i++){
            if (a[i]){
                for (j = 0; j < n; j++){
                    temp[i + j] += (a[i] * b[j]);
                    if (temp[i + j] > INF) temp[i + j] %= MOD;
                }
            }
        }
		for (i = 0; i < (n + n); i++) res[i] = temp[i] % MOD;
		return;
	}

	s = n >> 1;
	karatsuba(s, a, b, res);
	karatsuba(s, a + s, b + s, res + n);
	long long *x = buffer + ptr, *y = buffer + ptr + s, *z = buffer + ptr + s + s;

	ptr += (s + s + n);
	for (i = 0; i < s; i++){
        x[i] = a[i] + a[i + s], y[i] = b[i] + b[i + s];
        if (x[i] >= MOD) x[i] -= MOD;
        if (y[i] >= MOD) y[i] -= MOD;
	}

	karatsuba(s, x, y, z);
	for (i = 0; i < n; i++) z[i] -= (res[i] + res[i + n] - MOD);
	for (i = 0; i < n; i++) res[i + s] = (res[i + s] + z[i] + MOD) % MOD;
	ptr -= (s + s + n);
}

/// multiplies two polynomial a(degree n) and b(degree m) and returns the result modulo MOD in a
/// returns the degree of the multiplied polynomial
/// note that a and b are changed in the process
int mul(int n, long long *a, int m, long long *b){
    int i, r, c = (n < m ? n : m), d = (n > m ? n : m);
    long long *res = buffer + ptr;
    r = 1 << (32 - __builtin_clz(d) - (__builtin_popcount(d) == 1));
    for (i = d; i < r; i++) a[i] = b[i] = 0;
    for (i = c; i < d && n < m; i++) a[i] = 0;
    for (i = c; i < d && m < n; i++) b[i] = 0;

    ptr += (r << 1), karatsuba(r, a, b, res), ptr -= (r << 1);
    for (i = 0; i < (r << 1); i++) a[i] = res[i];
    return (n + m - 1);
}

long long a[MAX], b[MAX];

int main(){
    int i, j, k, n = MAX - 10;
    for (i = 0; i < n; i++) a[i] = ran(1, 1000000000);
    for (i = 0; i < n; i++) b[i] = ran(1, 991929183);
    clock_t start = clock();
    mul(n, a, n, b);
    dbg(a[n / 2]);
    for (i = 0; i < (n << 1); i++){
        if (a[i] < 0) puts("YO");
    }
    printf("%0.5f\n", (clock() - start) / (1.0 * CLOCKS_PER_SEC));
    return 0;
}
