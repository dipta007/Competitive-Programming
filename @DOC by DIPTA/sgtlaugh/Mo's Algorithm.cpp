#include <bits/stdtr1c++.h>

#define MAX 1000010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

/// Mo's Algorithm for DQUERY, 0-based index by default
namespace mo{
    int q, counter, block_size = 437, out[MAX], ar[MAX], freq[MAX];

    struct Query{
        int l, r, d, idx;

        inline Query() {}
        inline Query(int a, int b, int c){
            idx = c;
            l = a, r = b, d = l / block_size;
        }

        inline bool operator < (const Query& other) const{
            if (d != other.d) return (d < other.d);
            return ((d & 1) ? (r < other.r) : (r > other.r));
        }
    } Q[MAX];

    /// Number of nodes, initial array, and block_size
    inline void init(int n, int *T, int sz){
        clr(freq);
        counter = 0, q = 0, block_size = max(1, sz);
        for (int i = 0; i < n; i++) ar[i] = T[i]; /// Change here if 1-based array
    }

    inline void push(int a, int b, int idx){
        Q[q++] = Query(a, b, idx);
    }

    inline void insert(int idx){
        if (!freq[ar[idx]]) counter++;
        freq[ar[idx]]++;
    }

    inline void erase(int idx){
        freq[ar[idx]]--;
        if (!freq[ar[idx]]) counter--;
    }

    inline void run(){
        sort(Q, Q + q);
        int i, l, r, a = 0, b = 0; /// Change here if 1-based array

        for (counter = 0, i = 0; i < q; i++){
            l = Q[i].l, r = Q[i].r;
            while (a > l) insert(--a);
            while (a < l) erase(a++);
            while (b <= r) insert(b++);
            while (b > (r + 1)) erase(--b);
            out[Q[i].idx] = counter;
        }
    }

    inline void print(){
        for (int i = 0; i < q; i++) printf("%d\n", out[i]);
    }
}

int n, ar[MAX];

int main(){
    int i, j, k, q, a, b;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &ar[i]);
    mo::init(n, ar, 447);

    scanf("%d", &q);
    for (i = 0; i < q; i++){
        scanf("%d %d", &a, &b);
        mo::push(--a, --b, i);
    }

    mo::run();
    mo::print();
    return 0;
}
