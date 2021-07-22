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
            temp=temp->next;
        temp->next=newnode;
    }
}
void delete_alternateNodes()
{
    if(head==NULL)
        return;
    temp=head;
    struct node*ptr=head->next;
    while(temp!=NULL &&ptr!=NULL)
    {
        temp->next=ptr->next;
        delete(ptr);
        temp=temp->next;
        if(temp!=NULL)
            ptr=temp->next;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of nodes in the list"<<endl;
    cin>>n;
    cout<<"Enter the elements in the list"<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele);
    }
    delete_alternateNodes();
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
