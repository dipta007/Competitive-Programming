#define MAX 100010
int n, q, ar[MAX];
struct node{
    pii sum, prefix, suffix, subarray;
    node(){}
    node(pii p){
        sum = p, prefix = p, suffix = p, subarray = p;
    }
    node(pii a, pii b, pii c, pii d){
        sum = a, prefix = b, suffix = c, subarray = d;
    }
} tree[MAX * 4];

pii operator + (const pii& a, const pii& b){
    return pii(a.first + b.first, a.second + b.second);
}

pii F(pii a, pii b){ /// a is better than b
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
        tree[idx] = node(pii(ar[a], 1));
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

