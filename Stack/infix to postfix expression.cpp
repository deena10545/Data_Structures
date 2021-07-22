#include <iostream>
#include <string.h>
using namespace std;

template<class T>
class stack
{
    int top;
    T *arr;
    int size;
public:
    stack(int s)
    {
        size=s;
        top=-1;
        arr=new T[size];
    }
    bool isempty();
    bool isfull();
    void push(T x);
    T pop();
    int topp();
    void display();
};
template<class T>
int stack<T> :: topp()
{
    return arr[top];
}
template<class T>
bool stack<T> :: isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}
template<class T>
bool stack<T> :: isfull()
{
    if(top==size-1)
        return true;
    else
        return false;
}
template<class T>
void stack<T> :: push(T x)
{
    if(isfull())
        cout<<"stack overflow"<<endl;
    else
        {
            top++;
            arr[top]=x;
        }
}
template<class T>
T stack<T> :: pop()
{
    if(isempty())
    {
        cout<<"stack underflow"<<endl;
    }
    else
    {
        int popvalue= arr[top];
        top--;
        return popvalue;
    }
}
template <class T>
void stack<T> :: display()
{
    pop();
    for(int i=top;i>=0;i--)
    {
        if(arr[i]=='('|| arr[i]=='{' || arr[i]=='[')
        {
            top--;
            break;
        }
        else
            cout<<pop();
    }
}
int main()
{
    stack<char> s(20);
    char a[20];
    cin>>a;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]>='a' && a[i]<='z' || a[i]>=48 && a[i]<=57)
            cout<<a[i];
        else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
        {
            if(s.isempty())
                s.push(a[i]);
            else if(a[i]=='*' || a[i]=='/')
            {
                if(s.topp()=='(' || s.topp()=='[' || s.topp()=='{')
                    s.push(a[i]);
                else if(s.topp()=='-' || s.topp()=='+')
                    s.push(a[i]);
                else
                {
                    cout<<s.pop();
                    s.push(a[i]);
                }
            }
            else if(a[i]=='+' || a[i]=='-')
            {
                 if(s.topp()=='(' || s.topp()=='[' || s.topp()=='{')
                    s.push(a[i]);
                else if(s.topp()=='*' || s.topp()=='/')
                    {
                        cout<<s.pop();
                        s.push(a[i]);
                    }
                else
                {
                    cout<<s.pop();
                    s.push(a[i]);
                }
            }
        }
        else if(a[i]=='(' || a[i]=='{' || a[i]=='[')
             {
                 s.push(a[i]);
             }
        else if(a[i]==')' || a[i]=='}' || a[i]==']')
            {
                s.push(a[i]);
                s.display();
            }
    }
    if(!s.isempty())
        cout<<s.pop();

}
