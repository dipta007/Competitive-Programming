/**
Procedure:
    1. Input N for total man and woman
    2. Input data in pref_man in decreasing order
    3. Input data in pref_woman in decreasing order
**/
int N,pref_men[MAX_N][MAX_N],pref_women[MAX_N][MAX_N];
int inv[MAX_N][MAX_N],cont[MAX_N],wife[MAX_N],husband[MAX_N];

void stable_marriage(){

    for(int i = 0 ; i < N ; i++)
        for(int j = 0;j < N; j++)
            inv[i][pref_women[i][j]] = j;

    fill(cont,cont+N,0);
    fill(wife,wife+N,-1);
    fill(husband,husband+N,-1);
    queue<int> Q;
    for(int i = 0; i < N; i++) Q.push(i);

    int m,w;

    while(!Q.empty()){
        m = Q.front();
        w = pref_men[m][cont[m]];

        if(husband[w] == -1){
            wife[m] = w;
            husband[w] = m;
            Q.pop();
        }else{
            if( inv[w][m] < inv[w][husband[w]] ){
                wife[m] = w;
                wife[husband[w]] = -1;
                Q.pop();
                Q.push(husband[w]);
                husband[w] = m;
            }
        }

        cont[m]++;
    }
}


