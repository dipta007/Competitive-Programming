#include<iostream>
#include<fstream>
using namespace std;

#define MOD 1000000007
#define ll long long int

ll a[101][101], p[101][101], m;

void mul(ll m1[101][101], ll m2[101][101]){
    ll m3[101][101], m4[101][101];
    ll i,j,k;
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            m3[i][j] = m1[i][j];
            m4[i][j] = m2[i][j];
            p[i][j] = 0;
        }
    }
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            for(k=0; k<m; k++){
                p[i][j] += (m3[i][k] * m4[k][j]);
                p[i][j] %= MOD;
            }
        }
    }
}

void power(ll n){
    if(n==0 or n==1){
        return;
    }
    power(n/2);
    mul(p, p);
    if(n%2){
        mul(p, a);
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    ll t,n,i,j;
    cin>>t;
    while(t--){
        cin>>m>>n;
        ll s[m+1];
        for(i=0; i<m; i++){
            cin>>s[i];
            s[i] += MOD;
        }

        for(i=0; i<m; i++){
            cin>>a[0][m-1-i];
        }

        for(i=1; i<m; i++){
            for(j=0; j<m; j++){
                if(i==(j+1)){
                    a[i][j] = 1;
                }
                else{
                    a[i][j] = 0;
                }
            }
        }
        for(i=0; i<m; i++){
            for(j=0; j<m; j++){
                p[i][j] = a[i][j];
            }
        }
        if(n>=m){
            power(n-m+1);
            ll ans = 0;
            for(i=0; i<m; i++){
                ans += (p[0][i]*s[m-1-i]);
                ans %= MOD;
            }
            cout<<ans<<endl;
        }
        else{
            cout<<s[n]%MOD<<endl;
        }
    }
    return 0;
}

