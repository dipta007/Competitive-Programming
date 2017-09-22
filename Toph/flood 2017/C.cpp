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

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

struct data
{
    string fname,lname,location;
    int age,mem,in;
//    data(string a, string b, string c, int x, int y)
//    {
//        fname = a;
//        lname = b;
//        location = c;
//        age = x;
//        mem = y;
//    }
};

bool comp1(const data &a, const data &b)
{
    if(a.fname < b.fname) return true;
//    if(a.fname == b.fname) return a.in < b.in;
    return false;
}

bool comp2(const data &a, const data &b)
{
    if(a.lname < b.lname) return true;
//    if(a.lname == b.lname) return a.in < b.in;
    return false;
}

bool comp3(const data &a, const data &b)
{
    if(a.location < b.location) return true;
//    if(a.location == b.location) return a.in < b.in;
    return false;
}

bool comp4(const data &a, const data &b)
{
    if(a.age < b.age) return true;
//    if(a.age == b.age) return a.in < b.in;
    return false;
}

bool comp5(const data &a, const data &b)
{
    if(a.mem < b.mem) return true;
//    if(a.mem == b.mem) return a.in < b.in;
    return false;
}
bool comp6(const data &a, const data &b)
{
    if(a.fname > b.fname) return true;
    //if(a.fname == b.fname) return a.in < b.in;
    return false;
}

bool comp7(const data &a, const data &b)
{
    if(a.lname > b.lname) return true;
    //if(a.lname == b.lname) return a.in < b.in;
    return false;
}

bool comp8(const data &a, const data &b)
{
    if(a.location > b.location) return true;
    //if(a.location == b.location) return a.in < b.in;
    return false;
}

bool comp9(const data &a, const data &b)
{
    if(a.age > b.age) return true;
//    if(a.age == b.age) return a.in < b.in;
    return false;
}

bool comp10(const data &a, const data &b)
{
    if(a.mem > b.mem) return true;
//    if(a.mem == b.mem) return a.in < b.in;
    return false;
}

vector < data > vd;

string process(string st)
{
    st = " " + st;
    while(st.size() < 20) st = st + " ";
    return st;
}
string process(int a)
{
    string st = NumberToString(a);
    st = " " + st;
    while(st.size() < 20) st = st + " ";
    return st;
}

string cat[5] = {
                " first_name         ",
                " last_name          ",
                " location           ",
                " age                ",
                " family_members     "};

void gen()
{
    FOR(ik,1,5)
    {
        cout << "+";
        FOR(i,1,20) cout << "-";
    }
    cout << "+" << endl;

    FOR(i,1,5)
    {
        cout << "|";
        cout << cat[i-1];
    }
    cout << "|" << endl;

    FOR(ik,1,5)
    {
        cout << "+";
        FOR(i,1,20) cout << "-";
    }
    cout << "+" << endl;

    FOR(i,0,(int)vd.size()-1)
    {
        data d = vd[i];
        cout << "|" << process(d.fname) << "|" << process(d.lname) << "|" << process(d.location) << "|" << process(d.age) << "|" << process(d.mem);
        cout << "|" << endl;
    }

    FOR(ik,1,5)
    {
        cout << "+";
        FOR(i,1,20) cout << "-";
    }
    cout << "+" << endl;
}


string cantwrite = "I can't write queries. So Shakib is a bad boy.";

int main()
{
#ifdef dipta007
    READ("in.txt");
        //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    int x;
//    cin >> x;
//    string st;
//    getline(cin,st);
//    debug(x, "*",st);

    //gen();
    int n;
    cin >> n;
//    while( cin >> n )
    {
        vd.clear();
        FOR(i,1,n)
        {
            data d;
            cin >> d.fname >> d.lname >> d.location >> d.age >> d.mem;
            d.in = i;
            //debug(i, d.fname)
            vd.PB(d);
        }
        cin.get();
//        getchar();
//        debug("**")
        int db=0,tb=0;
        string st;
        while(1)
        {
            getline(cin, st);
//            debug("*", st)
            if(st == "Lol:Exit") break;
            else if(st == "mysql -u root -p People")
            {
                if(db)
                {
                    cout << cantwrite << endl;
                    continue;
                }
                db = 1;
            }
            else if(st == "use people")
            {
                if(db==0 || tb==1) cout << cantwrite << endl;
                else tb = 1;
            }
            else if(st == "select * from people")
            {
                if(db==0 || tb==0) cout << cantwrite << endl;
                else gen();
            }
            else if(st.size() >= 9 && st.substr(0,9) == "order by ")
            {
                if(db==0 || tb==0)
                {
                    cout << cantwrite << endl;
                    continue;
                }
                int flg = 0;
                string now = "";
                FOR(i,9,(int)st.size()-1)
                {
                    now += st[i];
                    if(now == "first_name ")
                    {
                        flg = 1;
                        break;
                    }
                    else if(now == "last_name ")
                    {
                        flg = 2;
                        break;
                    }
                    else if(now == "location ")
                    {
                        flg = 3;
                        break;
                    }
                    else if(now == "age ")
                    {
                        flg = 4;
                        break;
                    }
                    else if(now == "family_members ")
                    {
                        flg = 5;
                        break;
                    }
                }

                string tmp = "";
                int cnt = 0;
                FOR(i,0,(int)st.size()-1)
                {
                    if(st[i]==' ') cnt++;
                    else if(cnt == 3)
                    {
                        tmp += st[i];
                    }
                }
//                debug(tmp,st)
                if(tmp == "asc" && cnt == 3)
                {
                    if(flg==0) cout << cantwrite << endl;
                    else if(flg == 1) sort(ALL(vd),comp1);
                    else if(flg == 2) sort(ALL(vd),comp2);
                    else if(flg == 3) sort(ALL(vd),comp3);
                    else if(flg == 4) sort(ALL(vd),comp4);
                    else if(flg == 5) sort(ALL(vd),comp5);
                }
                else if(tmp == "desc" && cnt == 3)
                {
                    if(flg==0) cout << cantwrite << endl;
                    else if(flg == 1) sort(ALL(vd),comp6);
                    else if(flg == 2) sort(ALL(vd),comp7);
                    else if(flg == 3) sort(ALL(vd),comp8);
                    else if(flg == 4) sort(ALL(vd),comp9);
                    else if(flg == 5) sort(ALL(vd),comp10);
                }
                else cout << cantwrite << endl;
            }
            else cout << cantwrite << endl;
        }
    }

    return 0;
}



