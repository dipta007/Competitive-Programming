int p[mx];
bool t[mx];
unsigned long long esum[mx],phi[mx];
void euler(){
    forab(i,2,mx-7){
        if(!t[i])p[++p[0]]=i,esum[i]=i-1;
        for(int j=1;j<=p[0]&&i*p[j]<=mx-7;++j){
            t[i*p[j]]=true;
            if(i%p[j]==0){
                esum[i*p[j]]=p[j]*esum[i];
                break;
            }else{
                esum[i*p[j]]=(p[j]-1)*esum[i];
            }
        }
    }
    forab(i,2,mx-7){
        phi[i] = esum[i];
        esum[i]+=esum[i-1];
    }
}
