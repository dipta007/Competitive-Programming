/// Number of lattice points in polygon
// Picks Theorem :: A = I + B/2 - 1
// A = area of polygon , I =  the number of points (int) lying strictly inside the polygon
//  B = number of points on the border( int co ordinate )
ll picksTheorem(polygon P) {
    double A = P.getArea();
    ll B = 0 ;
    int n = P.n;
    for( int i = 0, j = n - 1; i < n; j = i++ )
    {
        ll ret = lattice_pts(P.p[i],P.p[j]);
        B += ret;
    }
    B -= n;
    return (2.0 * A - B + 2)/2;
}
