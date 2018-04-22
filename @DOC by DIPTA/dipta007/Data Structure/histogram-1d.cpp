const int MAX = 30004;
int hist[MAX];
int getArea(int n)
{
    stack < int > s;
    int max_area = 0;
    int i = 0;
    while( i < n )
    {
        if(s.empty() || hist[s.top()] <= hist[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            int now = s.top();
            s.pop();
            int now_area = hist[now] * (s.empty() ? i : i- s.top() - 1);
            if(now_area > max_area)
            {
                max_area = now_area;
            }
        }
    }
    while(!s.empty())
    {
        int now = s.top();
        s.pop();
        int now_area = hist[now] * (s.empty() ? i : i- s.top() - 1);
        if(now_area > max_area)
        {
            max_area = now_area;
        }
    }

    return max_area;
}
