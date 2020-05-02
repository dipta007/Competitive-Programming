// using 0 based index

#define MAX 40005
vector<int> g[MAX],gt[MAX];
list<int> L;
bool vi[MAX];
int num[MAX];
int giveNode(int x,char ch){
	x <<=1;
	if(ch=='-') return x+1;
	return x;
}
void dfs1(int x){
	vi[x] = 1;
	int i,sz = g[x].size(),y;
	for(i = 0;i<sz;i++){
		y = g[x][i];
		if(!vi[y])	dfs1(y);
	}
	L.push_front(x);
}
void dfs2(int x,int cnt){
	num[x] = cnt;
	int i,sz = gt[x].size(),y;
	for(i = 0;i<sz;i++){
		y = gt[x][i];
		if(num[y]==-1) dfs2(y,cnt);
	}
}
int main(){
	list<int>::iterator it;
	vector<int> v;
	int i,x,y,n,m,t,cs = 1;
	char ch1,ch2;

	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&m,&n);
		for(i = 0;i<2*n;i++)
			g[i].clear(),gt[i].clear(),num[i] = -1,vi[i] = 0;

		for(i = 0;i<m;i++){
			scanf(" %c%d %c%d",&ch1,&x,&ch2,&y);
			x = giveNode(x-1,ch1);
			y = giveNode(y-1,ch2);
			/*
			+x +y ,take x or take y
			+x -y ,take x or remove y
			-x +y ,remove x or take y
			-x -y, remove x or remove y
			*/
			g[x^1].pb(y);
			g[y^1].pb(x);

			gt[y].pb(x^1);
			gt[x].pb(y^1);
		}
		L.clear();
		for(i = 0;i<2*n;i++){
			if(!vi[i]) dfs1(i);
		}
		int cnt = 0;
		for(it=L.begin();it!=L.end();it++){
			if(num[*it]==-1)
				dfs2(*it,cnt++);
		}
		v.clear();
		printf("Case %d: ",cs++);
		for(i = 0;i<2*n;i+=2){
			if(num[i]==num[i^1]){
				break;
			}
		}
		if(i<2*n){
			puts("No");
			continue;
		}
		for(i = 0;i<2*n;i+=2){
			if(num[i]>num[i^1]) v.push_back(i/2);
		}
		printf("Yes\n%d",v.size());
		for(i = 0;i<v.size();i++) printf(" %d",v[i]+1);
		puts("");
	}
	return 0;
}
