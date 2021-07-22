#include <bits/stdc++.h>
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
void checkpalindrome(struct node*head)
{
    temp=head;
    stack<int> s;
    while(temp!=NULL)
    {
       s.push(temp->data);
       temp=temp->next;
    }
    while(head!=NULL)
    {
        int i=s.top();
        s.pop();
        if(head->data!=i)
        {
            cout<<"\nNOT a palindrome"<<endl;
            return;
        }
        head=head->next;
    }
    cout<<"\nPalindrome"<<endl;
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
    checkpalindrome(head);
}
