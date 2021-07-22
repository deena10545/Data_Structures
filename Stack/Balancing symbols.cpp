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
    void pop();
    int topp();
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
void stack<T> :: pop()
{
    if(isempty())
    {
        cout<<"stack underflow"<<endl;
    }
    else
    {
        int popvalue= arr[top];
        top--;
        //return popvalue;
    }
}
int main()
{
    stack<char> s(50);
    char a[50];
    cin>>a;
    char x;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='{' || a[i]=='(' || a[i]=='[')
            {
                s.push(a[i]);
                continue;
            }
        else if(a[i]=='}'|| a[i]==')' ||a[i]==']')
        {
            if(a[i]==')')
            {
                if(s.topp()=='(')
                    s.pop();
                else
                {
                    //cout<<"Unbalanced expression..."<<endl;
                    break;
                }
            }
            if(a[i]==']')
            {
                if(s.topp()=='[')
                   s.pop();
                else
                {
                    //cout<<"Unbalanced expression..."<<endl;
                    break;
                }
            }
            if(a[i]=='}')
            {
                if(s.topp()=='{')
                    s.pop();
                else
                {
                   // cout<<"Unbalanced expression..."<<endl;
                    break;
                }
            }
        }
    }
    if(s.isempty())
            cout<<"Balanced expression"<<endl;
    else
        cout<<"unbalanced expression"<<endl;
}

