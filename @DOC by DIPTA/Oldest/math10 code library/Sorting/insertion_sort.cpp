vector<int> insertion_sort(vector<int >A){
    int len = A.size();
    forab(i,1,len-1){
        int key = A[i];
        int j = i - 1;
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    return A;
}

int main(){
    int n = II;
    vector<int >A;
    rep(i,n){
        int u = II;
        A.pb(u);
    }
    A = insertion_sort(A);
    rep(i,n) cout << A[i] << " ";
}
