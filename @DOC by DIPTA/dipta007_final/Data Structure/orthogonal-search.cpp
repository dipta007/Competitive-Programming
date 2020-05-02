/// LighOJ 1120 - Rectangle Union
/// Area of all rectangle union
/// Given x1, y1 - lower left
///       x2, y2 - upper right
/// Find the area of all union rectangle

const int MX = 1e5;
struct data{
    int x, y1, y2, val;
    data(){}
    data(int x, int y1, int y2, int val): x(x), y1(y1), y2(y2), val(val){}
} event[MX];

bool cmp(const data &a, const data &b) {
    return a.x < b.x;
}

int arr[MX], lazy[MX * 4];
ll sum[MX * 4];

void push(int node, int b, int e){
    if(lazy[node]){
        sum[node] = arr[e] - arr[b - 1];
    }
    else sum[node] = sum[node * 2] + sum[node * 2 + 1];
}
void update(int node, int b, int e, int i, int j, int val){
    if(e < i || b > j) return;
    if(b >= i && e <= j){
        lazy[node] += val;
        push(node, b, e);
        return;
    }
    int L = node * 2, R = L + 1, mid = (b + e) / 2;
    update(L, b, mid, i, j, val);
    update(R, mid + 1, e, i, j, val);
    push(node, b, e);
}


int main() {
    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n;
        cin >> n;
        int in = 0;
        int ind = 0;
        FOR(i,1,n)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            event[in++] = data(x1, y1, y2, 1);
            event[in++] = data(x2, y1, y2, -1);

            arr[ind++] = y1;
            arr[ind++] = y2;
        }

        sort(arr, arr+ind);
        ind = unique(arr, arr+ind) - arr;
        sort(event, event+in, cmp);

        CLR(sum);
        CLR(lazy);
        ll res = 0;
        FOR(i,0,in-1)
        {
            int l = lower_bound(arr, arr+ind, event[i].y1) - arr;
            int r = lower_bound(arr, arr+ind, event[i].y2) - arr;

            trace(l, r, sum[1], res);
            trace(event[i].y1, event[i].y2, event[i].x);
            if(!i) {
                update(1, 0, ind, l+1, r, event[i].val);
            }
            else {
                res += sum[1] * (event[i].x - event[i-1].x);
                update(1, 0, ind, l+1, r, event[i].val);
            }
        }
        cout << "Case " << ci << ": " << res << endl;
    }

    return 0;
}



