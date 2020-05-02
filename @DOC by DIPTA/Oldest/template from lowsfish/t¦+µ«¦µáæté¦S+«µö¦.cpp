#include<iostream>
#include<cstdio>
using namespace std;
const int INTMAX=1<<31;
const int MAXN=1<<17;
int n,dat[MAXN*2-1];

void init(int n_)		//��ʼ���߶��� 
{
	n=1;
	while(n<n_) n<<=1;
	for(int i=0;i<2*n-1;++i)
		dat[i]=INTMAX;
}

void update(int k,int a)		//����k��ֵ����Ϊa 
{
	k+=n-1;
	dat[k]=a;
	while(k>0)
	{
		k=(k-1)>>1;
		dat[k]=min(k*2+1,k*2+2);
	}
}

int query(int a,int b,int k,int l,int r)	//��ѯ����[a,b)����Сֵ 
{
	if(r<=a||b<=l) return INTMAX;		//���[a,b)��[l,r)û�н������ͷ���һ���㹻����� 
	if(a<=l&&b>=r) return dat[k];		//���[a,b)��ȫ����[l,r)���ͷ��ص�ǰ�ڵ��ֵ 
	return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));		//���򷵻����������е���С�� 
}

int main()
{
	return 0;
}
