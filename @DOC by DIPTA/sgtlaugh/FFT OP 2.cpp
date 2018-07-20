#include <bits/stdtr1c++.h>

#define TMAX 10010
#define CUTOFF 512
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

#pragma OPT_LEVEL 4
#pragma GCC OPTIMIZE("+Oaggressive")
#pragma GCC OPTIMIZE("+Onolimit")
#pragma GCC OPTIMIZE("+Oall")

using namespace std;

struct complx{
    double real, img;

    inline complx(){
        real = img = 0.0;
    }

    inline complx(double x){
        real = x, img = 0.0;
    }

    inline complx(double x, double y){
        real = x, img = y;
    }

    inline void operator += (complx &other){
        real += other.real, img += other.img;
    }

    inline void operator -= (complx &other){
        real -= other.real, img -= other.img;
    }

    inline complx operator + (complx &other){
        return complx(real + other.real, img + other.img);
    }

    inline complx operator - (complx &other){
        return complx(real - other.real, img - other.img);
    }

    inline complx operator * (complx& other){
        return complx((real * other.real) - (img * other.img), (real * other.img) + (img * other.real));
    }
};

complx wlen_P[TMAX >> 1], A[TMAX], B[TMAX], C[TMAX];

void FFT(complx *ar, int n, int inv){
    int i, j, l, len, len2;
    const double p = 4.0 * inv * acos(0.0);

    for (i = 1, j = 0; i < n; i++){
        for (l = n >> 1; j >= l; l >>= 1) j -= l;
        j += l;
        if (i < j) swap(ar[i], ar[j]);
    }

    for (len = 2; len <= n; len <<= 1){
        len2 = len >> 1;
        double theta = p / len;
        complx mul(cos(theta), sin(theta));

        wlen_P[0] = complx(1, 0);
        for (i = 1; i < len2; i++) wlen_P[i] = (wlen_P[i - 1] * mul);

        for (i = 0; i < n; i += len){
            complx t, *pu = ar + i, *pv = ar + i + len2, *pend = ar + i + len2, *pw = wlen_P;
            for (; pu != pend; pu++, pv++, pw++){
                t = (*pv) * (*pw);
                *pv = *pu - t;
                *pu += t;
            }
        }
    }

    if (inv == -1){
        double tmp = 1.0 / n;
        for (i = 0; i < n; i++) ar[i].real *= tmp; /// ar[i].img is unchanged because of optimization, add ar[i].img *= tmp if imaginary part is also required
    }
}

void convolution(int n, complx* A, complx* B, complx* C){
    int i, m;
    m = 1 << (32 - __builtin_clz(n) - (__builtin_popcount(n) == 1));

    for (i = n; i < m; i++) A[i] = B[i] = complx(0);
    FFT(A, m, 1), FFT(B, m, 1);
    for (i = 0; i < m; i++) C[i] = A[i] * B[i];
    FFT(C, m, -1);
}

int multiply(int a, int b, complx* A, complx* B, complx* C){
    int i, j, n, m;

    if (((long long)a * b) < CUTOFF){
        for (i = 0; i < (a + b); i++) C[i] = complx(0);

        for (i = 0; i < a; i++){
            for (j = 0; j < b; j++){
                complx tmp = A[i] * B[j];
                C[i + j] += tmp;
            }
        }
        return (a + b - 1);
    }

    n = a + b - 1;
    m = 1 << (32 - __builtin_clz(n) - (__builtin_popcount(n) == 1));

    for (i = a; i < m; i++) A[i] = complx(0);
    for (i = b; i < m; i++) B[i] = complx(0);
    FFT(A, m, 1), FFT(B, m, 1);
    for (i = 0; i < m; i++) C[i] = A[i] * B[i];
    FFT(C, m, -1);

    return m;
}

int main(){
}
