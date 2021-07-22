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
void RotateByKNodes(int k)
{
    if(k==0)
        return;
    temp=head;
    int count=1;
    while(temp!=NULL && count<k)
    {
        temp=temp->next;
        count++;
    }
    if(temp==NULL)
        return;
    struct node*ptr=temp;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head;
    head=ptr->next;
    ptr->next=NULL;

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
    int k;
    cout<<"Enter the k Nodes";
    cin>>k;
    RotateByKNodes(k);
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
