#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
using namespace std;

const double EPS = 1e-9;

// #define double long double
typedef complex<double> complx;
#define vi vector<int>

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
  ios_base::sync_with_stdio(0);cin.tie(0);

  int a, b, c, d;
  while (cin >> a) {
    cin >> b >> c >> d;
    vector <complx> A(500002), B(500002);
    for (int i=a; i<=b; i+= 1) {
      A[i] = 1;
    }
    for (int i=b; i<=c; i+=1) {
      B[i] = 1;
    }
    vector<complx> res = multiply(A, B);
    // cout << res[500000+500000] << endl;
    long long cnt = 0;
    // cout << res.size() << endl;
    for (int i=0; i<res.size(); i += 1) {
      int now = round(res[i].real());
      
      if (now) {
        // cout << i << " " << c;
        // cout << i << " " << round(now) << " " << res[i].real() << endl;
        if (i >= c) {
          int r = min(i-1, d);
          // cout << " in " << r << " " << (r-c+1) << " " << cnt << endl;
          if (r >= c) {
            cnt += ((long long)now * (r-c+1));
          }
        }
      }
    }
    cout << cnt << endl;
    // for (int i = 0; i < res.size(); i++) cout << res[i].real() << endl;
  }
    // vector <int> A = {0, 1, 1, 1};
    // vector <int> B = {0, 0, 1, 0, 1};

    // // vector <complx> C = multiply(A, B);
}