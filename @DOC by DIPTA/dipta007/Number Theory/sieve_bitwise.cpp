const int MX = 1e7
int status[(MX/32)+2];
void sieve()
{
    int i, j, sqrtN;
    sqrtN = int( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( bitCheck(status[i>>5],i&31)==0)
        {
            for( j = i*i; j <= N; j += (i<<1) )
            {
                status[j>>5] = bitOn(status[j>>5],j & 31);
            }
        }
    }
    puts("2");
    for(i=3; i<=N; i+=2)
        if( Check(status[i>>5],i&31)==0)
            printf("%d\n",i);
}
