

/// Cumulative sum query with update

void update ( int x, int val ) {
    while ( x < limit ) {
        bit[x] += val;
        x += x & (-x);
    }
}

int query ( int x ) {
    int res = 0;

    while ( x ) {
        res += bit[x];
        x -= x & (-x);
    }

    return res;
}


/// 2D Cumulative sum

int bit[M][M];

void update ( int x, int y, int val ) {
    for ( int i = x; i < limit; i += i & (-i) ) {
        for ( int j = y; j < limit; j += j & (-j) ) {
            bit[i][j] += val;
        }
    }
}

int query ( int x, int y ) {
    int res = 0;
    for ( int i = x; i ; i -= i & (-i) ) {
        for ( int j = y; j; j -= j & (-j) ) {
            res += bit[i][j];
        }
    }
}
