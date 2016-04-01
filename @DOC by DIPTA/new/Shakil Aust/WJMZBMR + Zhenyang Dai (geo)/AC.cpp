#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
using namespace std;

const int CHARSET = 26;
const int MAX_N_NODES = int(3e5) + 10;

int pointer;
struct Node {
	Node*ch[CHARSET], *fail, *par;
	Node() {
		memset(ch, 0, sizeof ch);
		fail = 0;
	}
	Node*go(int w);
}*root;

Node nodePool[MAX_N_NODES], *cur;

Node*newNode() {
	Node*t = cur++;
	memset(t->ch, 0, sizeof t->ch);
	t->fail = 0;
	return t;
}

Node* Node::go(int w) {
	if (ch[w] == 0) {
		ch[w] = newNode();
		ch[w]->par = this;
	}
	return ch[w];
}

void init() {
	cur = nodePool;
	root = newNode();
	root->par = 0;
}

void build() {
	static Node*que[MAX_N_NODES];
	int qh = 0, qt = 0;
	que[qt++] = root;
	while (qh < qt) {
		Node*t = que[qh++];
		for (int c = 0; c < CHARSET; ++c) {
			Node*v = t->ch[c];
			if (!v)
				continue;
			Node*f = t->fail;
			while (f && f->ch[c] == 0)
				f = f->fail;
			if (f == 0)
				v->fail = root;
			else
				v->fail = f->ch[c];
			que[qt++] = v;
		}
	}
}
