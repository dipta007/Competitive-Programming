//
// Rectilinear Minimum Spanning Tree
//
// Description:
//   For a given set of n points in 2D plane, it finds a minimum
//   spaning tree whose edge weight is given by the Manhattan distance:
//     d(i,j) = |x(i) - x(j)| + |y(i) - y(j)|.
//
// Algorithm:
//   [Zhou+'02]'s plane sweep method.
//
//       2|1
//      3\|/0
//      --p--
//      4/|\7
//       5 6
//
//  Consider octant 0. For each point p, the algorithm finds the
//  nearest neighbors in this octant. This is simply performed by
//  the plane sweep technique: We process points from south-west
//  to north-east. The sweep line keeps the points whose neighbor
//  is not determined. This can be implemented by the y-sorted list.
//  By performing plane sweeping 4 times, we obtain the nearest
//  neighbors of the points.
//
// Complexity:
//   O(n log n).
//
// References:
//   H. Zhou, N. Shenoy, and W. Nichollos (2002):
//   Efficient minimum spanning tree without Delaunay triangulation.
//   Information Processing Letters, vol.81, pp.271--276.
//
// Verify:
//   Codechef DRAGONST
//

#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())


typedef complex<double> point;
namespace std {
bool operator < (point p, point q) {
  if (real(p) != real(q)) return real(p) < real(q);
  return imag(p) < imag(q);
}
};
istream &operator>>(istream &is, point &p) {
  double x, y;
  is >> x >> y;
  p = point(x, y);
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &x) {
  for (auto &a: x) os << a << " ";
  return os;
}

double dot(point p, point q)   { return real(conj(p) * q); }
double cross(point p, point q) { return imag(conj(p) * q); }
double EPS = 1e-8;
int sign(double x) {
  if (x < -EPS) return -1;
  if (x > +EPS) return +1;
  return 0;
}


struct union_find {
  vector<int> p;
  union_find(int n) : p(n, -1) { };
  bool unite(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return false;
    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v]; p[v] = u;
    return true;
  }
  bool find(int u, int v) { return root(u) == root(v); }
  int root(int u) { return p[u] < 0 ? u : p[u] = root(p[u]); }
  int size(int u) { return -p[root(u)]; }
};

double rectilinear_mst(vector<point> ps) {
  vector<int> id(ps.size()); iota(all(id), 0);
  struct edge { int src, dst; double weight; };
  vector<edge> edges;
  for (int s = 0; s < 2; ++s) {
    for (int t = 0; t < 2; ++t) {
      sort(all(id), [&](int i, int j) {
          return real(ps[i]-ps[j]) < imag(ps[j]-ps[i]);});
      map<double, int> sweep;
      for (int i: id) {
        for (auto it = sweep.lower_bound(-imag(ps[i]));
                  it != sweep.end(); sweep.erase(it++)) {
          int j = it->snd;
          if (imag(ps[j] - ps[i]) < real(ps[j] - ps[i])) break;
          double d = abs(real(ps[i]-ps[j])) + abs(imag(ps[i]-ps[j]));
          edges.push_back({i, j, d}); // all nearest edges in 8 directions
        }
        sweep[-imag(ps[i])] = i;
      }
      for (auto &p: ps) p = point(imag(p), real(p));
    }
    for (auto &p: ps) p = point(-real(p), imag(p));
  }
  double cost = 0;
  sort(all(edges), [](edge a, edge b) { return a.weight < b.weight; });
  union_find uf(ps.size());
  for (auto e: edges)
    if (uf.unite(e.src, e.dst))
      cost += e.weight;
  return cost;
}

vector<point> ps;

int main() {

    int n;
    double x, y;

    scanf("%d", &n);
    ps.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &x, &y);
        ps[i] = point(x, y);
    }
    double a = rectilinear_mst(ps) + .1;
    cout<<fixed<<setprecision(0);
    cout<<a<<endl;

    return 0;
}
