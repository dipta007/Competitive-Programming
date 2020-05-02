/// leading digits of n to power k,
/// dig = how many digits
ll leadingdigit(ll n,ll k,ll dig)
{
    ///log10(x)=y
    double y=(double)k*log10(n);

    ///if y=123.456 we are setting y=0.456
    y=y-floor(y);

    ///we are getting 10^y for reverse processing
    y=pow(10,y);

    ///now we are getting the digits by shifting the decimal to right
    rep(i,dig-1)y*=10;

    return (ll)floor(y);
}
