vector<pair<db ,db > >A;

bool cmp(pair<db ,db >a,pair<db ,db >b){
    return (((a.first/a.second)-(b.first/b.second)) > EPS) ;
}

db Fractional_Knapsack(db m){
    sort(all(A),cmp);
    int len = A.size();
    db profit = 0;
    rep(i,len){
        if(A[i].second<m){
            profit += A[i].first;
            m -= A[i].second;
        }
        else{
            profit += (A[i].first * (m / A[i].second) );
            break;
        }
    }
    return profit;
}

int main(){
    int n = II;
    db m = ID;
    rep(i,n){
        int p = II,w = II;
        A.pb(mp(p,w));
    }
    cout << Fractional_Knapsack(m) << endl;
}
