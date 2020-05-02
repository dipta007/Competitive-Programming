#define SIZE 10000
int arr[SIZE][SIZE];

int sparse[22][SIZE][SIZE], height;
int buildTable ( int n ) {

    ///Base Case
    for ( int i = 0; i < n; i++ ) {
        for(int j=0; j<n; j++)
        {
            sparse[0][i][j] = arr[i][j];
        }
    }
    ///Current power of 2 is cur
    ///power of 2 for previous row is prev
    int cur = 2, prev = 1;
    for ( int i = 1; i < 22; i++ ) {
        if ( cur > n ) {
            height = i;
            break;
        }
        for(int r=0; r<n; r++)
        {
            for(int c=0; c<n; c++)
            {
                int k = j+prev;
                if(k>=n) k = n-1;
                sparse[i][r][c] = min( sparse[i-1][r][c], sparse[i-1][k][c]);
            }
        }
        cur *= 2;
        prev *= 2;
    }
}
int rmq ( int i, int j , int s) {
    int len = s*s;

    int row = height;
    int two = pow ( 2, height );

    while ( two > len ) {
        two /= 2;
        row--;
    }

    int res = min ( sparse[row][i][j], sparse[row][i][s*s-two] );
    return res;
}



