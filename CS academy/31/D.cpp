#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef __JETBRAINS_IDE__
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
	template<typename T> debugger& operator , (const T& v){
		cerr<<v<<" ";
		return *this;
	}
}dbg;

map <int , int> mp[10004];
//int mark[10004];

int question(int frst,int scnd)
{
	if(mp[frst].find(scnd)!=mp[frst].end())
		return mp[frst][scnd];
	
	cout << "Q " << frst << " " << scnd << endl;
	cout.flush();
	int m;
	cin >> m;
	return m;
}
void answer(int num)
{
	cout << "A " << num << endl;
	cout.flush();
}


int main() {
#ifdef dipta007
	//READ("in.txt");
//        WRITE("in.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);
	
	srand(time(NULL));
	int n;
	while(cin >> n)
	{
		debug(n)
		//FOR(i,0,n) mp[i].clear();
		
		int q = min(2*n, n+15);
		
		FOR(i,1,n-1)
		{
			int kk = question(i,i+1);
			q--;
			mp[i][i+1] = kk;
			mp[i+1][i] = kk;
		}
		
		int one = 1;
		FOR(i,1,n-1)
		{
			if(mp[i][i+1]==i+1)
			{
				one = i+1;
			}
			else
			{
				one = i;
				for(;i<=n-1; i++)
				{
					if(mp[i][i+1]==i+1)
					{
						int kk = question(one, i+1);
						mp[one][i+1] = kk;
						mp[i+1][one] = kk;
						one = kk;
					}
				}
			}
		}
		
		int two = 1;
		int suru = 1;
		if(one==1)
		{
			two++;
			suru = 2;
		}
		FOR(i,suru,n-2)
		{
			if(i+1==one)
			{
				int kk = question(i, i+2);
				q--;
				mp[i][i+2] = kk;
				mp[i+2][i] = kk;
				break;
			}
		}
		
		FOR(i,suru,n-1)
		{
			if(i==one) continue;
			
			int ik = i+1;
			if(ik==one) ik++;
			
			if(ik==n+1) break;
			
			if(mp[i][ik]==ik)
			{
				two = ik;
			}
			else
			{
				two = i;
				for(;i<=n-1; i++)
				{
					int ik = i+1;
					if(ik==one) ik++;
					if(ik==n+1) break;
					if(mp[i][ik]==ik)
					{
						int kk = question(two, ik);
						mp[two][ik]=kk;
						mp[ik][two] = kk;
						two = kk;
					}
				}
			}
		}
		
		answer(two);
		
		
		
		
		
		
		
		
		
//		FOR(i,1,q)
//		{
//			int in1 = rand()%n + 1;
//			int in2 = rand()%n + 1;
//			while(in1==in2 || mp[in1][in2]!=0 || mp[in2][in1]!=0)
//			{
//				in1 = rand()%n + 1;
//				in2 = rand()%n + 1;
//			}
//
//			cout << "Q " << in1 << " " << in2 << endl;
//			cout.flush();
//			int response;
//			cin >> response;
//
//			mp[in1][in2] = response;
//			mp[in2][in1] = response;
//
//			mark[response] ++;
//		}
		
//		int one = rand()%n+1;
//		int flg= 1;
//		FOR(i,1,n)
//		{
//			if(one == i)
//			{
//				flg=0;
//				continue;
//			}
//			cout << "Q " << one << " " << i << endl;
//			cout.flush();
//
//
//			int response;
//			cin >> response;
//
//			one = response;
//		}
//
//		if(n==2)
//		{
//			if(one==1) cout << "A 2" << endl;
//			else cout << "A 1" << endl;
//			cout.flush();
//			break;
//		}
//
//		q -= (n-1);
//		q -= flg;
//
//		int two = rand()%n+1;
//		while(two==one) two++;
//		while(two>n || two==one) two--;
//		FOR(i,1,q)
//		{
//			int now = rand()%n+1;
//			while(now == two || now == one) now++;
//			while(now == two || now == one || now > n) now--;
//
//			cout << "Q " << two << " " << now << endl;
//			cout.flush();
//
//
//			int response;
//			cin >> response;
//
//			two = response;
//		}
//
		
//		int mini = INF;
//		FOR(i,1,n)
//		{
//			mini = min(mini, mark[i]);
//		}
//
//		int mini1 = INF;
//		int in;
//		FOR(i,1,n)
//		{
//			if(mark[i]!=mini && mark[i] < mini1)
//			{
//				mini1 = mark[i];
//				in = i;
//			}
////		}
//		cout << "A " << two << endl;
//		cout.flush();
//		break;
	}
	
	
	return 0;
}


