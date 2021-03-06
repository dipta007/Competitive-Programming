#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    ll	             long long

#define mx 50004
int arr[mx];

struct data {
    ll pre, suff, sum, maxy;
};

data tree[mx*3];

data call(data &a, data &b)
{
    data tmp;
    tmp.pre = max(a.pre, a.sum+b.pre);
    tmp.suff = max(b.suff, a.suff+b.sum);
    tmp.sum = a.sum + b.sum;
    tmp.maxy = max(a.pre, b.suff);
    tmp.maxy = max(tmp.maxy, tmp.sum);
    tmp.maxy = max(tmp.maxy, a.suff);
    tmp.maxy = max(tmp.maxy, b.pre);
    tmp.maxy = max(tmp.maxy, a.maxy);
    tmp.maxy = max(tmp.maxy, b.maxy);
    tmp.maxy = max(tmp.maxy, a.suff + b.pre);
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
        data tmp;
        tmp.pre = tmp.suff = tmp.sum = tmp.maxy = arr[b];
        // debug(b, arr[b]);
		tree[node]=tmp;
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right]);
}
data query(int node,int b,int e,int i,int j)
{
    if(i > j)
    {
        data tmp;
        printf("SAD\n");
        tmp.pre = tmp.suff = tmp.maxy = tmp.sum = 0LL;
        // debug(b,e)
        return tmp; //বাইরে চলে গিয়েছে
    }
	if (i > e || j < b)
    {
        data tmp;
        tmp.pre = tmp.suff = tmp.maxy = tmp.sum = -750350020;
        // debug(b,e)
        return tmp; //বাইরে চলে গিয়েছে
    }
	if (b >= i && e <= j) return tree[node]; //রিলেভেন্ট সেগমেন্ট
	int Left=node*2;  //আরো ভাঙতে হবে
	int Right=node*2+1;
	int mid=(b+e)/2;
	data p1=query(Left,b,mid,i,j);
	data p2=query(Right,mid+1,e,i,j);
	return call(p1,p2); //বাম এবং ডান পাশের যোগফল
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

   int t;
   getI(t);
   FOR(ci,1,t)
   {
       int n;
       getI(n);
       FOR(i,1,n) getI(arr[i]);
       init(1,1,n);

       int q;
       getI(q);
       FOR(i,1,q)
       {
           int x1,y1,x2,y2;
           getII(x1,y1);
           getII(x2,y2);
           ll ans;
           if(y1 < x2)
           {
               printf("%lld\n", query(1, 1, n, y1+1, x2-1).sum, query(1, 1, n, x2, y2).pre);
               ans = query(1,1,n,x1,y1).suff + query(1, 1, n, y1+1, x2-1).sum + query(1, 1, n, x2, y2).pre;
           }
           else
           {
               ans = query(1,1,n,x1,y1-1).suff + query(1,1,n,y1,y2).pre;
               ans = max(ans, query(1, 1, n, x2, y1-1).suff + query(1,1,n,y1,y2).pre);
               ans = max(ans, query(1, 1, n, x2, y1).maxy );
           }
           printf("%lld\n", ans);
       }

   }

    return 0;
}
