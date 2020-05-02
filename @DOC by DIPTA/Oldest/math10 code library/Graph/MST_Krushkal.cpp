struct edge{
    int u,v,w;
    edge( int a ,int b, int c){
        u = a , v = b , w = c;
    }
    edge(){};
};

bool operator < ( edge a ,edge b){  return a.w < b.w ; }

int prev[mx];

int Parent(int i){
    if(i==prev[i])return i;
    return (prev[i]=Parent(prev[i]));
}

int isUnion(int a,int b){
    return Parent(a)==Parent(b);
}

void makeUnion(int a,int b ){
    prev[Parent(a)] = Parent(b);
}

int MST(int n , edge *x , int e ){
  sort(x,x+e);
  rep(i,n) prev[i] = i ;
  int mst = 0 , spanning_edges = 0 ;
  rep(i,e){
        if(!isUnion(x[i].u,x[i].v)){
                makeUnion(x[i].u,x[i].v);
                mst += x[i].w;
                spanning_edges ++ ;
         }
   }
   return mst ; // if(spanning edges == n - 1 )
}

int main(){
    int t ;
    scanf("%d",&t);
    edge x[mx];
    while(t--){
        int n , m  ;
        scanf("%d %d",&n,&m);

        rep(i,m){
            int u , v , w ;
            scanf("%d %d %d",&u,&v,&w);
            x[i] = edge(u,v,w);
        }
        printf("%d\n",MST(n,x,m)) ;
    }
}
