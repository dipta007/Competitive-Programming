class Delaunay{
    class Point implements Comparable<Point> {
        long x, y;

        public int compareTo(Point o) {
            if (x != o.x)
                return Long.signum(x - o.x);
            return Long.signum(y - o.y);
        }

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        Point3D get() {
            return new Point3D(x, y, x * x + y * y);
        }

        Point sub(Point p) {
            return new Point(x - p.x, y - p.y);
        }

        long det(Point p) {
            return x * p.y - y * p.x;
        }

        long abs2() {
            return x * x + y * y;
        }

        long distTo2(Point p) {
            return sub(p).abs2();
        }
    }

    long cross(Point p1, Point p2, Point p3) {
        return p2.sub(p1).det(p3.sub(p1));
    }

    int crossOp(Point p1, Point p2, Point p3) {
        return Long.signum(cross(p1, p2, p3));
    }

    boolean crsSS(Point p1, Point p2, Point q1, Point q2) {
        return crossOp(p1, p2, q1) * crossOp(p1, p2, q2) < 0 &&
                crossOp(q1, q2, p1) * crossOp(q1, q2, p2) < 0;
    }

    class Point3D {
        long x, y, z;

        Point3D(long x, long y, long z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        long dot(Point3D p) {
            return x * p.x + y * p.y + z * p.z;
        }

        Point3D det(Point3D p) {
            return new Point3D(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
        }

        Point3D sub(Point3D p) {
            return new Point3D(x - p.x, y - p.y, z - p.z);
        }
    }

    int inCircle(Point a, Point b, Point c, Point d) {
        b = b.sub(a);
        c = c.sub(a);
        d = d.sub(a);
        if (b.det(c) < 0) {
            Point t = b;
            b = c;
            c = t;
        }
        Point3D pb = b.get(), pc = c.get(), pd = d.get();
        Point3D o = pb.det(pc);
        return Long.signum(pd.dot(o));
    }

    class PointId extends Point {
        int id;
        List<PointId> edges = new LinkedList<PointId>();

        PointId(long x, long y, int id) {
            super(x, y);
            this.id = id;
        }

        void addEdge(PointId t) {
            edges.add(t);
            t.edges.add(this);
        }
    }

    int n;
    PointId[] ps;

    void construct(int l, int r) {//[l,r)
        if (r - l <= 3) {
            for (int i = l; i < r; i++) {
                for (int j = l + 1; j < r; j++) {
                    ps[i].addEdge(ps[j]);
                }
            }
            return;
        }
        int m = (l + r) / 2;
        construct(l, m);
        construct(m, r);

        //find the common tangent
        PointId pl = ps[l], pr = ps[r - 1];
        for (; ; ) {
            PointId next = null;
            for (PointId p : pl.edges) {
                int op = crossOp(pr, pl, p);
                if (op > 0 || (op == 0 && p.distTo2(pr) < pl.distTo2(pr))) {
                    next = p;
                    break;
                }
            }
            if (next != null)
                pl = next;
            else {
                next = null;
                for (PointId p : pr.edges) {
                    int op = crossOp(pr, pl, p);
                    if (op > 0 || (op == 0 && p.distTo2(pl) < pr.distTo2(pl))) {
                        next = p;
                        break;
                    }
                }
                if (next != null)
                    pr = next;
                else
                    break;
            }
        }

        //merge
        pl.addEdge(pr);
        pr.addEdge(pl);
        for (; ; ) {
            PointId next = null;
            boolean which = false;
            for (PointId p : pl.edges) {
                if (crossOp(pr, pl, p) < 0 && (next == null || inCircle(next, pl, pr, p) == -1))
                    next = p;
            }
            for (PointId p : pr.edges) {
                if (crossOp(pl, pr, p) > 0 && (next == null || inCircle(next, pl, pr, p) == -1)) {
                    next = p;
                    which = true;
                }
            }
            if (next == null)
                break;
            if (!which) {//pl
                List<PointId> nEdges = new ArrayList<PointId>();
                for (PointId p : pl.edges) {
                    if (!crsSS(next, pr, pl, p))
                        nEdges.add(p);
                }
                pl.edges = nEdges;
                pr.addEdge(next);
                pl = next;
            } else {//pr
                List<PointId> nEdges = new ArrayList<PointId>();
                for (PointId p : pr.edges) {
                    if (!crsSS(next, pl, pr, p))
                        nEdges.add(p);
                }
                pr.edges = nEdges;
                pl.addEdge(next);
                pr = next;
            }
        }
    }
}
