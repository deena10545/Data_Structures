#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node*next;
}*head=NULL,*temp=NULL;
void mergesplit(node*temp,node**a,node**b);
void MergeSort(node** head);
node* SortedMerge(node*a, node*b);
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
void MergeSort(struct node**head)
{
    node* temp= *head;
    node* a;
    node* b;
    if(temp==NULL || temp->next==NULL)
        return;
    mergesplit(temp,&a,&b);
    MergeSort(&a);
    MergeSort(&b);
    *head=SortedMerge(a,b);
}
node* SortedMerge(node* a, node* b)
{
    node* result=NULL;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->data<=b->data)
    {
        result=a;
        result->next=SortedMerge(a->next,b);
    }
    else
    {
        result=b;
        result->next=SortedMerge(a,b->next);
    }
    return result;
}
void mergesplit(node* temp, node** frontt, node** backk)
{
    node* fast;
    node* slow;
    slow=temp;
    fast=temp->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
        *frontt=temp;
        *backk=slow->next;
        slow->next=NULL;
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
    MergeSort(&head);
    print(head);
}
