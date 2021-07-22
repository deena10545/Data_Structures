#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
}*head=NULL,*temp=NULL;
void insertnode(int ele)
{
    node* newnode=new node();
    if(head==NULL)
    {
        newnode->data=ele;
        newnode->next=newnode;
        head=newnode;
    }
    else
    {
        newnode->data=ele;
        temp=head;
        do
        {
            temp=temp->next;
        }while(temp->next!=head);
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
    }
}
void detectloop(struct node* head);
void removeloop(struct node*loop)
{
    struct node * ptr1=head,*ptr2=loop;
    while(1)
    {
        while(ptr2->next!=loop && ptr2->next!=ptr1)
        {
            ptr2=ptr2->next;
        }
        if(ptr2->next==ptr1)
            break;
        ptr1=ptr1->next;
    }
    ptr2->next=NULL;
    cout<<"LOOP removed";
}
void detectloop(struct node*head)
{
    struct node * slwptr=head, *fstptr=head;
    while(slwptr && fstptr && fstptr->next)
    {
        slwptr=slwptr->next;
        fstptr=fstptr->next->next;
        if(slwptr==fstptr)
            {
                cout<<"LOOP Found"<<endl;
                cout<<"Removing loop"<<endl;
                removeloop(slwptr);
                return;
            }
    }
    cout<<"LOOP NOT FOUND";
}

int main()
{
    int n;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele);
    }
    detectloop(head);
}
