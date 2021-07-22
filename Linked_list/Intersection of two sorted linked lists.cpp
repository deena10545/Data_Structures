#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node*next;
}*head1=NULL,*head2=NULL,*temp=NULL;

void insertnode( struct node**head, int ele)
{
     node *newnode=new node();
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
            temp=temp->next;
        temp->next=newnode;
    }
}
//brutce force method...
/*void intersection(struct node*head1,struct node*head2)
{
    struct node*temp1=head1,*temp2=head2;
    int flag=0;
    while(temp1)
    {
        temp2=head2;
        while(temp2)
        {
            if(temp1->data==temp2->data)
            {
                cout<<temp1->data<<" ";
                flag=1;
            }
                temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    if(flag==0)
        cout<<"No nodes are intersect..";
}   */

void intersect(struct node*head1, struct node*head2)
{
    struct node*temp1=head1,*temp2=head2;
    int flag=0;
    while(temp1!=NULL && temp2!=NULL )
    {
        if(temp1->data ==temp2->data)
        {
            cout<<temp1->data<<" ";
            flag=1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->data>temp2->data)
            temp2=temp2->next;
        else
            temp1=temp1->next;
    }
     if(flag==0)
        cout<<"No nodes are intersect..";
}
void sortt(struct node*head)
{
    int i,j,a;
    struct node*ptr;
    struct node*ptr1;
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        for(ptr1=ptr->next;ptr1!=NULL;ptr1=ptr1->next)
        {

            if(ptr->data>ptr1->data)
            {
                a=ptr->data;
                ptr->data=ptr1->data;
                ptr1->data=a;
            }
        }
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
        insertnode(&head1,ele);
    }
    cout<<"Enter list2 elements: ";
    for(int i=0;i<m;i++)
    {
        int ele;
        cin>>ele;
        insertnode(&head2,ele);
    }
    sortt(head1);
    sortt(head2);
    cout<<"\nList one elements: ";
     temp=head1;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\nList two elements: ";
    temp=head2;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\nIntersection of two linked lists: ";
    intersect(head1,head2);
}
