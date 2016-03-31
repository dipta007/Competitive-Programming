#include <iostream>
#include <stdio.h>
using namespace std;

const int INF = 0x7f7f7f7f;
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
    tree[node]=min(tree[left],tree[right]);
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return INF;
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ci=1;ci<=t;ci++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        init(1,1,n);
        printf("Case %d:\n",ci);
        for(int i=0;i<q;i++)
        {
            int I,J;
            scanf("%d %d",&I,&J);
            printf("%d\n",query(1,1,n,I,J));
        }
    }

}
