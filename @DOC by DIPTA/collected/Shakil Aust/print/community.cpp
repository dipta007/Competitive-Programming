using namespace std;

#include <cstdio>
#include <algorithm>

#define frequency first
#define mostFrequent second

const int N = 100000 + 5;

struct segmentTree {
    int ans;
    pair <int, int> prefix, suffix;
} tree [N * 4];

segmentTree createNode () {
    int value;
    segmentTree temp;

    scanf ("%d", &value);
    temp.prefix.frequency = temp.suffix.frequency = temp.ans = 1;
    temp.prefix.mostFrequent = temp.suffix.mostFrequent = value;
    return temp;
}

segmentTree combine (segmentTree left, segmentTree right) {
    segmentTree temp;

    temp.prefix.frequency    = left.prefix.frequency + (left.prefix.mostFrequent == right.prefix.mostFrequent ? right.prefix.frequency : 0);
    temp.prefix.mostFrequent = left.prefix.mostFrequent;

    temp.suffix.frequency    = right.suffix.frequency + (right.suffix.mostFrequent == left.suffix.mostFrequent ? left.suffix.frequency : 0);
    temp.suffix.mostFrequent = right.suffix.mostFrequent;

    temp.ans                 = max (max (left.ans, right.ans), (left.suffix.mostFrequent ==  right.prefix.mostFrequent ? left.suffix.frequency + right.prefix.frequency : 0));

    return temp;
}

void buildTree (int root, int left, int right) {
    if (left == right)
        tree [root] = createNode ();
    else {
        int mid = (left + right) >> 1;
        buildTree (root << 1, left, mid);
        buildTree (root << 1 | 1, mid + 1, right);
        tree [root] = combine (tree [root << 1], tree [root << 1 | 1]);
    }
}

segmentTree query (int root, int left, int right, int rangeLeft, int rangeRight) {
    if (left == rangeLeft && right == rangeRight)
        return tree [root];
    int mid = (left + right) >> 1;
    if (rangeRight <= mid)
        return query (root << 1, left, mid, rangeLeft, rangeRight);
    if (rangeLeft > mid)
        return query (root << 1 | 1, mid + 1, right, rangeLeft, rangeRight);
    return combine (query (root << 1, left, mid, rangeLeft, mid), query (root << 1 | 1, mid + 1, right, mid + 1, rangeRight));
}

int main () {
    int t, caseno = 0;
    // freopen("input.txt", "r", stdin);
    scanf ("%d", &t);

    while (t --) {
        int n, c, q, i, x, y;
        scanf ("%d %d %d", &n, &c, &q);

        buildTree (1, 1, n);

        printf("Case %d:\n", ++ caseno);
        for (i = 0; i < q; ++ i) {
            scanf ("%d %d", &x, &y);
            printf ("%d\n", query (1, 1, n, x, y).ans);
        }
    }

    return 0;
}

