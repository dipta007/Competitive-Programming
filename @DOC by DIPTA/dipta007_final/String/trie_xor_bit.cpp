struct node
{
    bool endmark;
    node *next[2];
    node()
    {
        endmark=0;
        for(int i=0; i<2; i++)
            next[i]=NULL;
    }
}*root;

void insert(int n)
{
    node *curr=root;
    for(int i=30; i>=0; i--)
    {
        int id=Check(n,i);
        //debug(id);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=1;

}
int find_max(int n)
{
    node *curr=root;
    int sum=0;
    for(int i=30; i>=0; i--)
    {
        int id=Check(n,i);
        int inv=1-id;       //ja ache tar inverse ta khujtasi tai inverse nilam
        if(curr->next[inv]!=NULL)
        {
            sum=sum | (1<<i);   //jdi inverse pai tahola result er oi position a 1 set hba
            curr=curr->next[inv];
        }
        else
        {
            //na paila 0 set hba
            curr=curr->next[id];
        }
    }
    debug(sum);
    return sum;
}
int find_min(int n)
{
    node *curr=root;
    int sum=0;
    for(int i=30; i>=0; i--)
    {
        int id=Check(n,i);
        int inv=1-id;
        if(curr->next[id]!=NULL)
        {
            curr=curr->next[id];  //jdi inverse pai tahola result er oi position a 0 set hba
        }
        else
        {
            sum=sum | (1<<i); //na paila 1
            curr=curr->next[inv];
        }
    }
    return sum;
}

void del(node *cur)				// send root here
{
    for(int i=0; i<2; i++)
        if(cur->next[i])
            del(cur->next[i]) ;
    delete(cur) ;
}

int main()
{
    int t;
    getI(t);
    for(int cs=1; cs<=t; cs++)
    {
        root=new node();
        int num_word;
        cin>>num_word;
        int n;
        int mx=0,mn=INF,tmp=0;
        insert(0);
        for(int i=1; i<=num_word; i++)
        {
            getI(n);
            tmp=tmp^n;
            mx=max(mx,find_max(tmp));
            mn=min(mn,find_min(tmp));
            insert(tmp);
        }
        printf("Case %d: %d %d\n",cs,mx,mn);
        del(root);
    }
    return 0;
}

/*Suppose you have saved all consecutive XOR sum from index [0, 0], [0, 1], [0, 2], ..., [0, i-1],
now we want to calculate for result [0, i] and save it. And you also want to find a k such that[k, i]
is as large as possible. Usually [k, i] = [0, i] (XOR) [0, k - 1].Say, [0, i] = 11011, then you would
definitely want to find 00100 in your saved list. If you cannot find that you would want to find the
number closer to that
*/


