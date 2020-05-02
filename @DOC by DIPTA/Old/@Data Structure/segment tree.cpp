// jodi proti ber 1 ta value update korte hoi dn eita use kora better

#define MAX 100004
int arr[MAX];


int tree[MAX*4];

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node]=arr[b];
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=tree[Left]+tree[Right];
}
int query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return 0;
	if (b >= i && e <= j) return tree[node];
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int p1=query(Left,b,mid,i,j);
	int p2=query(Right,mid+1,e,i,j);
	return p1+p2;
}
void update(int node,int b,int e,int i,int newvalue)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i) {
		tree[node]=newvalue;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,newvalue);
	update(Right,mid+1,e,i,newvalue);
	tree[node]=tree[Left]+tree[Right];
}
