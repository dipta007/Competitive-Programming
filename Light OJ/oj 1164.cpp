#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define mx 100004

struct info{
    long long int sum,prop;
}tree[mx*3];

int arr[mx];

void update(int node,int b,int e,int i,int j,long long int x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

long long int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node].sum+carry*(e-b+1);

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p1+p2;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ci=1;ci<=t;ci++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        printf("Case %d:\n",ci);
        for(int i=1;i<=q;i++)
        {
            int w;
            scanf("%d",&w);
            if(w==0)
            {
                int x,y,v;
                scanf("%d %d %d",&x,&y,&v);
                update(1,0,n-1,x,y,v);
            }
            else if(w==1)
            {
                int x,y;
                scanf("%d %d",&x,&y);
                printf("%lld\n",query(1,0,n-1,x,y));
            }
        }
    }
}
