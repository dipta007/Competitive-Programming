#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

/*** Note that duplicates are discarded by the unordered_set ***/

class Treap{
    public:

    struct Node{
        Node *l, *r;
        int val, counter;
        unsigned int priority;

        Node(){
            l = r = 0;
        }

        Node(int x){
            l = r = 0;
            counter = 1, val = x;
            priority = rand();
            if (priority < 32768) priority = (priority << 17) ^ rand();
        }

        ~Node(){
            delete l;
            delete r;
        }

        void update(){
            counter = 1;
            if (l) counter += l->counter;
            if (r) counter += r->counter;
        }
    };

    /*** Merge two treaps in O(log n), Assumes l and r are in the appropriate order
         All values in the first are less than the values at the second
    ***/
    Node* merge(Node* l, Node* r){
        if (!l) return r;
        if (!r) return l;

        if (l->priority < r->priority){
            l->r = merge(l->r, r);
            l->update();
            return l;
        }
        else{
            r->l = merge(l, r->l);
            r->update();
            return r;
        }
    }

    /*** Divides the tree T into two trees L and R so that L contains all elements that
         are smaller than x, and R contains all elements that are equal to or larger than x.
    ***/
    void split(Node* cur, Node* &l, Node* &r, int x){
        l = r = 0;
        if (!cur) return;

        if (cur->val < x){
            split(cur->r, cur->r, r, x);
            l = cur;
        }
        else{
            split(cur->l, l, cur->l, x);
            r = cur;
        }

        cur->update();
    }

    Node* root;
    tr1::unordered_set <int> S; /*** Remove if no duplicates are guaranteed ***/

    Treap(){
        root = 0;
        S.clear();
        srand(time(0));
    }

    ~Treap(){
        delete root;
    }

    bool insert(int x){
        if (S.count(x)) return false;

        Node *l, *r;
        split(root, l, r, x);
        root = merge(l, merge(new Node(x), r));
        S.insert(x);
        return true;
    }

    bool erase(int x){
        if (!S.count(x)) return false;

        Node *l, *r, *m;
        split(root, l, m, x);
        split(m, m, r, x + 1);

        if (m && m->counter == 1 && m->val == x){
            delete m;
            root = merge(l, r);
            S.erase(x);
            return true;
        }
        else return false;
    }

    int size(){
        if (root) return root->counter;
        return 0;
    }

    /*** Returns the k'th smallest element of the treap in 1-based index, -1 on failure ***/
    int kth(int k){
        if ((k < 1) || (k > size())) return -1;

        Node *l, *r, *cur = root;
        for (; ;){
            l = cur->l, r = cur->r;
            if (l){
                if (k <= l->counter) cur = l;
                else if ((l->counter + 1) == k) return cur->val;
                else cur = r, k -= (l->counter + 1);
            }
            else{
                if (k == 1) return (cur->val);
                else cur = r, k--;
            }
        }
    }

    /*** Returns the count of values strictly less than x ***/
    int count(int x){
        int res = 0;
        Node *l, *r, *cur = root;

        while (cur){
            l = cur->l, r = cur->r;
            if (cur->val < x) res++;
            if (x < cur->val) cur = l;
            else{
                cur = r;
                if (l) res += l->counter;
            }
        }
        return res;
    }
};

int main(){
    char str[10];
    int n, i, j, x, res;

    scanf("%d", &n);
    Treap T = Treap();
    while (n--){
        scanf("%s %d", str, &x);
        if (str[0] == 'I') T.insert(x);
        if (str[0] == 'D') T.erase(x);
        if (str[0] == 'C') printf("%d\n", T.count(x));
        if (str[0] == 'K'){
            res = T.kth(x);
            if (res == -1) puts("invalid");
            else printf("%d\n", res);
        }
    }
    return 0;
}

