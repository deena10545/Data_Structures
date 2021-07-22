#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
}*head=NULL,*temp=NULL;

void insertnode(int ele)
{
    node *newnode=new node();
    if(head==NULL)
    {
        newnode->data=ele;
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->data=ele;
        newnode->next=NULL;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void reversenode(struct node *head)
{
    struct node *current=NULL, *prev=NULL, *nextnode=NULL;
    current=head;
    while(current)
    {
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    head=prev;
    temp=head;
    while(temp)
    {
        cout<<temp->data;
        temp=temp->next;
        if(temp!=NULL)
            cout<<"-->";
    }

}
int main()
{
    int n;
    cout<<"Enter the no. of nodes in the list"<<endl;
    cin>>n;
    cout<<"Enter the elements in the list"<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele);
    }
    reversenode(head);
}
