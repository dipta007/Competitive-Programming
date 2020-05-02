/*
mu[n] = 1 if n is a square-free positive integer with an even number of prime factors.
mu[n] = −1 if n is a square-free positive integer with an odd number of prime factors.
mu[n] = 0 if n has a squared prime factor.
*/
int mu[mx];
void mobius_function() {
    memo(mu,0);
    mu[1] = 1;
    For(i,mx-7)
        for(int j = 2*i; j<=mx-7; j += i)
            mu[j] -= mu[i];
}
