
#pragma comment(linker, "/stack:640000000")

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define scanl(a) scanf("%lld",&a)
#define scanii(a,b) scanf("%d%d",&a,&b)
#define scaniii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scanll(a,b) scanf("%lld%lld",&a,&b)
#define scanlll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scani(a) scanf("%d",&a)
#define clr(a) memset(a,0,sizeof(a))
#define clr_(a) memset(a,-1,sizeof(a))
#define pb(a) push_back(a)
#define pii pair<int,int>
#define sqr(a) a*a
#define eps 1e-9
#define inf INT_MAX
#define pi acos(-1.0)
#define ff first
#define ss second
#define INF 1e18
#define siz 100010
#define vsort(v) sort(v.begin(),v.end())
int Set(int n,int pos){return n=n | (1<<pos);}///sets the pos bit
int reset(int n,int pos){return n=n & ~(1<<pos);}///resets the pos bit
bool check(int n,int pos){return (bool)(n & (1<<pos));}///return pos bit
ll power(ll x,ll n)
{
    ///complexity O(logn)
    if(n==0)return 1;
    else if(n%2==0)
    {
        ll y=power(x,n/2);
        return y*y;
    }
    else
        return x*power(x,n-1);
}
int strTOint(string s)
{
    stringstream ss;
    int x;
    ss<<s;
    ss>>x;
    return x;
}
double geo_dist(int a,int b,int c,int d)
{
    double dd=(double)(a-c)*(a-c)+(b-d)*(b-d);
    double r=sqrt(dd)+eps;
    return r;
}
ll bigmod(ll a,ll p,ll mod)
{
    ll ans=1;
    while(p)
    {
        if(p&1)ans=ans*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ans;
}
ll euclid_x,euclid_y,euclid_d,euclid_g;
void ext_gcd(ll a,ll b)
{
    if(b==0)
    {
        euclid_x=1;euclid_y=0;euclid_d=a;return;
    }
    ext_gcd(b,a%b);
    ll x1=euclid_y;
    ll y1=euclid_x-(a/b)*euclid_y;
    euclid_x=x1;
    euclid_y=y1;
}

ll modInv (ll a,ll m ) {

    ///if m prime
    ///ll x = bigmod( a, m - 2, m ); ///(ax)%m = 1
   /// i m not prime;
    ext_gcd( a, m);
    ///Process x so that it is between 0 and m-1
    euclid_x %= m;
    if ( euclid_x < 0 ) euclid_x += m;
    return euclid_x;
}
vector<int>num;
void input(string s)
{
    ///declare a gloabl vector num & values will be in num
    istringstream ss(s);
    int n;
    while(ss>>n)
    {
        num.pb(n);
    }
}
int fx[]={0,0,-1,1,-1,1,1,-1};
int fy[]={1,-1,0,0,1,1,-1,-1};
///FOR KNIGHT MOVE
///int fx[]={2,1,-1,-2,-2,-1,1,2};
///int fy[]={1,2,2,1,-1,-2,-2,-1};
map<int,int>mp;
#define N 100010
vector<pii>v,v1;
vector<int>v2;
int n,m;
int main()
{
    /// ios_base::sync_with_stdio(0);
    /// cin.tie(0);
//    freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
//    v.pb(pii(1,2));
//    v.pb(pii(2,4));
//    v.pb(pii(3,5));
    scanii(n,m);
    int arr[n+5][m+5];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)arr[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            {
                scani(arr[i][j]);
            }
    }

    int x=1,y=0;
    for(int i=1;i<=m;i++)///column;
    {
        int flag=0;
        x=1;
        for(int j=1;j<=n;j++)
        {

            if(arr[j][i]>=arr[j-1][i])
            {
              //  flag=0;
            }
            else
            {
               // flag=1;
             //   cout<<x<<" "<<j-1<<endl;
               // mp[x]=max(mp[x],j-1);
                v.pb(pii(x,j-1));
                x=j;
            }
            if(j==n)v.pb(pii(x,j));
        }
    }
      sort(v.begin(),v.end());
  /*  for(int i=0;i<v.size();i++)
    {
        cout<<v[i].ff<<" "<<v[i].ss<<endl;
    }
    cout<<"*******"<<endl;*/
    int len=v.size();

    int k=0;
    for(int i=0;i<len;)
    {
        int j=i;
        int k=j;
        int f;
        for(j=i;j<len;j++)
        {
            f=0;
            if(v[j].ff==v[i].ff)continue;
            j--;
            f=1;
            v2.pb(v[j].ff);
            v1.pb(pii(v[j].ff,v[j].ss));
            k=j;
            for(k=j;k<len;k++)
            {
                if(v[k].ss<=v[j].ss)continue;
                break;
            }
            break;
        }
        i=max(k,j);
        if(i>=len-1 && f==0)
        {
            i=len-1;
            v1.pb(pii(v[i].ff,v[i].ss));v2.pb(v[i].ff);break;
        }
     //   cout<<i<<endl;
       // break;
    }
//    for(int i=0;i<v1.size();i++)
//    {
//        cout<<v1[i].ff<<" "<<v1[i].ss<<endl;
//    }
    int q;
    scani(q);
    for(int i=1;i<=q;i++)
    {
        int u,v;
        scanii(u,v);
        int l=upper_bound(v2.begin(),v2.end(),u)-v2.begin()-1;
        if(v1[l].ss>=v)printf("Yes\n");
        else printf("No\n");
    }
    return 0;

}
