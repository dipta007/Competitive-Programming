/**
Procedure:
    1. Initialize lf and rt to 0 & -1
    2. Get Input using node(a,b,ind)
    3. Sort query
    4. Call MO(i) for every query
    5. Get answers from ans[]
Complexity: O(max(n*sqrt(n), q*sqrt(n), n*sqrt(q), q*log(q)))
Optimizations done:
    1. keep l_bucket
    2. use inline functions
    3. use even odd different sorting
    4. use unsigned

    If nothing works, last resort:
    5. write everything in the main
**** MUST HAVE AT LEAST ONE POSITIVE NUMBER
**/
// 0 BASED
#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

struct node {
	int L, R, id, l_bucket;
	bool even;
	node(int a, int b, int ind)
    {
        L = a, R = b, idx = ind;
        l_bucket = st/bucket_size;
        if(l_bucket & 1)
            even = false;
        else
            even = true;
    }
    node(){}
    bool operator < (const node &b) const
    {
        if(l_bucket == b.l_bucket)
        {
    //        return a.ed < b.ed;
            if(even)
                return ed < b.ed;
            else
                return ed > b.ed;
        }
        return l_bucket < b.l_bucket;
    }
}q[N];

int lf=0, rt=-1;

inline void add(int position) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
		answer++;
	}
}
inline void remove(int position) {
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
