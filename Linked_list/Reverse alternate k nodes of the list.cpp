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
node* reverseAltKnode(struct node *head,int k)
{
    struct node *current=NULL, *prev=NULL, *nextnode=NULL;
    current=head;
    int count=0;
    while(current!=NULL && count<k)
    {
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
        count++;
    }
    if(head!=NULL)
        head->next=current;
    count=0;
    while(count<k-1 && current!=NULL)
    {
        current=current->next;
        count++;
    }
    if(current!=NULL)
        current->next=reverseAltKnode(current->next,k);
    return prev;
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
    int k;
    cout<<"Enter k value";
    cin>>k;
    head=reverseAltKnode(head,k);
    temp=head;
    while(temp)
    {
        cout<<temp->data;
        temp=temp->next;
        if(temp!=NULL)
            cout<<"-->";
    }
}
