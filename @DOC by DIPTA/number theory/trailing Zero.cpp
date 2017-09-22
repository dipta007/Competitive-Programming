
int trailngZeroInFactorial(int xx, int base=10)
{
    int tmp=xx;
    int two = 0;
    while(xx)
    {
        two += (xx/2);
        xx/=2;
    }
    xx=tmp;
    int five=0;
    while(xx)
    {
        five+=(xx/5);
        xx/=5;
    }
    return min(two,five);
}
