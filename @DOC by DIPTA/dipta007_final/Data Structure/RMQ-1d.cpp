/**
Procedure:
    1. Call preCalculate(MAX) once before all test cases
    2. Call build table once for each test case
    3. Call rmq(l, r) to get the result
Time Complexity = RMQ - O(1), build(N log N)
**/
int arr[100004];
#define SIZE 300005
int sparse[30][SIZE], height;
int sparsemx[30][SIZE];
int b[100004];
int r[100004];

void preCalculate(int n)
{
    int xx = 1,rr=0;
    FOR(i,1,n)
    {
        if(i!=1 && !(i&(i-1)))
        {
            xx *= 2;
            rr ++;
        }
        b[i]=xx;
        r[i]=rr;
    }
}
int buildTable ( int n ) {
    ///Base Case
    for ( int i = 0; i < n; i++ ) {
        sparse[0][i] = arr[i];
        sparsemx[0][i] = arr[i];
    }
    ///Current power of 2 is cur
    ///power of 2 for previous row is prev
    int cur = 2, prev = 1;
    for ( int i = 1; i < 22; i++ ) {
        if ( cur > n ) {
            height = i;
            break;
        }
        for ( int j = 0; j < n; j++ ) {
            int k = j + prev;
            if ( k >= n ) k = n - 1;
            sparse[i][j] = min ( sparse[i-1][j], sparse[i-1][k]);
            sparsemx[i][j] = max ( sparsemx[i-1][j], sparsemx[i-1][k]);
        }

        cur *= 2;
        prev *= 2;
    }
}
pii rmq ( int i, int j ) {
    int len = j - i + 1;
//    int row = height;
//    int two = pow ( 2, height );
//
//    while ( two > len ) {
//        two /= 2;
//        row--;
//    }
    int two = b[len];
    int row = r[len];

    int res = min ( sparse[row][i], sparse[row][j-two+1] );
    int res1 = max ( sparsemx[row][i], sparsemx[row][j-two+1] );
    return pii(res,res1);
}

