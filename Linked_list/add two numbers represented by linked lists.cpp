#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*next;
}*head=NULL,*head1=NULL,*temp=NULL;
node* newnode(int data)
{
    node*x=new node();
    x->data=data;
    return x;
}
void insertnode(int ele,struct node**head)
{
    node* newnode=new node();
    if(*head==NULL)
    {
        newnode->data=ele;
        newnode->next=NULL;
        *head=newnode;
    }
    else
    {
        newnode->data=ele;
        newnode->next=NULL;
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

node* addTwo(struct node* head, struct node* head1)
{
    stack<node*> s1,s2,s3;
    temp=head;
    while(temp!=NULL)
    {
        s1.push(temp);
        temp=temp->next;
    }
    struct node* temp1=head1;
    while(temp1!=NULL)
    {
        s2.push(temp1);
        temp1=temp1->next;
    }

    int carry=0;
    while(!s1.empty() && !s2.empty())
    {
        int sum=s1.top()->data+s2.top()->data+carry;
         node* temp2= newnode(sum%10);
        s3.push(temp2);
        if(sum>9)
            carry=1;
        else
            carry=0;
        s1.pop();
        s2.pop();
    }
    while(!s1.empty())
    {
        int sum=s1.top()->data+carry;
        struct node*temp2=newnode(sum%10);
        s3.push(temp2);
        if(sum>9)
            carry=1;
        else
            carry=0;
        s1.pop();
    }
    while(!s2.empty())
    {
        int sum=s2.top()->data+carry;
        struct node*temp2=newnode(sum%10);
        s3.push(temp2);
        if(sum>9)
            carry=1;
        else
            carry=0;
        s2.pop();
    }
    if(carry==1)
     {
        struct node*temp2=newnode(1);
        s3.push(temp2);
     }
     struct node* prev=NULL;
     if(!s3.empty())
        prev=s3.top();
     while(!s3.empty())
     {
         temp=s3.top();
         s3.pop();
         if(s3.size()==0)
            temp->next=NULL;
         else
            temp->next=s3.top();
     }
     return prev;
}
void printList(struct node* head)
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        if(temp->next!=NULL)
            cout<<"-->";
        temp=temp->next;
    }
}

int main()
{
    int n,m;
    cout<<"Enter the no. of nodes in a linked list1 and list2:\n";
    cin>>n>>m;
    cout<<"Enter the elements of list1: \n";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele,&head);
    }
    cout<<"Enter the elements of list2: \n";
    for(int i=0;i<m;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele,&head1);
    }
    printList(head);
    cout<<endl;
    printList(head1);
    node* list3=addTwo(head,head1);
    cout<<endl;
    printList(list3);

}
