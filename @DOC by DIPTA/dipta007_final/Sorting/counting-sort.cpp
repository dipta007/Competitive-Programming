vector<int> counting_sort(vector<int >A){
    map<int,int>C;
    vector<int >B(mx);
    int len = A.size();
    rep(i,len) C[A[i]]++;
    int sum = 0;
    forstl(it,C){
        sum += (*it).second;
        C[(*it).first] = sum;
    }
    per(i,len){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    return B;
}

int main(){
    vector<int >A;
    int n = II;
    rep(i,n){
        int u = II;
        A.pb(u);
    }
    A = counting_sort(A);
    For(i,n) cout << A[i] << " ";
}
