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
void sortelements(struct node*head)
{
    int countt[3]={0,0,0};
    temp=head;
    while(temp!=NULL)
    {
        countt[temp->data]+=1;
        temp=temp->next;
    }
    int i=0;
    temp=head;
    while(temp!=NULL)
    {
        if(countt[i]==0)
            i++;
        else
        {
            temp->data=i;
            countt[i]--;
            temp=temp->next;
        }
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
    sortelements(head);
    print(head);
}
