vector<int >A;
void marge(int lf,int mid,int rt){
    queue<int >L,R;
    forab(i,lf,mid) L.push(A[i]);
    L.push(INF);
    forab(i,mid+1,rt) R.push(A[i]);
    R.push(INF);
    forab(i,lf,rt){
        if(L.front()<R.front()){
            A[i] = L.front();
            L.pop();
        }
        else{
            A[i] = R.front();
            R.pop();
        }
    }
}

void marge_sort(int lf,int rt){
    if(lf<rt){
        int mid = (lf+rt)>>1;
        marge_sort(lf,mid);
        marge_sort(mid+1,rt);
        marge(lf,mid,rt);
    }
}

int main(){
    A.clear();
    int n = II;
    rep(i,n){
        int u = II;
        A.pb(u);
    }
    marge_sort(0,n-1);
    rep(i,n) cout << A[i] << " ";
}
