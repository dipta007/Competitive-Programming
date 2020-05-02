#include <bits/stdc++.h>
#define maxn 1000010
#define inf 0x3f3f3f3f
#define SIGMA 26
using namespace std;
typedef long long ll;
int n;
/***Trie***/
int root,tot;
int Next[maxn][SIGMA],End[maxn],cnt[maxn];
string ss[100005];
int newnode(){
    for(int i=0;i<SIGMA;i++)
        Next[tot][i]=0;
    End[tot++]=0;
    return tot-1;
}
void init(){
    memset(Next,0,sizeof(Next));
    memset(End,0,sizeof(End));
    tot=0;
    root=newnode();
}
inline int get_idx(char c){
    return c-'a';
}
inline void Insert(string s){
    int len=s.length();int buf[15];memset(buf,0,sizeof(buf));
    for(int i=0;i<len;i++)
        buf[i]=get_idx(s[i]);
    int now=root;
    for(int i=len-1;i>=0;i--){
        if(!Next[now][buf[i]])
            Next[now][buf[i]]=newnode();
        now=Next[now][buf[i]];
        cnt[now]++;
    }
    End[now]++;
}
inline int query(string s){
    int len=s.length();int buf[15],res=0;memset(buf,0,sizeof(buf));
    for(int i=0;i<len;i++)
        buf[i]=get_idx(s[i]);
    int now=root;
    for(int i=len-1;i>=0;i--){
        for(int j=buf[i]+1;j<26;j++) res+=cnt[Next[now][j]];
        if(!Next[now][buf[i]]) return res;
        else now=Next[now][buf[i]];
    }
    for(int i=0;i<26;i++) res+=cnt[Next[now][i]];
    return res;
}
int main()
{
    init();
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>ss[i];
    sort(ss+1,ss+1+n);
    ll ans=0;Insert(ss[1]);
    for(int i=2;i<=n;i++){
        ans+=query(ss[i]);
        Insert(ss[i]);
    }
    printf("%lld\n",ans);
}
