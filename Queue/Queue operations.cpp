#include <iostream>

using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    int *arr;
public:
    Queue(int s)
    {
        size=s;
        front=rear=-1;
        arr=new int[s];
    }
    void enqueue(int x);
    int dequeue();
    bool isempty();
    bool isfull();
    void display();
    int count()
    {
        return(rear-front+1);
    }
};
bool Queue :: isempty()
{
  if( front==-1 && rear ==-1)
        return true;
  else
    return false;
}
bool Queue :: isfull()
{
    if(rear==size -1)
        return true;
    else
        return false;
}
void Queue :: enqueue(int x)
{
    if(isfull())
    {
        cout<<"Queue is full"<<endl;
    }
    else if(isempty()){
        rear=front=0;
        arr[rear]=x;}
    else{
        rear++;
        arr[rear]=x;}
}
int Queue :: dequeue()
{
    int x;
    if(isempty())
    {
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    else if(rear==front)
    {
        x=arr[front];
        front=rear=-1;
    }
    else
    {
        x=arr[front];
        front++;
    }
    return x;
}
void Queue :: display()
{
    for(int i=front;i<=rear;i++)
        cout<<arr[i]<<endl;
}
int main()
{
    Queue q(3);
    int options, value;
    while(1)
    {
        cout<<"QUEUE OPERATIONS\n";
        cout<<" 1.isempty\n 2.isfull\n 3.enqueue\n 4.dequeue\n 5.count\n 6.display\n 7.exit\n";
        cout<<"Enter your choice:";
        cin>>options;
        switch(options)
        {
        case 1:
            {
                if(q.isempty())
                    cout<<"Queue is empty\n";
                else
                    cout<<"Queue is not empty\n";
                break;
            }
        case 2:
            {
                if(q.isfull())
                    cout<<"Queue is full\n";
                else
                    cout<<"Queue is not full\n";
                break;
            }
        case 3:
            {
                cout<<"enter the value to be inserted"<<endl;
                cin>>value;
                q.enqueue(value);
                break;
            }
        case 4:
            {
                if(q.isempty())
                    cout<<"Queue is empty\n";
                else
                    cout<<"The deleted element is:"<<q.dequeue()<<endl;
                break;
            }
        case 5:
            {
                cout<<"The count is"<<q.count();
                break;
            }
        case 6:
            {
                q.display();
                break;
            }
        case 7:
            exit(1);
        default:
            {
            cout<<"Enter the valid choice";
            }
        }
    }
}
