/**
Procedure:
    1. Call init()

**/
const int MS = 100004;
const int MN = 54;

struct trie
{
    struct node
    {
        int c;
        int a[MN];
    };

    node tree[MS];
    void clear()
    {
        tree[nodes].c = 0;
        memset(tree[nodes].a, -1, sizeof tree[nodes].a);
        nodes++;
    }

    int nodes;

    void init()
    {
        nodes = 0;
        clear();
    }

    void add(const string &s, bool query = 0)
    {
        int cur_node = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            int id = gid(s[i]);
            if(tree[cur_node].a[id] == -1)
            {
                tree[cur_node].a[id] = nodes;
                clear();
            }
            cur_node = tree[cur_node].a[id];
        }
        tree[cur_node].c++;
    }

    int query(const string &s)
    {
        int cur_node = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            int id = gid(s[i]);
            if(tree[cur_node].a[id] == -1)
            {
                return 0;
            }
            cur_node = tree[cur_node].a[id];
        }
        return tree[cur_node].c;
    }
};
