#include <bits/stdtr1c++.h>

#define MAXN 200010
#define MAXQ 200010
#define MAXV 1000010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

const int block_size = 533;

namespace mo{ /// 0 based index for arrays and queries
    long long res, out[MAXQ];
    int q, lim, ar[MAXN], freq[MAXV];

    struct query{
        int l, r, d, idx;

        inline query() {}
        inline query(int a, int b, int c){
            idx = c;
            l = a, r = b, d = l / block_size;
        }

        inline bool operator < (const query& other) const{
            if (d != other.d) return (d < other.d);
            if (r == other.r) return (l < other.l);
            return (r < other.r);
        }
    } Q[MAXQ];

    inline void init(int n, int *T){
        clr(freq);
        res = 0, q = 0;
        for (int i = 0; i < n; i++) ar[i] = T[i];
        lim = (*max_element(ar, ar + n) + 1) * sizeof(int); /// long long freq
    }

    inline void push(int a, int b){
        Q[q] = query(a, b, q);
        q++;
    }

    inline void insert(int idx){
        res -= (long long)ar[idx] * freq[ar[idx]] * freq[ar[idx]];
        freq[ar[idx]]++;
        res += (long long)ar[idx] * freq[ar[idx]] * freq[ar[idx]];
    }

    inline void erase(int idx){
        res -= (long long)ar[idx] * freq[ar[idx]] * freq[ar[idx]];
        freq[ar[idx]]--;
        res += (long long)ar[idx] * freq[ar[idx]] * freq[ar[idx]];
    }

    inline void run(){
        sort(Q, Q + q);
        int i, j, l, r, a = 0, b = MAXN;

        for (i = 0; i < q; i++){
            l = Q[i].l, r = Q[i].r;
            if (b > r){
                res = 0;
                memset(freq, 0, lim);
                for (j = l; j <= r; j++) insert(j);
            }
            else{
                for (j = l; j < a; j++) insert(j);
                for (j = b + 1; j <= r; j++) insert(j);
                for (j = a; j < l; j++) erase(j);
                for (j = r + 1; j <= b; j++) erase(j);
            }

            a = l, b = r;
            out[Q[i].idx] = res;
        }
        for (i = 0; i < q; i++) printf("%lld\n", out[i]);
    }
}

int n, ar[MAXN];

int main(){
    int n, q, i, j, k, a, b;

    scanf("%d %d", &n, &q);
    for (i = 0; i < n; i++) scanf("%d", &ar[i]);

    mo::init(n, ar);
    while (q--){
        scanf("%d %d", &a, &b);
        mo::push(a - 1, b - 1);
    }
    mo::run();
    return 0;
}
