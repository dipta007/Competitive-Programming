/***
    Call root = new data();
    then execute all the operations on root
***/

/// TODO: Implement memory cache
/// using: http://codeforces.com/blog/entry/60321
struct data
{
    int from, to;
    ll sum, lazy;
    data *left, *right;
    data()
    {
        from=0;
        to=1e5;
        sum=0;
        lazy=0;
        left=NULL;
        right=NULL;
    }
    void extend()
    {
        if(left==NULL)
        {
            left=new data();
            right=new data();
            left->from=from;
            left->to=(from+to)>>1;
            right->from = left->to + 1;
            right->to=to;
        }
    }
};

data *root;

void merge(data *node, data *a, data *b)
{
    node->sum = a->sum + b->sum;
    node->lazy = 0;
}

void propagate(data *node)
{
    node->sum += (node->to-node->from+1) * node->lazy;
    if(node->from != node->to)
    {
        node->extend();
        node->left->lazy += node->lazy;
        node->right->lazy += node->lazy;
    }
    node->lazy=0;
}

void update(data *node, int left, int right, long long newVal)
{
    if(node->lazy) propagate(node);


    /// Not in the block
    if((node->from) > (node->to) || (node->from) > right || (node->to) < left) return;

    /// Right in the block
    if(node->from >= left && node->to <= right)
    {
        node->sum += (node->to - node->from+1) * newVal;
        if(node->from != node->to)
        {
            node->extend();
            node->left->lazy += newVal;
            node->right->lazy += newVal;
        }
        return;
    }
    node->extend();
    update(node->left,left,right,newVal);
    update(node->right,left,right,newVal);
    merge(node, node->left, node->right);
}

ll query(data *node, int left, int right)
{
    /// Not in the block
    if((node->from) > (node->to) || (node->from) > right || (node->to) < left) return 0;
    if(node->lazy) propagate(node);

    if(node->from >= left && node->to <= right) return node->sum;

    node->extend();
    ll q1=query(node->left, left,right);
    ll q2=query(node->right, left,right);
    return q1+q2;
}
