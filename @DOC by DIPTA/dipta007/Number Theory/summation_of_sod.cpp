///http://rizoantoufiq.blogspot.com/2015/12/lightoj-1098-new-function.html
ll ssod(ll n)
{
    ll ans=0;
    for(ll i=2;i*i<=n;i++)
    {
        ll j=n/i;
        ans+=(i+j)*(j-i+1)/2;
        ans+=i*(j-i);
    }
    return ans;
}
