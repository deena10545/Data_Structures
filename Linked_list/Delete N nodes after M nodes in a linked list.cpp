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
void DeleteNafterM(struct node*head,int N, int M)
{
    int i;
    temp=head;
    while(temp)
    {
        for(i=1;i<M && temp!=NULL; i++)
        {
            temp=temp->next;
        }
        if(temp==NULL)
            return;
        node* t=NULL;
        t=temp->next;
        for(i=1;i<=N && t!=NULL;i++)
        {
            node* dummy=t;
            t=t->next;
            delete(t);
        }
        temp->next=t;
        temp=t;
    }
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
    int n,N,M;
    cout<<"Enter the no. of nodes in the list"<<endl;
    cin>>n;
    cout<<"Enter the elements in the list"<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele);
    }
    cout<<"Enter the n and m node: ";
    cin>>N>>M;
    DeleteNafterM(head,N,M);
    print(head);
}
