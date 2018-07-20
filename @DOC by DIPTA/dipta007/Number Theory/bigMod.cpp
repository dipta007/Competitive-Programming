ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

/// Russian peasant method
/// Multiply big numbers
/// return (a*b)%c
ll modmultiply(ll a,ll b,ll c) {
    ll res = 0,y = a%c;
    while(b > 0) {
        if(b%2 == 1) {
            res = (res+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return res%c;
}
