#define MX 1000004
int arr[MX];

struct node {
	int size, prior;
    ll val; //value stored in the array
    ll sum; //whatever info you want to maintain in segtree for each node
    ll lazy; //whatever lazy update you want to do
    node *l, *r;
	node(){}
	node(int val) {
		size = 1;
		this->val = val;
		prior = rand();
        lazy = 0;
        sum = val;
		l = r = NULL;
	}
} *root;

typedef node* pnode;

int sz(pnode t){
    return t?t->size:0;
}
void upd_sz(pnode t){
    if(t) t->size = sz(t->l) + 1 + sz(t->r);
}

void lazy(pnode t){
    if(!t || !t->lazy)return;

    /// Update the value of current subtree
    t->val += t->lazy;
    t->sum += t->lazy * sz(t);

    /// Propagate Lazy to the left and right subtree
    if(t->l) t->l->lazy += t->lazy;
    if(t->r) t->r->lazy += t->lazy;
    t->lazy=0;
}
void reset(pnode t){
   if(t)t->sum = t->val;//lazy already propagated
}
void combine(pnode& t,pnode l,pnode r){//combine segtree ranges
    if(!l || !r)return void(t = l?l:r);
    t->sum = l->sum + r->sum ;
}
void operation(pnode t){//operation of segtree
    if(!t)return;
    reset(t);//node represents single element of array
    lazy(t->l);lazy(t->r); //imp:propagate lazy before combining l,r
    combine(t,t->l,t);combine(t,t,t->r);
}

void split(pnode t, pnode &l, pnode &r, int pos, int add=0){
    if(!t) return void(l=r=NULL);
    lazy(t);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to "l"
            split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else    split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}
void merge(pnode &t,pnode l,pnode r){//result //left //right array
    lazy(l); lazy(r);
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
    else                       merge(r->l,l,r->l),t=r;
    upd_sz(t); operation(t);
}

/// For initialize or print
pnode init(int val){
    pnode ret = new node(val);
    return ret;
}
void initArray(int sz)
{
    for(int i=0; i<sz; i++)
    {
        pnode it = init( arr[i] );
        if(i==0) root = it;
        else merge(root, root, it);
    }
}
void print(pnode rr, int n)
{
    FOR(i,0,n-1)
    {
        if(i) printf(" ");
        pnode tmp;
        split(rr, tmp, rr, 0);
        printf("%d",tmp->val);
    }
    printf("\n");
}
void output (pnode t) {
	if (! t) return;
	lazy (t);
	output (t-> l);
	printf ("%d", t-> val);
	output (t-> r);
}
void display(pnode t, int level)
{
    if (!t) return;
    display(t->r, level + 1);
    cout<<endl;
    if (t == root)
   	    cout<<"Root->:  ";
    else
    {
        for (int i = 0; i < level; i++)
            cout<<"       ";
    }
    cout<<t->val;
    display(t->l, level + 1);
}
void clear_tree(pnode t)
{
    if(!t) return;
    clear_tree(t->l);
    clear_tree(t->r);
    free(t);
}

/// Segment Tree Functions
ll range_query(pnode t,int l,int r){//[l,r]
   pnode L,mid,R;
   split(t,L,mid,l-1);
   split(mid,t,R,r-l);//note: r-l!!
   // Answer will be the total ans of the ranges
   ll ans = t->sum;
   merge(mid,L,t);
   merge(t,mid,R);
   return ans;
}
void range_update(pnode t,int l,int r, int val){//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l); //note: r-l!!
    t->lazy += val; //lazy_update
    merge(mid,L,t);
    merge(t,mid,R);
}

/// More usual Functions
bool find(pnode t, int val) {
	if(!t)                 return 0;
	else if(t->val == val) return 1;
	else if(val <= t->val) return find(t->l, val);
	else                   return find(t->r, val);
}
void insert(pnode &t, pnode it) {
	if(!t) t = it;
	else if(it->prior > t->prior) {
		split(t, it->l, it->r, it->val);
		t = it;
	}
    else insert(it->val <= t->val ? t->l : t->r, it);
	upd_sz(t);
}
void insert(int num) {
	pnode x = init(num);
	insert(root, x);
}
void erase(pnode &t, int val) {
	if(!t) return;
	else if(val == t->val) {
		pnode tmp = t;
		merge(t, t->l, t->r);
		free(tmp);
	} else {
		erase(val <= t->val ? t->l : t->r, val);
	}
    upd_sz(t);
}
// returns the number of elemnets less than X
int countLess(int X) {
	pnode l, r;
	split(root, l, r, X-1);
	int ans = sz(l);
	merge(root, l, r);
	return ans;
}
// returns the kth no in the list
int kth(pnode t, int k) {
	int cntleft = sz(t->l);
	if(cntleft == k-1)     return t->val;
	else if(cntleft >= k)  return kth(t->l, k);
	else                   return kth(t->r, k - cntleft - 1);
}
// reverse the range, needs lazy propagation and rev bit
void reverse (pnode t, int l, int r) {
	pnode t1, t2, t3;
	split (t, t1, t2, l);
	split (t2, t2, t3, r-l + 1);
	t2->rev ^= true;
	merge (t, t1, t2);
	merge (t, t, t3);
}

