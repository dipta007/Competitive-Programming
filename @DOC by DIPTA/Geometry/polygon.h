
struct polygon
{
#define maxp 10000
    int n;
    point p[maxp];
    line l[maxp];

    void input()
    {
        cin >> n;
        if(n==0)exit(0);

        for (int i = 0; i < n ; i++)
        {
            p[i].input();
        }
    }
    void add(point q)
    {
        p[n++] = q;
    }

};
void getline(polygon P)
{
    for (int i = 0; i < P.n; i++)
    {
        P.l[i] = line( P.p[i] , P.p[(i+1)%P.n] ); //line header
    }
}
/**  বিন্দুটা পলিগন এর কোথায় আছে তা return করে
        3 পলিগনের একটা বিন্দু
        2 পলিগন এর লাইন এর উপর অবস্থিত
        1 পলিগন এর ভিতরে অবস্থিত
        0 পলিগন এর বাইরে অবস্থিত
    **/
int relationpoint(polygon P,point q)
{
    int i,j;
    for (i=0; i<P.n; i++)
    {
        if (P.p[i]==q)return 3;
    }
    getline(P); // own
    for (i=0; i<P.n; i++)
    {
        if (pointonseg(P.l[i],q))return 2; // line header
    }
    int cnt=0;
    for (i=0; i<P.n; i++)
    {
        j=(i+1)%P.n;
        int k=EQ(cross((q - P.p[j]),P.p[i] - P.p[j])); //point header
        int u=EQ(P.p[i].y-q.y);
        int v=EQ(P.p[j].y-q.y);
        if (k>0&&u<0&&v>=0)cnt++;
        if (k<0&&v<0&&u>=0)cnt--;
    }
    return cnt!=0;
}

bool isconvex(polygon P) ///পলিগনটা convex না cancave আকারে আছে তা return করে
{
    bool s[3];
    memset(s,0,sizeof(s));
    int i,j,k;
    for (i = 0; i < P.n ; i++)
    {
        j = (i+1)%P.n;
        k = (j+1)%P.n;
        s[ EQ (cross( ( P.p[j] - P.p[i] ), P.p[k] - P.p[i] ) ) + 1 ] = 1;  //point header
        if ( s[0] && s[2] )return 0;
    }
    return 1;
}

///পলিগন এর পরিধি return করে
double getcircumference(polygon P)
{
    double sum=0;
    int i;
    for (i=0; i<P.n; i++)
    {
        sum+=dis(P.p[i],P.p[(i+1)%P.n]); //point header
    }
    return sum;
}

///পলিগন এর ক্ষেত্রফল return করে
double getarea(polygon P)
{
    double sum=0;
    int i;
    for (i=0; i<P.n; i++)
    {
        sum+=cross(P.p[i],P.p[(i+1)%P.n]); //point header
    }
    return fabs(sum)/2;
}
///পলিগন এর বিন্দুগুলা clock wise order(1) না anti clock wise order(0) এ আছে তা return করে
bool getdir(polygon P)
{
    double sum=0;
    int i;
    for (i=0; i<P.n; i++)
    {
        sum+=cross(P.p[i],P.p[(i+1)%P.n]); //point header
    }
    if (EQ(sum)>0)return 1;
    return 0;
}
///পলিগন circle এর intersection ক্ষেত্রফল return করে
double areacircle(polygon P,circle c)
{
    int i,j,k,l,m;
    double ans=0;
    for (i=0; i<P.n; i++)
    {
        int j=(i+1)%P.n;
        if (EQ(cross((P.p[j] - c.p),P.p[i] - c.p ))>=0) //point header
        {
            ans+=areatriangle(c,P.p[i],P.p[j]); // circle header
        }
        else
        {
            ans-=areatriangle(c,P.p[i],P.p[j]); //circle header
        }
    }
    return fabs(ans);
}
void find(int st,point tri[],circle &c) // mincircle এর জন্য দরকার ;;it use circle header
{
    if (!st)
    {
        c=circle(point(0,0),-2);
    }
    if (st==1)
    {
        c=circle(tri[0],0);
    }
    if (st==2)
    {
        c=circle((tri[0] - tri[1])/(2),dis(tri[0],tri[1])/2.0);  //point header
    }
    if (st==3)
    {
        c = circle(tri[0],tri[1],tri[2]);
    }
}
void solve(polygon P,int cur,int st,point tri[],circle &c) // mincircle এর জন্য দরকার
{
    find(st,tri,c); // own
    if (st==3)return;
    int i;
    for (i=0; i<cur; i++)
    {
        if (EQ(dis(P.p[i],c.p)-c.r)>0) //point header
        {
            tri[st]=P.p[i];
            solve(P,i,st+1,tri,c); // own
        }
    }
}
circle mincircle(polygon P) //ক্ষুদ্রতর circle যেটা পলিগনটাকে কভার কইরা রাখে
{
    random_shuffle(P.p,P.p+P.n);
    point tri[4];
    circle c;
    solve(P,P.n,0,tri,c); // own
    return c;
}
polygon cutPolygon(polygon po,point a,point s)
{
    point x,c;
    polygon ans;
    int sum=0;
    for(int q=0; q<po.n; q++)
    {
        x=po.p[q];
        c=po.p[(q+1)%po.n];
        if(OnLeft(line(a,s-a),x)||OnSegment(x,a,s))
        {
            ans.p[sum]=x;
            sum++;
        }
        if(SegmentProperIntersection(x,c,a,s))
        {
            ComputeLineIntersection(x,c-x,a,s-a,ans.p[sum]);
            sum++;
        }
    }
    ans.n=sum;
    return ans;
}
point centre_poly(polygon P)   // returns centre of polygoan /convex
{

    double area = getarea(P);
    double factor = 1.0 / (6 * area);
    double cx = 0, cy = 0;
    int i,sz = P.n;
    for( i = 0 ; i < sz ; i++)
    {
        point cur = P.p[i] , next = P.p[(i + 1) % sz];
        cx += (cur.x + next.x) * (cur.x * next.y - cur.y * next.x);
        cy += (cur.y + next.y) * (cur.x * next.y - cur.y * next.x);
    }
    cx *= factor;
    cy *= factor;
    return point(cx, cy);
}
