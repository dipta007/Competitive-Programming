#include <stdio.h>
int main()
{
    int t, i, count, j;
    scanf("%d ", &t);
    for(i=1;i<=t;i++){
        char ch[150];
        gets(ch);
        count = 0;
        for(j=0;ch[j]!=NULL;j++){
            if( ch[j]=='a' || ch[j]=='d' || ch[j]=='g' || ch[j]=='j' || ch[j]=='m' || ch[j]=='p' || ch[j]=='t' || ch[j]=='w' || ch[j]==' ')
                count++;
            else if( ch[j]=='b' || ch[j]=='e' || ch[j]=='h' || ch[j]=='k' || ch[j]=='n' || ch[j]=='q' || ch[j]=='u' || ch[j]=='x')
                count = count +2;
            else if( ch[j]=='c' || ch[j]=='f' || ch[j]=='i' || ch[j]=='l' || ch[j]=='o' || ch[j]=='r' || ch[j]=='v' || ch[j]=='y')
                count = count+3;
            else
                count = count +4;
        }
        printf("Case #%d: %d\n", i, count);
    }
    return 0;
}
