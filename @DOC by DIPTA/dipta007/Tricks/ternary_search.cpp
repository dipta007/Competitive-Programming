/// Ternary search on DOUBLE
double ts()
{
    double low = 0;
    double high = 1;
    int c = 100; //for higher precision have to increase
    while (c--)
    {
        double m1 = ( low * 2.0 + high ) / 3.0;
        double m2 = ( low + high * 2.0) / 3.0;
        double y1 = fun(m1);
        double y2 = fun(m2);

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

/// Ternary Search on INTS
int lo = -1, hi = n;
while (hi - lo > 1)
{
    int mid = (hi + lo)>>1;
    if (f(mid) > f(mid + 1))
        hi = mid;
    else
        lo = mid;
}
//lo + 1 is the answer

/** Ternary Search on ARRAY INT **/
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


