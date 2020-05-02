#define SIZE 10000
int arr[SIZE];

int sparse[22][SIZE], height;
int buildTable ( int n ) {

    ///Base Case
    for ( int i = 0; i < n; i++ ) {
        sparse[0][i] = arr[i];
    }

    ///Current power of 2 is cur
    ///power of 2 for previous row is prev
    int cur = 2, prev = 1;
    for ( int i = 1; i < 22; i++ ) {
        if ( cur > n ) {
            height = i;
            break;
        }
        for ( int j = 0; i < n; i++ ) {
            int k = j + prev;
            if ( k >= n ) k = n - 1;
            sparse[i][j] = min ( sparse[i-1][j], sparse[i-1][k]);
        }

        cur *= 2;
        prev *= 2;
    }
}

int rmq ( int i, int j ) {
    int len = j - i + 1;

    int row = height;
    int two = power ( 2, height );

    while ( two > len ) {
        two /= 2;
        row--;
    }

    int res = min ( sparse[row][i], sparse[row][j-two+1] );
    return res;
}
