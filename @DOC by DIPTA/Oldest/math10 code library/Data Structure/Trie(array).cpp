const int max_child = 128;
const int max_edge = 1e7;
int get_id(int id){
    return id;
}

struct node{
        int val;
        int next[max_child];
        node(){
                val=0;
                rep(i,max_child)
                        next[i]=-1;
        }
}trie[max_edge/max_child];
int cnt = 0;
void insert(string str){
        int node_id = 0;
        int len = str.size();
        rep(i,len){
                if(trie[node_id].next[get_id(str[i])]==-1){
                        trie[node_id].next[get_id(str[i])]=++cnt;
                }
                node_id = trie[node_id].next[get_id(str[i])];
        }
        trie[node_id].val++;
}

bool find(string str){
        int node_id = 0;
        int len = str.size();
        rep(i,len){
                if(trie[node_id].next[get_id(str[i])]==-1){
                        return 0;
                }
                node_id = trie[node_id].next[get_id(str[i])];
        }
        return (trie[node_id].val != 0);
}

void traverse(node &p){
        rep(i,max_child){
                if(p.next[i]!=-1){
                        traverse(trie[p.next[i]]);
                        p.next[i] = -1;
                }
        }
}
