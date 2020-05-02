#include <iostream>
using namespace std;

#define size 5000

class stck{
    int top;
    int st[size];
public:
    stck()
    {
        top=0;
    }
    void push(int c)
    {
        st[top]=c;
        top++;
    }
    int pop()
    {
        top--;
        return st[top];
    }
    bool emp()
    {
        if(top==0)
            return 1;
        else
            return 0;
    }
};

int main()
{
    stck a,b;
    int n;
    while(1)
    {
        cin >> n;
        if(n==0)
            break;

        for(int i=n;i>0;i--)
            a.push(i);
        int i=1;
        cout << "Discarded cards:";
        while(1)
        {
            while(!a.emp())
            {
                if(i%2==1)
                {
                    if(!a.emp())
                        cout << "*";
                    cout << a.pop();
                }
                else
                    b.push(a.pop());

                i++;
            }
            int cnt=0;
            while(!b.emp())
            {
                a.push(b.pop());
                cnt++;
            }
            if(cnt==1)
            {
                cout << "\nRemaining card: "<<a.pop() << endl;
                break;
            }
        }
    }
}

