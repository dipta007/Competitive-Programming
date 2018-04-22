#include<bits/stdc++.h>

using namespace std;

#define fRead(x)  freopen(x,"r",stdin)
#define fWrite(x) freopen (x,"w",stdout)

#define LL long long
#define ULL unsigned long long
#define ff first
#define ss second
#define pb push_back
#define INF 2e16
#define PI acos(-1.0)
#define mk make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>


#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,b) for(int i=0;i<b;i++)
#define MEM(a,x) memset(a,x,sizeof(a))
#define ABS(x) ((x)<0?-(x):(x))

#define scanI(a) scanf("%d",&a)
#define scanI2(a,b) scanI(a) , scanI(b)
#define scanI3(a,b,c) scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a) scanf("%I64d",&a)
#define scanL2(a,b) scanL(a) , scanL(b)
#define scanL3(a,b,c) scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

#define SORT(v) sort(v.begin(),v.end())
#define REV(v) reverse(v.begin(),v.end())


#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);

char str[260];
short int len;
short int dp[257][34][34][34][34];
short int vis[257][34][34][34][34],id;
short int cum[257],F[257];

short int MAX(short int A,short int B)
{
   if(A > B)return A;
   else return B;
}
short int MIN(short int A,short int B)
{
   if(A < B)return A;
   else return B;
}
short int n,k;

short int call(short int pos,short int c,short int h,short int e,short int f)
{
   if(f == k)return cum[pos];
   if(F[pos] == 0)return -1e3;
   if(f + e < k and f + e + e > k)return -1e3;
   if(pos == len)return -1e3;

   if(vis[pos][c][h][e][f] == id)return dp[pos][c][h][e][f];
   vis[pos][c][h][e][f] = id;

   short int ret = -1e3;
   ret = MAX(ret, call(pos + 1,c,h,e,f));
   short int ex = 1;
   if(str[pos] == 'c'){
      short int cc = MIN(33,c + 1);
      ret = MAX(ret,ex + call(pos + 1,cc,h,e,f));

   }else if(str[pos] == 'h'){
      short int hh = MIN(33,h + c);
      ret = MAX(ret,ex + call(pos + 1,c,hh,e,f));

   }else if(str[pos] == 'e'){
      short int ee = MIN(33,e + h);
      if(f + ee <=k)ret = MAX(ret,ex + call(pos + 1,c,h,ee,f));

   }else{
      short int ff = f + e;
      if(ff <= k)ret = MAX(ret,ex + call(pos + 1,c,h,e,ff));
   }

   return dp[pos][c][h][e][f] = ret;
}

int main()
{
   FastRead
   short int t;
   cin >> t;
   while(t--)
   {
      id++;
      cin >> n >> k;
      cin >> str;
      len = n;

      MEM(cum,0);
      MEM(F,0);

      for(short int i = len - 1;i >= 0;i--){
         if(str[i] == 'f')cum[i] = cum[i + 1];
         else cum[i] = cum[i + 1] + 1;

         if(str[i] == 'f')F[i] = F[i+1] + 1;
         else F[i] = F[i+1];
      }

      short int ans = call(0,0,0,0,0);
      if(ans < 0)cout << -1 << "\n";
      else cout << len -ans << "\n";
   }


}
/*
1
198 29
ffhffhffcfechchccccfhhhfhhhhhhehhhehhhhheeeeefeeeeeeheeheeeeffcfffffffffffhffffchffeffcefefhhfcehfeffhffhffcfechchccccfhhhfhhhhhhehhhehhhhheeeeefeeeeeeheeheeeeffcfffffffffffhffffchffeffcefefhhfcehfe
*/
