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

node* mergeoflist(struct node*head1, struct node*head2)
{
    struct node*result=NULL;
    if(!head1)
        return head2;
    else if(!head2)
        return head1;
    if(head1->data>=head2->data)
    {
        result=head2;
        result->next=mergeoflist(head1,head2->next);
    }
    else
    {
        result=head1;
        result->next=mergeoflist(head1->next,head2);
    }
    return result;
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
    cout<<"\nMerge of two linked lists: ";
    struct node* result=mergeoflist(head1,head2);
    temp=result;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
