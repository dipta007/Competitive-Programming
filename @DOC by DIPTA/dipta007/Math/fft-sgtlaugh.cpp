#include <bits/stdtr1c++.h>
using namespace std;

typedef complex<double> complx;

/// Computes the discrete fourier transformation of the vector when inv = 1
/// Computes the inverse discrete fourier transformation when inv = -1

vector <complx> FFT(vector <complx> ar, int inv){
    int i, j, l, len, n = ar.size();
    const double p = 4.0 * inv * acos(0.0);

    for (i = 1, j = 0; i < n; i++){
        for (l = n >> 1; j >= l; l >>= 1) j -= l;
        j += l;
        if (i < j) swap(ar[i], ar[j]);
    }

    for (l = 1, len = 2; len <= n; l <<= 1, len <<= 1){
        double theta = p / len;
        complx mul(cos(theta), sin(theta));

        for (i = 0; i < n; i += len){
            complx w(1.0, 0.0);
            for (j = 0; j < l; j++){
                complx u = ar[i + j], v = ar[i + j + l] * w;
                ar[i + j] = u + v, ar[i + j + l] = u - v;
                w *= mul;
            }
        }
    }

    if (inv == -1){
        for (i = 0; i < n; i++) ar[i] /= n;
    }
    return ar;
}

/***
    Computes the circular convolution of A and B, denoted A * B
    A and B must be of equal size, if not normalize before calling function
    Example to demonstrate convolution for n = 5:

    c0 = a0b0 + a1b4 + a2b3 + a3b2 + a4b1
    c1 = a0b1 + a1b0 + a2b4 + a3b3 + a4b2
    ...
    c4 = a0b4 + a1b3 + a2b2 + a3b1 + a4b0


    Note: If linear convolution is required, pad with zeros appropriately, as in multiplication

***/

vector <complx> convolution(vector <complx> A, vector <complx> B){
    int n, m, i;
    n = A.size();
    vector <complx> C;
    m = 1 << (32 - __builtin_clz(n) - (__builtin_popcount(n) == 1));
    A.resize(m, 0), B.resize(m, 0), C.resize(m, 0);

    A = FFT(A, 1), B = FFT(B, 1);
    for (i = 0; i < m; i++) C[i] = A[i] * B[i];
    return FFT(C, -1);
}

/// Multiplies two polynomials A and B and return the coefficients of their product
vector <complx> multiply(vector <complx> A, vector <complx> B){
    int n, m, i;
    vector <complx> C;
    n = A.size() + B.size() - 1;
    m = 1 << (32 - __builtin_clz(n) - (__builtin_popcount(n) == 1));
    A.resize(m, 0), B.resize(m, 0), C.resize(m, 0);

    A = FFT(A, 1), B = FFT(B, 1);
    for (i = 0; i < m; i++) C[i] = A[i] * B[i];
    return FFT(C, -1);
}

int main(){
    vector <complx> A = {1, 2, 3, 4};
    vector <complx> B = {7, 29, 13, 17};

    vector <complx> C = convolution(A, B);
    for (int i = 0; i < C.size(); i++) trace(C[i].real());
}

