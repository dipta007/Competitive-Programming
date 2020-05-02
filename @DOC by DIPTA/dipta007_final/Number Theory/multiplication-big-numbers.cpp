/// Russian peasant method
/// Multiply big numbers
/// return (a*b)%c
ll modMultiply(ll a,ll b,ll c) {
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

