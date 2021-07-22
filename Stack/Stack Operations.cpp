#include <iostream>

using namespace std;

class stack
{
    int top;
    int *arr;
    int size;
public:
    stack(int s)
    {
        size=s;
        top=-1;
        arr=new int[size];
    }
    bool isempty();
    bool isfull();
    void push(int x);
    int pop();
    int count();
    void change(int x,int y);
    int peek(int x);
    void display();
};

bool stack :: isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}
bool stack :: isfull()
{
    if(top==size-1)
        return true;
    else
        return false;
}
void stack :: push(int x)
{
    if(isfull())
        cout<<"stack overflow"<<endl;
    else
        {
            top++;
            arr[top]=x;
        }
}
int stack :: pop()
{
    if(isempty())
    {
        cout<<"stack underflow"<<endl;
        return 0;
    }
    else
    {
        int popvalue= arr[top];
        top--;
        return popvalue;
    }
}
int stack :: count()
{
    return (top+1);
}

int stack :: peek(int pos)
{
    if(isempty())
    {
        cout<<"stack underflow"<<endl;
        return 0;
    }
    else
    {
        return arr[pos];
    }
}
void stack :: change(int pos, int val)
{
    arr[pos]=val;
    cout<<"The value changed in the position"<<pos<<"is"<<val<<endl;
}
void stack :: display()
{
    for(int i=top;i>=0;i--)
        cout<<arr[i]<<endl;
}
int main()
{
    stack s1(10);
    int option,position,value;
    while(1)
    {
        cout<<"STACK OPERATIONS"<<endl;
        cout<<"1.push\n 2.pop\n 3.isempty\n 4.isfull\n 5.peek\n 6.count\n 7.change\n 8.display\n 9.exit\n";
        cout<<"Enter the operation you want to do"<<endl;
        cin>>option;
        switch(option)
        {
        case 1:
            {
                cout<<"Enter a element"<<endl;
                cin>>value;
                s1.push(value);
                break;
            }
        case 2:
            {
                cout<<"Popped element is"<<s1.pop()<<endl;
                break;
            }
        case 3:
            {
                if(s1.isempty())
                    cout<<"stack is empty";
                else
                    cout<<"stack is not empty";
                break;
            }
        case 4:
            {
                 if(s1.isfull())
                    cout<<"stack is full";
                else
                    cout<<"stack is not full";
                break;
            }
        case 5:
            {
                cout<<"Enter a position"<<endl;
                cin>>position;
                cout<<"Peek is"<<s1.peek(position)<<endl;
                break;
            }
        case 6:
            {
                cout<<"count is"<<s1.count()<<endl;
                break;
            }
        case 7:
            {
                cout<<"Enter a position"<<endl;
                cin>>position;
                cout<<"Enter a value"<<endl;
                cin>>value;
                s1.change(position,value);
                break;
            }
        case 8:
            {
                s1.display();
                break;
            }
        case 9:
            exit(1);
        default:
            cout<<"enter a valid choice";
            break;
        }

    }
}
