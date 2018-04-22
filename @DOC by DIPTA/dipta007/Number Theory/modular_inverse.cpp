/** Fermats Theorem **/
( A / B ) % m = ( ( A % m ) * ( B^( m - 2 ) % m ) ) % m  , if m is prime

/**
Procedure:
    1. Call modInv(x, mod)
**/
typedef pair <ll, ll> pll
pll extendedEuclid(ll a, ll b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
		return pll(1, 0);
    else
    {
        pll d = extendedEuclid(b, a % b);
        return pll(d.ss, d.ff - d.ss * (a / b));
    }
}
ll modularInverse(ll a, ll M) {
  pll ret = extendedEuclid(a, M);
  return ((ret.ff % M) + M) % M;
}
