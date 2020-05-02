#define max_child 128

int get_id(int id){
    return id;
}

struct node{
        int val;
        node *next[max_child];
        node(){
                val=0;
                rep(i,max_child)
                        next[i]=NULL;
        }
};
node *root=new node();
int tot;
void insert(string str){
        node *curr=root;
        int len = str.size();
        rep(i,len){
                if(curr->next[get_id(str[i])]==NULL){
                        curr->next[get_id(str[i])]=new node();
                }
                curr=curr->next[get_id(str[i])];
        }
        curr->val++;
}

bool find(string str){
        node *curr=root;
        int len = str.size();
        rep(i,len){
                if(curr->next[get_id(str[i])]==NULL){
                        return 0;
                }
                curr=curr->next[get_id(str[i])];
        }
        return (curr->val != 0);
}

void traverse(node *p){
        rep(i,max_child){
                if(p->next[i]!=NULL){
                        traverse(p->next[i]);
                        p->next[i] = NULL;
                        delete p->next[i];
                }
        }
}
