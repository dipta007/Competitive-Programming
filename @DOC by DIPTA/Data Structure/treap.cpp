struct node {
	int size, prior, val;
	node *left, *right;
	node(){}
	node(int val) {
		size = 1;
		this->val = val;
		prior = rand();
		left = right = NULL;
	}
} *root;
typedef node* pnode;

int sz(pnode t) {
	return t?t->size:0;
}
void updateSz(pnode t) {
	if(t) t->size = 1 + sz(t->left) + sz(t->right);
}

void split(pnode t, pnode &l, pnode &r, int key) {
	if(!t) l = r = NULL;
	else if(t->val <= key)
		split(t->right, t->right, r, key), l = t;
	else split(t->left, l, t->left, key), r = t;
	updateSz(t);
}
void merge(pnode &t, pnode l, pnode r) {
	if(!l || !r) t = l ? l : r;
	else if(l->prior > r->prior)
		merge(l->right, l->right, r), t = l;
	else merge(r->left, l, r->left), t = r;
	updateSz(t);
}

bool find(pnode t, int val) {
	if(!t) return 0;
	else if(t->val == val) return 1;
	else if(val <= t->val)
		return find(t->left, val);
	else return
		find(t->right, val);
}

void insert(pnode &t, pnode it) {
	if(!t) t = it;
	else if(it->prior > t->prior) {
		split(t, it->left, it->right, it->val);
		t = it;
	} else insert(it->val <= t->val ? t->left : t->right, it);
	updateSz(t);
}

void erase(pnode &t, int val) {
	if(!t) return;
	else if(val == t->val) {
		pnode tmp = t;
		merge(t, t->left, t->right);
		free(tmp);
	} else {
		erase(val <= t->val ? t->left : t->right, val);
	} updateSz(t);
}

void insert(int num) {
	pnode x = new node(num);
	insert(root, x);
}


int countLess(int x) {
	pnode l, r;
	split(root, l, r, x-1);
	int ans = sz(l);
	merge(root, l, r);
	return ans;
}
int kth(pnode t, int k) {
	int cntleft = sz(t->left);
	if(cntleft == k-1) return t->val;
	else if(cntleft >= k) {
		return kth(t->left, k);
	} else return kth(t->right, k - cntleft - 1);
}


----------------------------------

void unite (pnode &t,pnode l, pnode r) {
    if (!l || !r) return void(t = l ? l : r);
    if (l->prior < r->prior) swap (l, r);
    pnode lt, rt;
    split (r,lt, rt,l->val);
    unite (l->left,l->left, lt);
    unite (l->right,l->right, rt);
    t=l;
    updateSz(t);
}

*****************************

int getVal(pnode it) {
	return it? it-> val: 0;
}

void updateVal(pnode it) {
	if (it)
		it-> val = cnt (it-> left) + cnt (it-> right) + 1;
}

void push (pnode it) {
	if (it && it-> rev) {
		it-> rev = false;
		swap (it-> l, it-> r);
		if (it-> l) it-> l-> rev ^ = true;
		if (it-> r) it-> r-> rev ^ = true;
	}
}

void reverse (pnode t, int l, int r) {
	pnode t1, t2, t3;
	split (t, t1, t2, l);
	split (t2, t2, t3, r-l + 1);
	t2-> rev ^ = true;
	merge (t, t1, t2);
	merge (t, t, t3);
}

void output (pnode t) {
	if (! t) return;
	push (t);
	output (t-> l);
	printf ("% d", t-> value);
	output (t-> r);
}

/*
 * Left Rotation
 */
void CTree::sigrotl(ctree& k1)
{
    ctree k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}

/*
 * Right Rotation
 */
void CTree::sigrotr(ctree& k1)
{
    ctree k2;
    k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1 = k2;
}

/*
 * Display elements of Treap
 */
void CTree::display(ctree ptr, int level)
{
    int i;
    if (ptr == nullnode)
        return;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        cout<<endl;
        if (ptr == root)
       	    cout<<"Root->:  ";
        else
        {
            for (i = 0; i < level; i++)
                cout<<"       ";
        }
        cout<<ptr->key;
        display(ptr->left, level + 1);
    }
}
