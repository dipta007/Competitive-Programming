/**
Procedure:
    1. Set root = new node()
    2. del(root) after each test case
**/
struct node
{
    bool endmark;
    node *next[26+1];
    node()
    {
        endmark=0;
        for(int i=0; i<26; i++)
			next[i]=NULL;
    }
}*root;
void insert(char *str,int len)			// parameter = word & length of word
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=1;

}
bool search(char *str,int len)			// parameter = word & length of word
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL) return false;
        curr=curr->next[id];
    }
    return curr->endmark;				// jodi word thake then 1 return korbe
										// jodi word na thake dn 0 return korbe
}
void del(node *cur)						// parameter hisebe root pathate hbe
{
    for(int i=0; i<26; i++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}
