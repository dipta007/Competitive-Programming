#include <bits/stdtr1c++.h>

#define MAX 100010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

typedef pair<int, int> Pair;

int n, q, ar[MAX];

struct node{
    Pair sum, prefix, suffix, subarray;
    node(){}
    node(Pair p){
        sum = p, prefix = p, suffix = p, subarray = p;
    }
    node(Pair a, Pair b, Pair c, Pair d){
        sum = a, prefix = b, suffix = c, subarray = d;
    }
} tree[MAX * 4];

Pair operator + (const Pair& a, const Pair& b){
    return Pair(a.first + b.first, a.second + b.second);
}

Pair F(Pair a, Pair b){ /// a is better than b
    if (a.first != b.first) return (a.first > b.first ? a : b);
    return (a.second > b.second ? a : b);
}

node merge(node a, node b){
    node c = a;
    c.sum = a.sum + b.sum;
    c.subarray = F(c.subarray, b.subarray);
    c.prefix = F(a.prefix, a.sum + b.prefix);
    c.suffix = F(b.suffix, a.suffix + b.sum);
    c.subarray = F(c.subarray, a.suffix + b.prefix);
    return c;
}

void build(int idx, int a, int b){
    int c = (a + b) >> 1, d = c + 1, p = idx << 1, q = p | 1;
    if (a == b){
        tree[idx] = node(Pair(ar[a], 1));
        return;
    }

    build(p, a, c);
    build(q, d, b);
    tree[idx] = merge(tree[p], tree[q]);
}

node query(int idx, int a, int b, int l, int r){
    int c = (a + b) >> 1, d = c + 1, p = idx << 1, q = p | 1;
    if (a == l && b == r) return tree[idx];
    if (r <= c) return query(p, a, c, l, r);
    else if (l >= d) return query(q, d, b, l, r);
    else return merge(query(p, a, c, l, c), query(q, d, b, d, r));
}

int main(){
    int i, j, k, l, r;

    while (scanf("%d", &n) != EOF){
        clr(tree);
        for (i = 1; i <= n; i++) scanf("%d", &ar[i]);
        build(1, 1, n);

        scanf("%d", &q);
        while (q--){
            scanf("%d %d", &l, &r);
            node res = query(1, 1, n, l, r);
            printf("%d %d\n", res.subarray.first, res.subarray.second);
        }
    }
    return 0;
}
