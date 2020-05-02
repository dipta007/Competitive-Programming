int tot;
vector<int>dig;
ll dp[20][2][200][2];
ll call(int pos,int flag,int sum,int strt)
{
    if(pos==tot)return sum;
    ll &ret=dp[pos][flag][sum][strt];
    if(ret!=-1)return ret;
    ll ans=0;
    if(pos==0)
    {
        repI(i,dig[pos]+1)
        {
            ans+=call(pos+1,i==dig[pos],sum+(i==0&&strt),(strt||i!=0));
        }
    }
    else
    {
        if(flag)
        {
            for(int i=0;i<=dig[pos];i++)
            {
                ans+=call(pos+1,i==dig[pos],sum+(i==0&&strt),(strt||i!=0));
            }
        }
        else
        {
            repI(i,10)
                ans+=call(pos+1,0,sum+(i==0&&strt),(strt||i!=0));
        }
    }
    return ret=ans;
}
void calc(ll num)
{
    dig.clear();
    while(num)
    {
        dig.push_back(num%10);
        num/=10;
    }
    reverse(ALL(dig));
    tot=dig.size();
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    getI(t);
    rep(cs,t)
    {
        SET(dp);
        ll a,b;
        getL(a);
        getL(b);
        a--;
        ll ansa,ansb;
        if(a<0)ansa=0;
        else if(a<10)ansa=1;
        else
        {
            calc(a);
            ansa=call(0,0,0,0)+1;
        }
        SET(dp);
        calc(b);
        ansb=call(0,0,0,0)+1;
       // debug(ansa,ansb)
        printf("Case %d: %lld\n",cs,ansb-ansa);
    }




    return 0;
}

