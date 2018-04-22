const ll mod=2760727302517;
ll modu(ll a)
{
    if(a>=0)return a%mod;
    return ((a%mod)+mod)%mod;
}
ll add(ll a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
ll mul(ll q1,ll q2)
{
    if(q1==0||q2==0)return 0;
    if(q1<q2) swap(q1,q2);
    ll rs=0;
    for(;q2;q2>>=1)
    {
        if(q2&1LL)
        {
            rs=add(rs,q1);
        }
        q1=add(q1,q1);
    }
    return rs;
}
