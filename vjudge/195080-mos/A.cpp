/*
	By Anudeep Nekkanti
	Editorial at http://blog.anudeep2011.com/mos-algorithm/
	Question at http://www.spoj.com/problems/DQUERY/
	O( (N+M) * sqrt N )
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

struct node {
	int L, R, id;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

int lf, rt;

void add(int position) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
		answer++;
	}
}

void remove(int position) {
	cnt[a[position]]--;
	if(cnt[a[position]] == 0) {
		answer--;
	}
}

inline void MO(int i) {
    int L = q[i].L;
    int R = q[i].R;

    while(rt != R)
    {
        if(rt < R)
        {
            rt++;
            add(rt);
        }
        else
        {
            remove(rt);
            rt--;
        }
    }

    while(lf != L)
    {
        if(lf < L)
        {
            remove(lf);
            lf++;
        }
        else
        {
            lf--;
            add(lf);
        }
    }

    ans[ q[i].id ] = answer;
}

int main() {

    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	int m;
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d%d", &q[i].L, &q[i].R);
        q[i].L--, q[i].R--;
		q[i].id = i;
	}

	sort(q, q + m, cmp);

	lf = 0, rt = -1;
	for(int i=0; i<m; i++) {
		MO(i);
	}

	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);
}
