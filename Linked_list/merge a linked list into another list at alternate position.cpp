#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*next;
}*head=NULL,*head1=NULL,*temp=NULL;

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
void printList(struct node* head);
void MergeList(struct node* head, struct node* head1)
{
    if(head==NULL || head1==NULL)
        return;
    temp=head;
    node* temp1=head1;
    int countt=0;
    while(temp)
    {
        countt++;
        temp=temp->next;
    }
     node* ptr;
    node* ptr1;
    temp=head;
    int i=0;
    while(temp!=NULL && temp1!=NULL && i<countt)
    {
        ptr=temp->next;
        ptr1=temp1->next;
        node* s=temp1;
        temp->next=s;
        s->next=ptr;
        temp=ptr;
        temp1=ptr1;
        i++;
    }
    head1=temp1;
    printList(head);
    printList(head1);
}
void printList(struct node* head)
{
    cout<<endl;
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
    MergeList(head,head1);

}
