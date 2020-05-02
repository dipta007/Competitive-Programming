#include <bits/stdc++.h>

using namespace std;

/*
1. Assign MATMOD
2. Declare MAT win row and col.
*/
typedef long long vlong;

vlong MATMOD = 1000000000 + 7;
struct MAT{
    vlong a[3][3];///Maximum dimension of the matrix
    int row, col;
    MAT(){}
    MAT(int r, int c){
        row = r;
        col = c;
        mem();
    }
    void assign ( int r, int c ) {
        row = r;
        col = c;
    }

    void identity(){
        mem();
        for ( int i = 0; i < row; i++ ) a[i][i] = 1;
    }
    void mem(){
        memset ( a, 0, sizeof a );
    }
    void print() { ///For debugging purpose
        printf( "********\n");
        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < col; j++ ) printf ( "%llu ", a[i][j] );
            printf ( "\n" );
        }
    }
    MAT operator * ( MAT b ) { ///Matrix Multiplication N^3
        MAT res ( row, b.col );

        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < b.col; j++ ){
                for ( int k = 0; k < col; k++ )
                    res.a[i][j] = ( res.a[i][j] + a[i][k] * b.a[k][j] ) % MATMOD; ///Change here if no mod.
            }
        }
        return res;
    }
    MAT operator ^ ( vlong p ) { ///Matrix Exponentiation
        MAT res ( row, col ); res.identity();
        MAT x = *this;
        while ( p ){
            if ( p & 1 ){
                res = res * x;
            }
            x = x * x;
            p >>= 1;
        }
        return res;
    }
};


int main () {

    MAT init(2,1);
    init.a[0][0] = 1;
    init.a[1][0] = 1;

    MAT coef(2,2);
    coef.a[0][0] = 1; coef.a[0][1] = 1;
    coef.a[1][0] = 1; coef.a[1][1] = 0;

    init.print();

    coef.print();

    MAT res = (coef^3) * init;
    res.print();

    return 0;
}
