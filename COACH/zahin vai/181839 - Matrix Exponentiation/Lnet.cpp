#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f
#define MOD 10007

int N, M;
int id[7][7][7][7];
int ans[100];

struct Matriz {
	int mat[100][100];
	Matriz() { cl(mat,0); }
	Matriz operator*(const Matriz &q) const {
		Matriz r = Matriz();
		rp(i,M) rp(j,M) rp(k,M) r.mat[i][j] = (r.mat[i][j] + mat[i][k]*q.mat[k][j])%MOD;
		return r;
	}
} m, aux, res;

void expo(int n) {
	rp(i,M) rp(j,M) aux.mat[i][j] = m.mat[i][j];
	res = Matriz();
	rp(i,M) res.mat[i][i] = 1;
	for (; n > 0; n >>= 1, aux = aux*aux) if (n&1) res = res * aux;
}

int main() {
	M = 0;
	rp(a,6) fr(b,a+1,6) {
		rp(c,6) fr(d,c+1,6) {
			if (c == a-2 || c == a+2 || c == b-2 || c == b+2) continue;
			if (d == a-2 || d == a+2 || d == b-2 || d == b+2) continue;
			id[a][b][c][d] = M++;
			//printf("%d: %d %d %d %d\n", M-1, a, b, c, d);
		}
	}

	m = Matriz();
	rp(a,6) fr(b,a+1,6) {
		rp(c,6) fr(d,c+1,6) {
			if (c == a-2 || c == a+2 || c == b-2 || c == b+2) continue;
			if (d == a-2 || d == a+2 || d == b-2 || d == b+2) continue;

			rp(e,6) fr(f,e+1,6) {
				if (e == c-2 || e == c+2 || e == d-2 || e == d+2) continue;
				if (f == c-2 || f == c+2 || f == d-2 || f == d+2) continue;

				if (e == a-1 || e == a+1 || e == b-1 || e == b+1) continue;
				if (f == a-1 || f == a+1 || f == b-1 || f == b+1) continue;
				int id1 = id[a][b][c][d];
				int id2 = id[c][d][e][f];
				m.mat[id2][id1] = 1;
			}
		}
	}

	cout << M << endl;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		if (N == 1) printf("15\n");
		else {
			expo(N-2);
			cl(ans,0);
			int tot = 0;
			rp(i,M) {
				rp(j,M) tot= (tot + res.mat[i][j])%MOD;
			}
//			rp(j,M) tot = (tot + ans[j])%MOD;
			printf("%d\n", tot);
		}
	}
}
