
#define MAXROW 54
#define MAXCOL 54


/// n = number of equations
/// m = number of variables
int Gauss(int a[MAXROW][MAXCOL],const int&n,const int&m){
    int res=0,r=0;
    for(int i=0;i<m;++i){
        for(int j=r;j<n;++j)
            if(a[j][i]){
                for(int k=i;k<=m;++k)
                    swap(a[j][k],a[r][k]);
                break;
            }
        if(a[r][i]==0){
            ++res;
            continue;
        }
        for(int j=0;j<n;++j)
            if((j!=r)&&(a[j][i]!=0))
                for(int k=i;k<=m;++k)
                    a[j][k]^=a[r][k];
        ++r;
    }
    for(int i=r;i<n;++i)
        if(a[i][m])
            return -1;
    return res;
}
