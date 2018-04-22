
///*********points in rectangle**********
int t,n,m;
///4*50000 ta unique thakte pare
#define MAX 200005
vector<int> arr[MAX];
struct info
{
    vector<int> v;
}tree[MAX*4];
info call(info a,info b)
{
    info tmp;
    tmp.v.resize(a.v.size()+b.v.size());
    merge(ALL(a.v),ALL(b.v),tmp.v.begin());
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].v.resize(arr[b].size());
	    tree[node].v=arr[b];
	    ///sort korsi
	    sort(ALL(tree[node].v));
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right]);
}
int add(int a,int b)
{
    return a+b;
}
int query(int node,int b,int e,int i,int j,int y1,int y2)
{
	if (i > e || j < b)return 0;
	if (b >= i && e <= j)
    {
        ///y2 er modde koita ase ber korlam
        int val=upper_bound(ALL(tree[node].v),y2)-tree[node].v.begin();
        ///y1 er cheye chotogulao add hoye gesilo bad dilam
        val-=(lower_bound(ALL(tree[node].v),y1)-tree[node].v.begin());
        return val;

    }
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	int p1=query(Left,b,mid,i,j,y1,y2);
	int p2=query(Right,mid+1,e,i,j,y1,y2);
	return add(p1,p2);
}

vector<pii> in1,in2,in3;
vector<int> xx,yy;
map<int,int> mpx,mpy;
void clear()
{
    in1.clear();in2.clear();
    in3.clear();xx.clear();yy.clear();
    mpx.clear();mpy.clear();
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
    rep(cs,t)
    {
//        debug("");
        clear();
        getII(n,m);
        rep(i,n)
        {
            int x,y;
            getII(x,y);
            in1.push_back(MP(x,y));
            xx.push_back(x);
            yy.push_back(y);
        }
        rep(i,m)
        {
            int x,y;
            getII(x,y);
            in2.push_back(MP(x,y));
            xx.push_back(x);
            yy.push_back(y);
            getII(x,y);
            in3.push_back(MP(x,y));
            xx.push_back(x);
            yy.push_back(y);
        }
        ///sort korlam
        sort(ALL(xx));
        sort(ALL(yy));
        ///unique element nilam
        xx.erase(unique(ALL(xx)),xx.end());
        yy.erase(unique(ALL(yy)),yy.end());
        ///renumbering korlam
        repI(i,xx.size())mpx[xx[i]]=i+1;
        repI(i,yy.size())mpy[yy[i]]=i+1;
        ///clear
        int totx=xx.size();
        int toty=yy.size();
        rep(i,totx)arr[i].clear();
        ///proti ta x pos e kon y gula ase ta ber korlam
        repI(i,n)
        {
            int x=mpx[in1[i].ff],y=mpy[in1[i].ss];
            arr[x].PB(y);
        }
        ///initialize seg tree
        init(1,1,totx);
        printf("Case %d:\n",cs);
        repI(i,m)
        {
            int x1=mpx[in2[i].ff],y1=mpy[in2[i].ss];
            int x2=mpx[in3[i].ff],y2=mpy[in3[i].ss];
            int ans=query(1,1,totx,x1,x2,y1,y2);
            printf("%d\n",ans);
        }

    }
    return 0;
}
///*********************k query online
int t,n,m;
#define MAX 30005
int arr[MAX];

struct info
{
    vector<int> v;
}tree[MAX*3];;

void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].v.resize(1);
	    tree[node].v[0]=arr[b];
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node].v.resize(tree[Left].v.size()+tree[Right].v.size());
	merge(tree[Left].v.begin(),tree[Left].v.end(),tree[Right].v.begin(),tree[Right].v.end(),tree[node].v.begin());
}
int query(int node,int b,int e,int i,int j,int val)
{
	if (i > e || j < b)	return 0;
	if (b >= i && e <= j)
    {
        int sz=(e-b+1);
        int pos=upper_bound(ALL(tree[node].v),val)-tree[node].v.begin();
        return sz-pos;
    }
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	int p1=query(Left,b,mid,i,j,val);
	int p2=query(Right,mid+1,e,i,j,val);
	return p1+p2;
}
vector<int> res;

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        rep(i,n)getI(arr[i]);
        init(1,1,n);
//        repI(i,tree[1].v.size())debug(tree[1].v[i]);
        getI(m);
        int val=0;
        repI(i,m)
        {
            if(i)printf(" ");
            int x,y,z;
            getIII(x,y,z);
            x^=val;y^=val;z^=val;
            val=query(1,1,n,x,y,z);
            printf("%d",val);
        }
        puts("");

    }


    return 0;
}


