/// Needed for min circle covering polygon
void find(int st,point tri[],circle &c)
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
        c=circle((tri[0] - tri[1])/(2.0),tri[0].distance(tri[1])/2.0);
    }
    if (st==3)
    {
        c = circle(tri[0],tri[1],tri[2]);
    }
}
/// Needed for min circle covering polygon
void solve(polygon P,int cur,int st,point tri[],circle &c)
{
    find(st,tri,c); // own
    if (st==3)return;
    int i;
    for (i=0; i<cur; i++)
    {
        if(EQ(P.p[i].distance(c.p)-c.r) > 0)
        {
            tri[st]=P.p[i];
            solve(P,i,st+1,tri,c); // own
        }
    }
}
/// Smallest circle that can cover the polygon
circle mincircle(polygon P)
{
    random_shuffle(P.p,P.p+P.n);
    point tri[4];
    circle c;
    solve(P,P.n,0,tri,c); // own
    return c;
}

