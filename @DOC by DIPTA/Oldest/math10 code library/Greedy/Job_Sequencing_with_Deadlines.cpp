vector<pair<int ,int > >A;
bool flag[mx];
bool cmp(pair<int ,int >a,pair<int ,int >b){
    return a.second > b.second;
}

int Job_Sequencing_with_Deadlines(){
    sort(all(A),cmp);
    memo(flag,false);
    int len = A.size(),max_day = 0,profit = 0;
    rep(i,len){
        int key = -1;
        For(j,A[i].first){
            if(flag[j]==false) key = j;
        }
        if(key != -1){
            flag[key] = true;
            cout << key << " " << A[i].second << endl;
            profit += A[i].second;
        }
    }
    return profit;
}

int main(){
    int n = II;
    rep(i,n){
        int deadLine = II,profit = II;
        A.pb(mp(deadLine,profit));
    }
    cout << "Profit :: " << Job_Sequencing_with_Deadlines() << endl;
}
