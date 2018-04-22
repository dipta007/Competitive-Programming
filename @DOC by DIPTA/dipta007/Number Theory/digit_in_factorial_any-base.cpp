int factorialDigitExtended ( int n, int base )
{
    double x = 0;
    for ( int i = 1; i <= n; i++ )
    {
        x += log10 ( i ) / log10(base);
    }
    int res = ( (int) x ) + 1;
    return res;
}

