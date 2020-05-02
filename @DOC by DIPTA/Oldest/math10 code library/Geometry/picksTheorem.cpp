void picksTheorem(polygon P) {

    int64 A = P.poly_area();
    int64 B = 0 ;
    int n = P.P.size();
    for( int i = 0, j = n - 1; i < n; j = i++ ) {

        int64 ret = lattice_pts(P.P[i],P.P[j]);
        B += ret;
    }
    // Picks Theorem :: A = I + B/2 - 1
    // A = area of polygoan , I =  the number of points (int) lying strictly inside the polygon
    //  B = number of points on the border( int co ordinate )
}
