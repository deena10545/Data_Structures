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
int main()
{
    stack<int> s(20);
    char a[20];
    cin>>a;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            int temp=a[i]-'0';
            s.push(temp);
        }
        else
        {
            int val1=s.pop();
            int val2=s.pop();
            if(a[i]=='*')
            {
                s.push(val2*val1);
            }
            else if(a[i]=='-')
            {
                s.push(val2-val1);
            }
            else if(a[i]=='+')
            {
                s.push(val2+val1);
            }
            else if(a[i]=='/')
            {
                s.push(val2/val1);
            }
        }
    }
    cout<<s.topp();
    s.pop();
}
