struct ConvexHull {
    vector<point> points;

    void clear() {
        points.clear();
    }

    void addPoint(ll x, ll y) {
        points.push_back( point(x, y) );
    }

    void addPoint( point  p) {
        points.push_back(p);
    }

    // 2D cross product.
    // Return a positive value, if OAB makes a counter-clockwise turn,
    // negative for clockwise turn, and zero if the points are collinear.
    ll cross(const point &O, const point &A, const point &B) {
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    }

    // Returns a list of points on the convex hull in counter-clockwise order.
    // Note: the last PointLL in the returned list is the same as the first one.
    vector< point > getConvexHull(vector< point >& P) {
        int n = P.size(), k = 0;
        vector< point > H(2*n);
        // Sort points lexicographically
        sort(P.begin(), P.end());

        // Build lower hull
        for (int i = 0; i < n; i++) {
            while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--; // strictly counter-clockwise then < 0 (skipping the colinear points)  else use <=0
            H[k++] = P[i];
        }

        // Build upper hull
        for (int i = n-2, t = k+1; i >= 0; i--) {
            while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--; // strictly counter-clockwise then < 0 (skipping the colinear points)  else use <=0
            H[k++] = P[i];
        }

        H.resize(k);
        H.pop_back(); // first point comes again . so pop
        return H;
    }

    vector< point > getConvexHull() {
        return getConvexHull(points);
    }

};
