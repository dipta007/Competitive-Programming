#define MAX = 10000004

int Phi[MAX];
void sievePHI()
{
    Phi[1] = 1;
    int i, j;
    for( i = 2; i < MAX; i++ ) if( !Phi[i] )
        {
            Phi[i] = i - 1;
            for( j = i + i; j < MAX; j += i )
            {
                if( !Phi[j] ) Phi[j] = j;
                Phi[j] = Phi[j] / i * ( i - 1 );
            }
        }
}


int phi (int n)
{
    int ret = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            ret -= ret / i;
        }
    }
    if (n > 1) ret =ret - (ret / n);
    return ret;
}

/** Formula **/
Phi(n) = n * Product of (1- 1/p) , p that divides n

