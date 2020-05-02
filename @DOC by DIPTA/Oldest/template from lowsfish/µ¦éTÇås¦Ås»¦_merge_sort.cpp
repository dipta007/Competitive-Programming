#include<iostream>
#include<cstdio>
using namespace std;
long long cnt;

//对区间[l,r)进行排序
void merge_sort(int *A,int l,int r,int *T)
{
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		int p=l,q=m,i=l;
		merge_sort(A,l,m,T);
		merge_sort(A,m,r,T);
		while(p<m || q<r)
		{
			if(q>=r || (p<m && A[p]<=A[q]) ) T[i++]=A[p++];
			else {
				T[i++]=A[q++];
				cnt+=m-p;		//答案加上左边元素个数
			}
		}
		for(i=l;i<r;++i) A[i]=T[i];		//从辅助数组复制到新数组
	}
}
int main()
{
//	freopen("1.in","r",stdin);
	int *A,*T;
	int n;
	while(cin>>n)
	{
		if(!n) return 0;
		cnt=0;		//别忘了初始化
		A=new int[n+1];
		T=new int[n+1];
		for(int i=0;i<n;++i) cin>>A[i];
		merge_sort(A,0,n,T);
		cout<<cnt<<endl;
		delete []A;
		delete []T;
	}
	return 0;
}
