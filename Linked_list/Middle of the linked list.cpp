#include <bits/stdc++.h>
#include <cmath>
using namespace std;
struct node
{
    int data;
    struct node *next;
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
void Middle_ele(struct node*head,int mid)  //use two pointers slowptr and fast ptr...
{
    temp=head;
    int i=1;
    while(i<mid)
    {
        temp=temp->next;
        i++;
    }
    cout<<"\nThe middle of a linked list: "<<temp->data;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele);
    }
    temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    float x=(float)n/2;
    int mid=ceil(x);
    Middle_ele(head,mid);
}
