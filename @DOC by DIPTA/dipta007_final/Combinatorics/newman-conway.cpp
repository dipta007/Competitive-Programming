/**
Sequence: 1 1 2 2 3 4 4 4 5 6 7 7
**/
int f[MAX];
void newmanConway(int n)
{
    f[0] = 0;
    f[1] = f[2] = 1;

    FOR(i, 3, n)
    {
        f[i] = f[ f[i-1] ] + f[ i - f[i-1] ];
    }
}
