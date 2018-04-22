#define MAX 100010

namespace fenwick2D{
    unsigned int tree[MAX * 160];
    int n, idx, root[MAX], L[MAX * 160], R[MAX * 160];

    inline void init(int nsize){
        n = nsize + 1, idx = 0;
        clr(tree), clr(root), clr(L), clr(R);
    }

    inline void update(int &cur, int a, int b, int p, unsigned int v){
        if (!cur) cur = ++idx;
        tree[cur] += v;

        if (a ^ b){
            int m = (a + b) >> 1;
            if (p <= m) update(L[cur], a, m, p, v);
            else update(R[cur], m + 1, b, p, v);
        }
    }

    inline unsigned int query(int cur, int a, int b, int r){
        if (!cur) return 0;
        if (r >= b) return tree[cur];

        int m = (a + b) >> 1;
        if (r <= m) return query(L[cur], a, m, r);
        return tree[L[cur]] + query(R[cur], m + 1, b, r);
    }

    inline void update(int x, int y, unsigned int v){
        while (x <= n){
            update(root[x], 1, n, y, v);
            x += (x & -x);
        }
    }

    void update(int i, int j, int k, int l, int v){
        if (i > k || j > l) return;

        update(i, j, v);
        update(k + 1, j, -v);
        update(k + 1, l + 1, v);
        update(i, l + 1, -v);
    }

    inline unsigned int query(int x, int y){
        unsigned int res = 0;
        while (x){
            res += query(root[x], 1, n, y);
            x ^= (x & -x);
        }
        return res;
    }
}
/// fenwick2D::init(n);
/// fenwick2D::update(1, r, l, n, l - r);
