#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int b[100000];

void KMPprocess(char pattern[],int m) //// pattern = je patttern ta text e khujte hobe and m = pattern er length
{
    int i=0,j=-1;
    b[0]=-1;
    while(i<m)
    {
        while(j>=0 && pattern[i]!=pattern[j])
            j=b[j];
        i++;
        j++;
        b[i]=j;
    }
}

int KMP(char text[],char pattern[],int n,int m) //text = main text and n = text er length
{
    int cnt=0;
    int i=0,j=0;
    while(i<n)
    {
        while(j>=0 && pattern[j]!=text[i])
            j=b[j];
        i++;
        j++;
        if(j==m)
        {
            cnt++;
            j=b[j];
        }
    }
    return cnt;
}

int main()
{
    char p[100004],t[100004];
    int ct;
    scanf("%d",&ct);
    getchar();
    for(int ci=1;ci<=ct;ci++)
    {
        gets(t);
        gets(p);
        KMPprocess(p,strlen(p));
        int k= KMP(t,p,strlen(t),strlen(p));
        if(k>0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

