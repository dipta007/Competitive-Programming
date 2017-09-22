double ts()
{
    double low = 0;
    double high = 1;
    int c = 100; //for higher precision have to increase
    double k, l, f, g;
    while (c--)
    {
        m1 = ( low * 2.0 + high ) / 3.0;
        m2 = ( low + high * 2.0) / 3.0;
        y1 = fun(m1);
        y2 = fun(m2);

        /// boro - choto - boro
        if (y1 > y2)
        {
            low = m1;
        }
        else
        {
            high = m2;
        }

        /// choto - boro - choto
        if(y1 > y2)
        {
            high = m2;
        }
        else
        {
            low = m1;
        }
    }
    return (low + high) / 2.0;
}
/// ***************************************** ///
int ternary_search(int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(l,mid1-1,x);
        else if(x>ar[mid2])
            return ternary_search(mid2+1,r,x);
        else
            return ternary_search(mid1+1,mid2-1,x);

    }
    return -1;
}
/// ***************************************** ///
double func(double x)
{
    return -1*1*x*x + 2*x +3;
}


double ts(double start, double end)
{
    double l = start, r = end;

    for(int i=0; i<200; i++) {
      double l1 = (l*2+r)/3;
      double l2 = (l+2*r)/3;
      //cout<<l1<<" "<<l2<<endl;
      if(func(l1) > func(l2)) r = l2; else l = l1;
      }

     double x = l;
    return func(x);
}
