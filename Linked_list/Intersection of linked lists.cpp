#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node*next;
}*head1=NULL,*head2=NULL,*temp=NULL;
void insertnode(int ele)
{
    node *newnode=new node();
    if(head1==NULL)
    {
        newnode->data=ele;
        newnode->next=NULL;
        head1=newnode;
    }
    else
    {
        newnode->data=ele;
        newnode->next=NULL;
        temp=head1;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}
void intersection(int n, int m)
{
    struct node* ptr1=head1,*ptr2=head2;
    int d;
    if(n<m)
    {
        d=m-n;
        for(int i=0;i<d;i++)
        {
            if(ptr2==NULL)
                return;
            ptr2=ptr2->next;
        }
    }
    else
    {
        d=n-m;
        for(int i=0;i<d;i++)
        {
            if(ptr1==NULL)
                return;
            ptr1=ptr1->next;
        }
    }
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
          {
              cout<<ptr1->data<<" ";
              return;
          }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    cout<<"NO intersection nodes";
}
void insertnode1(int ele)
{
    node *newnode=new node();
    if(head2==NULL)
    {
        newnode->data=ele;
        newnode->next=NULL;
        head2=newnode;
    }
    else
    {
        newnode->data=ele;
        newnode->next=NULL;
        temp=head2;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}
int main()
{
    int n,m;
    cout<<"Enter the no. of nodes in the list1 and list2: ";
    cin>>n>>m;
    cout<<"Enter list1 elements: ";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele);
    }
    cout<<"Enter list2 elements: ";
    for(int i=0;i<m;i++)
    {
        int ele;
        cin>>ele;
        insertnode1(ele);
    }
   // head2->next->next=head1->next->next;

    int count1=0,count2=0;
    temp=head2;
    while(temp!=NULL)
    {
        count2++;
        temp=temp->next;
    }
    temp=head1;
    while(temp!=NULL)
    {
        count1++;
        temp=temp->next;
    }
    intersection(count1,count2);
}
