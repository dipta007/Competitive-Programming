#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 1000000 + 10;
struct State {
	State*suf, *go[26], *nxt;
	int val, cnt;
	State() :
			suf(0), val(0) {
		memset(go, 0, sizeof go);
	}
}*root, *last;
State statePool[MAX_N * 2], *cur;
State*first[MAX_N] = { };

void init() {
	cur = statePool;
	root = last = cur++;
}

void extend(int w) {
	State*p = last, *np = cur++;
	np->val = p->val + 1;
	np->cnt = 1;
	while (p && !p->go[w])
		p->go[w] = np, p = p->suf;
	if (!p)
		np->suf = root;
	else {
		State*q = p->go[w];
		if (p->val + 1 == q->val) {
			np->suf = q;
		} else {
			State*nq = cur++;
			memcpy(nq->go, q->go, sizeof q->go);
			nq->val = p->val + 1;
			nq->suf = q->suf;
			q->suf = nq;
			np->suf = nq;
			while (p && p->go[w] == q)
				p->go[w] = nq, p = p->suf;
		}
	}
	last = np;
}

int main() {
	string str;
	cin >> str;
	init();
	int L = str.size();
	for (int i = 0; i < L; ++i) {
		extend(str[i] - 'a');
	}
	for (State*i = statePool; i != cur; ++i)
		i->nxt = first[i->val], first[i->val] = i;
	for (int it = L; it >= 0; --it) {
		for (State*i = first[it]; i; i = i->nxt)
			if (i->suf)
				i->suf->cnt += i->cnt;
	}
//	cout << root->go[0]->go[0]->cnt << endl;
	return 0;
}
