/***

Sometimes we may need to maintain more than one recurrence, where they are interrelated.
For example, let a recurrence relation be:
g(n) = 2g(n-1) + 2g(n-2) + f(n), where, f(n) = 2f(n-1) + 2f(n-2).
Here, recurrence g(n) is dependent upon f(n) and the can be calculated in the same matrix
but of increased dimensions. Lets design the matrices A, B then we'll try to find matrix M.


                        Matrix A	            Matrix B

                        |  g(n)  |              | g(n+1) |
                        | g(n-1) |              |  g(n)  |
                        | f(n+1) |              | f(n+2) |
                        |  f(n)  |              | f(n+1) |


Here, g(n+1) = 2g(n) + 2g(n-1) + f(n+1) and f(n+2) = 2f(n+1) + 2f(n).
Now, using the above process, we can generate the objective matrix M as follows:

| 2  2  1  0 |
| 1  0  0  0 |
| 0  0  2  2 |
| 0  0  1  0 |

***/


#include <bits/stdtr1c++.h>

#define MAXN 10
#define MOD 1000000007
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

struct Matrix{
    int n;
    long long ar[MAXN][MAXN];

    Matrix(){
    }

    Matrix(int x){
        n = x;
        clr(ar);
    }
};

struct Matrix mul(struct Matrix& A, struct Matrix& B){
    int n = A.n;
    struct Matrix C = Matrix(n);

    int i, j, k;
    long long res = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            for (k = 0, res = 0; k < n; k++){
                res = res + (A.ar[i][k] * B.ar[k][j]);
                if (res >= MOD) res %= MOD;
            }
            C.ar[i][j] = res;
        }
    }

    return C;
}

struct Matrix pow(struct Matrix mat, long long n){
    int c = 0;
    struct Matrix res = Matrix(mat.n);
    for (int i = 0; i < mat.n; i++) res.ar[i][i] = 1;

    while (n){
        if (n & 1LL){
            if (!c++) res = mat;
            else res = mul(res, mat);
        }

        n >>= 1LL;
        mat = mul(mat, mat);
    }

    return res;
}

long long matrix_expo(int n, struct Matrix mat, long long val[MAXN], long long p){
    if (p < n) return (val[p] % MOD);

    int i, j;
    long long res = 0;
    Matrix pw = pow(mat, p - n + 1);

    for (i = 0; i < n; i++){
        long long x = (pw.ar[0][i] * val[n - i - 1]) % MOD;
        res = res + x;
    }
    return (res % MOD);
}

int main(){
    int n = 2;
    struct Matrix mat = Matrix(n);

    mat.ar[0][0] = mat.ar[0][1] = 1, mat.ar[1][0] = 1, mat.ar[1][1] = 0;
    long long val[] = {0, 1};

    long long res = matrix_expo(n, mat, val, 13);
    dbg(res);
    return 0;
}
