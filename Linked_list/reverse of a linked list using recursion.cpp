#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node* next;
}*head=NULL,*temp=NULL,*current=NULL;

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
void reversenode(struct node*head)
{
    struct node*first=head;
    struct node*rest=head->next;
        if(first==NULL || rest==NULL)
            {
                current=first;
                return;
            }
        reversenode(rest);
        rest->next=first;
        first->next=NULL;
       //cout<<"HII";
        //return rest;

}
void print( )
{
    temp=current;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp!=NULL)
            cout<<"-->";
    }
}
int main()
{
    int n;
    cout<<"Enter the number of nodes in the linked list"<<endl;
    cin>>n;
    cout<<"Enter the elements";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele);
    }
    reversenode(head);
    print( );
}
