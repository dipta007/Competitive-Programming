#include <stdio.h>

int a, b, c, d, e, f;
int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d",&cases);
    if(cases>100)
        return 0;
    while( cases-- )
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        if(a>=0 && b>=0 && c>=0 && d>=0 && e>=0 && f>=0 && n>=0 && n<=10000)
        {
            printf("Case %d: %d\n",++caseno, fn(n) % 10000007);
        }
    }
    return 0;
}
