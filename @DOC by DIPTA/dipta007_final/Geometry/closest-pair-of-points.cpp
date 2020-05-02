struct point{
    double x;
    double y;
};
bool cmp(point a,point b)
{
    return a.x<b.x;
}

double distance(point a,point b)
{
    return (double)sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double divide(point a[],int low,int high)
{
    if(low>=high) return 99999;  //切到只剩1個點，return inf

    int mid=(low+high)/2;
    double min_left=divide(a,low,mid);
    double min_right=divide(a,mid+1,high);
    return combine(a,low,mid,high,min_left,min_right);
}
double combine(point a[],int low,int mid,int high,double min_left,double min_right)
{
    double d=(min_left<min_right)?min_left:min_right;
    double line=(double)(a[mid].x+a[mid+1].x)*0.5; //line:左集合與右集合的中間線x座標
    double min_D=d;
    for(int i=mid+1;a[i].x<line+d && i<=high;i++){ //枚舉line+-d範圍內左右集合的點
        for(int j=mid;a[j].x>line-d && j>=low;j--){
            double temp=distance(a[i],a[j]);
            if(temp<min_D) min_D=temp;
        }
    }
    return min_D;
}
