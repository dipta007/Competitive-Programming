#define MAXN 10000
#define SQRSIZE  100

int arr[MAXN];               // original array
int block[SQRSIZE];          // decomposed array
int blk_sz;                      // block size

// Time Complexity : O(1)
void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}

// Time Complexity : O(sqrt(n))
int query(int l, int r)
{
    int sum = 0;
    while (l<r and l%blk_sz!=0 and l!=0)
    {
        // traversing first block in range
        sum += arr[l];
        l++;
    }
    while (l+blk_sz <= r)
    {
        // traversing completely overlapped blocks in range
        sum += block[l/blk_sz];
        l += blk_sz;
    }
    while (l<=r)
    {
        // traversing last block in range
        sum += arr[l];
        l++;
    }
    return sum;
}

// Fills values in input[]
void preprocess(int n)
{
    // initiating block pointer
    int blk_idx = -1;

    // calculating size of block
    blk_sz = sqrt(n);

    // building the decomposed array
    for (int i=0; i<n; i++)
    {
        if (i%blk_sz == 0)
        {
            // entering next block
            // incementing block pointer
            blk_idx++;
        }
        block[blk_idx] += arr[i];
    }
}

/// *****************************
/// For finding cnt where cnt<=v(vecotr)
#define MAXN 100004
#define SQRSIZE  400

struct info
{
    vector <pii> v;
};

int arr[MAXN];               // original array
info block[SQRSIZE];          // decomposed array
int blk_sz;                      // block size

// Time Complexity : O(1)
void update(int valIdx, int x)
{
    int blockNumber = valIdx / blk_sz;
    int idx = -1;
    arr[valIdx] = x;
    FOR(i,0,(int)block[blockNumber].v.size()-1)
    {
        if(block[blockNumber].v[i].ss==valIdx)
        {
            idx = i;
            break;
        }
    }
    block[blockNumber].v[idx].ff = x;
    FOR(i,idx,block[blockNumber].v.size()-2)
    {
        if(block[blockNumber].v[i].ff > block[blockNumber].v[i+1].ff)
        {
            swap(block[blockNumber].v[i], block[blockNumber].v[i+1]);
        }
    }
    ROF(i,idx,1)
    {
        if(block[blockNumber].v[i].ff < block[blockNumber].v[i-1].ff)
        {
            swap(block[blockNumber].v[i], block[blockNumber].v[i-1]);
        }
    }
}

int lower_bound(int blkNo, int val)
{
    int low = 0;
    int high = block[blkNo].v.size()-1;
    int res = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(block[blkNo].v[mid].ff<=val)
        {
            res = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return res+1;
}

// Time Complexity : O(sqrt(n))
int query(int l, int r, int val)
{
    int res = 0;
    while (l<r && l%blk_sz!=0 && l!=0)
    {
        /// traversing first block in range
        if(arr[l]<=val) res++;
        l++;
    }
    while (l+blk_sz <= r)
    {
        // traversing completely overlapped blocks in range
        int up = lower_bound(l/blk_sz, val);
        res += up;
        l += blk_sz;
    }
    while (l<=r)
    {
        // traversing last block in range
        if(arr[l]<=val) res++;
        l++;
    }
    return res;
}

// Fills values in input[]
void preprocess(int n)
{
    // initiating block pointer
    int blk_idx = -1;

    // calculating size of block
    blk_sz = sqrt(n);

    // building the decomposed array
    for (int i=0; i<n; i++)
    {
        if (i%blk_sz == 0)
        {
            // entering next block
            // incementing block pointer
            blk_idx++;
        }
        block[blk_idx].v.PB(pii(arr[i],i));
    }
    FOR(i,0,blk_idx)
    {
        sort(ALL(block[i].v));
    }
}
