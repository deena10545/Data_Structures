#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reversee(queue<int> &q)
{
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    reversee(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
