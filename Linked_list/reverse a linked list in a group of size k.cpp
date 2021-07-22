#include <bits/stdc++.h>

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
void ReverseByKNodes(int k)
{
    stack<node*> s;
    struct node* current=head;
    struct node*prev=NULL;
    while(current!=NULL)
    {
        int count=0;
        while(current!=NULL && count<k)
        {
            s.push(current);
            current=current->next;
            count++;
        }
        while(s.size()>0)
        {
            if(prev==NULL)
            {
                prev=s.top();
                head=prev;
                s.pop();
            }
            else
            {
                prev->next=s.top();
                prev=prev->next;
                s.pop();
            }
        }
    }
    prev->next=NULL;
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
    ReverseByKNodes(k);
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
