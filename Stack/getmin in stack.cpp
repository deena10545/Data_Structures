#include <bits/stdc++.h>
using namespace std;
#define maxi 100
class Stack
{
    int top;
    int arr[maxi];
public:
    Stack()
    {
        top=-1;
    }
    bool isempty();
    bool isfull();
    int pop();
    void push(int);
    int gettop()
    {
        return top;
    }
};

bool Stack :: isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}
bool Stack :: isfull()
{
    if(top== maxi-1)
        return true;
    else
        return false;
}
void Stack :: push(int x)
{
    if(isfull())
       {
           cout<<"Stack overflow"<<endl;
           abort();
       }
    else
        {
            top++;
            arr[top]=x;
        }
}
int Stack :: pop()
{
    if(isempty())
    {
        cout<<"stack underflow"<<endl;
        abort();
    }
    else
    {
        int x=arr[top];
        top--;
        return x;
    }
}

class minstack : public Stack
{
      Stack minn;
public:
    int pop();
    void push(int);
    int getmin();
};
void minstack :: push(int x)
{
    if(isempty())
    {
        Stack :: push(x);
        minn.push(x);
    }
    else
    {
        Stack :: push(x);
        int y=minn.pop();
        minn.push(y);
        if(x<=y)
            minn.push(x);
    }
}
int minstack :: pop()
{
    int x= Stack :: pop();
    int y=minn.pop();
    minn.push(y);
    if(x==y)
        minn.pop();
    return x;
}
int minstack :: getmin()
{
    int y=minn.pop();
    minn.push(y);
    return y;
}
int main()
{
    minstack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(5);
    cout<<s.getmin()<<endl;
    s.pop();
    s.pop();
    s.push(2);
    cout<<s.getmin()<<endl;
}
