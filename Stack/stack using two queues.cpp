#include <iostream>  //program error...
#include <queue>
#include <stack>

using namespace std;

void pushh(stack<int> &s)
{
    queue<int> q1,q2;
    while(!s.empty())
    {

        if(q1.empty())
        {
            q2.push(s.top());
            s.pop();
        }
        else
        {
            q1.push(s.top());
            s.pop();
        }
    }
}
int popp(stack<int> &s)
{
    queue<int> q1,q2;
    int j;
    if(!q2.empty())
    {
        j=0;
        while(j<q2.size()-1)
        {
            q1.push(q2.front());
            q2.pop();
            j++;
        }
        return (q2.front());
    }
    else
    {
        while(j<q1.size()-1)
        {
            q2.push(q1.front());
            q1.pop();
            j++;
        }
        return (q1.front());
    }
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    int m=s.size();
    pushh(s);
    for(int i=0;i<m;i++)
        cout<<popp(s)<<" ";
}
