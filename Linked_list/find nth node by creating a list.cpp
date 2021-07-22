#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
};

class Slist
{
public:
    node *head;
    Slist()
    {
        head=NULL;
    }
    void insertnode(int ele)
    {

        node *newnode= new node;
        newnode->data=ele;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    void display()
    {
        node*temp=NULL;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
            if(temp!=NULL)
                cout<<"-->";
        }
    }
    node *getNthnode( int n)
    {
        node *ptr1=head;
        node *ptr2=head;
        for(int i=0;i<n-1;i++)
        {
            ptr1=ptr1->next;
        }
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr2;
    }
};
int main()
{
    Slist s;
    int n,ele,Nth;
    node *Nthnode;
    cout<<"Enter the number of nodes in the list"<<endl;
    cin>>n;
    cout<<"Enter the elements in the list"<<endl;
    int count=0;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        s.insertnode(ele);
        count++;
    }
    s.display();
    cout<<endl<<"Nthnode from the end of the linkedlist"<<endl;
    cin>>Nth;
    if(count<Nth)
    {
        cout<<"Fewer nodes"<<endl;
    }
    else
    {
        Nthnode=s.getNthnode(Nth);
        cout<<"Nthnode from the end of the linked list is: "<<Nthnode->data;
    }
}
