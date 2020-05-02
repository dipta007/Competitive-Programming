double mat[110][110];

void make_matrix(){
}

db gauss( int R, int C )
{
    int i, j, k;

    for (i = 0; i < R; i++) {
        k = i;
        for (j = i+1; j < C; j++) if (fabs(mat[j][i]) > fabs(mat[k][i])) k = j;
        if (k != i) for (j = 0; j <= C; j++) swap(mat[k][j], mat[i][j]);
        for (j = i+1; j <= C; j++) mat[i][j] /= mat[i][i];
        mat[i][i] = 1;
        for (k = 0; k < R; k++) if( k != i ) {
            double t = mat[k][i];
            if (t == 0.0L) continue;
            for (j = i; j <= C; j++) mat[k][j] -= t * mat[i][j];
            mat[k][i] = 0.0L;
        }
    }
    vector<db>sol;
    rep(i,R) sol.pb(mat[i][C]);
    return sol[0];
}
