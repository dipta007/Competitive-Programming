/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


int parcourists[22][4];
LL H[200001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        int N, M; cin >> N >> M;
        LL W,X,Y,Z; cin >> H[1] >> H[2] >> W >> X >> Y >> Z;
        for(int i = 3; i <= N; i++) H[i] = (W * H[i-2] + X * H[i-1] + Y) % Z;
        REP(i, M) REP(j, 4) cin >> parcourists[i][j];

        double lo = 0.0, hi = 1e7;
        REP(i, 100) {
            double mid = (lo + hi) / 2.0;
            double s = H[1] - mid, e = H[1] + mid;
            bool possible = true;
            for(int j = 2; j <= N; j++) {
                double cs = H[j] - mid, ce = H[j] + mid;
                for(int k = 0; k < M; k++) {
                    if(parcourists[k][0] <= parcourists[k][1]) {
                        if(parcourists[k][0] >= j || parcourists[k][1] < j) continue;
                        ce = min(ce, e + parcourists[k][2]);
                        cs = max(cs, s - parcourists[k][3]);
                    } else {
                        if(parcourists[k][1] >= j || parcourists[k][0] < j) continue;
                        if(cs + parcourists[k][2] < s) cs = s - parcourists[k][2];
                        if(ce - parcourists[k][3] > e) ce = e + parcourists[k][3];
                    }
                }
                // cout << mid << " " << cs << " " << ce << " " << s << " " << e << endl;
                if(cs > ce) {
                    possible = false;
                    break;
                }
                s = cs;
                e = ce;
            }

            if(!possible) lo = mid;
            else hi = mid;
        }

        cout << "Case #" << ts << ": " << fixed << setprecision(9) << lo << endl;
    }
}
