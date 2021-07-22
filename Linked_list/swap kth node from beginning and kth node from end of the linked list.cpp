#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node*next;
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
void SwapK(struct node*head,int k)
{
    int countt=0;
    temp=head;
    while(temp)
    {
        countt++;
        temp=temp->next;
    }
    if(countt<k)
        return;
    if(2*k-1==countt)
        return;
    node* x=head;
    node* Xprev=NULL;
    for(int i=1;i<k;i++)
    {
        Xprev=x;
        x=x->next;
    }
    node* y=head;
    node* Yprev=NULL;
    for(int i=1;i<countt-k+1;i++)
    {
        Yprev=y;
        y=y->next;
    }
    if(Xprev)
        Xprev->next=y;
    if(Yprev)
        Yprev->next=x;
    temp=y->next;
    y->next=x->next;
    x->next=temp;
    if(k==1)
        head=y;
    if(k==countt)
        head=x;

}
void print(struct node*head)
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    int n,k;
    cout<<"Enter the no. of nodes in the list"<<endl;
    cin>>n;
    cout<<"Enter the elements in the list"<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele);
    }
    cout<<"Enter the kth node: ";
    cin>>k;
    SwapK(head,k);
    print(head);
}
