/**
Procedure:
    1. Assign MATMOD
    2. Assign row, col, a[][]
    Or, Call assign(r,c, temp[] )
    3. Use ^ to get the power of matrix
Time Complexity = O(row * col * col)
Space Complexity = O(row * col)
**** MUST HAVE AT LEAST ONE POSITIVE NUMBER
**/
int MATMOD = 1000000007;
class MAT
{
public:
    int a[MX][MX]; /// Set ll if needed
    int row, col;
    MAT() {}
    MAT(int r, int c)
    {
        row = r;
        col = c;
        mem();
    }
    void assign ( int r, int c, int temp[] )
    {
        row = r;
        col = c;
        int in = 0;
        FOR(i,0,row-1)
        {
            FOR(j,0,col-1)
            {
                a[i][j] = temp[in++];
            }
        }
    }
    void identity()
    {
        mem();
        for ( int i = 0; i < row; i++ )
            a[i][i] = 1;
    }
    void mem()
    {
        memset ( a, 0, sizeof a );
    }

#ifdef dipta007
    void print()   ///For debugging purpose
    {
        printf( "********\n");
        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < col; j++ )
                printf ( "%d ", a[i][j] );
            printf ( "\n" );
        }
        printf( "********\n");
    }
#else
    void print() {}
#endif
    MAT operator * (const MAT &b )
    {
        MAT res ( row, b.col );

        ll x,y = (ll)MATMOD*MATMOD;
        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < b.col; j++ )
            {
                x=0;
                for ( int k = 0; k < col; k++ )
                {
                    x += ((ll)a[i][k] * b.a[k][j]);
                    //debug(x, y)
                    if(x >= y)
                        x -= y; ///Change here if no mod.
                }
                res.a[i][j] = x % (ll)MATMOD; /// And here too
            }
        }
        return res;
    }
    MAT operator ^ ( ll p )
    {
        MAT res ( row, col );
        res.identity();
        MAT x = *this;
        while ( p )
        {
            if ( p & 1 )
            {
                res = res * x;
            }
            x = x * x;
            p >>= 1;
        }
        return res;
    }
};

