#include <iostream>
#include <stdio.h>
using namespace std;

#define mx 100004
int arr[mx];
int tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int i,int nv)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i)
    {
        tree[node]=nv;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,nv);
    update(right,mid+1,e,i,nv);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ci=1;ci<=t;ci++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        init(1,0,n-1);
        int w;
        printf("Case %d:\n",ci);
        for(int j=0;j<q;j++)
        {
            int w,k;
            scanf("%d",&w);
            if(w==1)
            {
                scanf("%d",&k);
                arr[k]=0;
                printf("%d\n",query(1,0,n-1,k,k));
                update(1,0,n-1,k,0);
            }
            else if(w==2)
            {
                int v;
                scanf("%d %d",&k,&v);
                update(1,0,n-1,k,arr[k]+v);
                arr[k]=arr[k]+v;
            }
            else if(w==3)
            {
                int v;
                scanf("%d %d",&k,&v);
                printf("%d\n",query(1,0,n-1,k,v));
            }
        }
    }
}
