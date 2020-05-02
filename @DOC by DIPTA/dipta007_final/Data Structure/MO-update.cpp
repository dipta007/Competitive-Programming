///Always notice the base of indexing,this is 0 based
///Make last[] = arr[]
int arr[N], angry[N], last[N];
int magic = 2154;
ll sum;
struct query{
    int l, r, t, id;
    query(){}
    query(int l, int r, int t, int id):l(l),r(r),t(t),id(id){}
}Q[N];
struct update{
    int x,pre,now;
    update(){}
    update(int x,int pre, int now):x(x),pre(pre),now(now){}
}U[N];
bool comp(query a, query b){
    int l1 = a.l/magic, l2 = b.l/magic;
    int r1 = a.r/magic, r2 = b.r/magic;
    if(l1 != l2) return l1 < l2;
    if(r1 != r2) return r1 < r2;
    return a.t < b.t;
}
int l,r,T,cnt[N];
ll ans[N];
void Add(int x){
    cnt[arr[x]] += 1;
    sum += 1LL*arr[x]*angry[cnt[arr[x]]];
}
void Remove(int x){
    sum -= 1LL*arr[x]*angry[cnt[arr[x]]];
    cnt[arr[x]] -= 1;
}
void Apply(int x, int y){
    if(l <= x && x <= r)Remove(x);
    arr[x] = y;
    if(l <= x && x <= r)Add(x);
}
ll get_ans(){
    return sum;
}
void MO_With_Update(int q_id){
    sort(Q,Q+q_id,comp);
    l = 0, r = -1; sum = 0;
    T = 0;
    CLR(cnt);
    for(int i = 0; i < q_id; i++){
        while(T < Q[i].t)T++,Apply(U[T].x, U[T].now);
        while(T > Q[i].t)Apply(U[T].x, U[T].pre),T--;
        while(l > Q[i].l)Add(--l);
        while(r < Q[i].r)Add(++r);
        while(l < Q[i].l)Remove(l++);
        while(r > Q[i].r)Remove(r--);
        ans[Q[i].id] = get_ans();
    }
    for(int i = 0; i < q_id; i++){
        cout << ans[i] << endl;
    }
}
void ProcessInput(int q){
    int q_id = 0, u_id = 0;
    for(int i = 1; i <= q; i++){
        int t, x, y; cin >> t >> x >> y;
        x--;
        if(t == 1){
            y --;
            Q[q_id]=query(x,y,u_id,q_id);
            q_id += 1;
        }
        else{
            U[++u_id] = update(x,last[x],y);
            last[x] = y;
        }
    }
    MO_With_Update(q_id);
}

