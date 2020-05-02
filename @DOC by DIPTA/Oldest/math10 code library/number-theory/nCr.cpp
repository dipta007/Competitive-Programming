const int MAX = 1000 + 7;
const int MOD = 1e9 + 7;
int64 nCr[MAX][MAX];
void make_nCr(){
     nCr[0][0] = 1;
        For(i,MAX-7) {
                nCr[i][0] = 1;
                For(j,i) {
                        nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j])%MOD;
                }
        }
}
