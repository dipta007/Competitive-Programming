/*
	By Anudeep Nekkanti
	Editorial at http://blog.anudeep2011.com/mos-algorithm/
	Question at http://www.spoj.com/problems/DQUERY/
	O( (N+M) * sqrt N )
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long

#define N 200004
#define A 1000004
#define BLOCK 448 // ~sqrt(N)

int cnt[A], a[N];
ll ans[N];
ll answer = 0;

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

ll get(int pos)
{
    return (ll)cnt[a[pos]] * cnt[a[pos]] * a[pos];
}

void add(int position) {
    answer -= get(position);
	cnt[a[position]]++;
    answer += get(position);
}

void remove(int position) {
    answer -= get(position);
	cnt[a[position]]--;
    answer += get(position);
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
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

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
		printf("%lld\n", ans[i]);
}
