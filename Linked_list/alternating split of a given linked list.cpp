#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node*next;
}*head=NULL,*temp=NULL;
void insertnode(int ele)
{
    node* newnode=new node();
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

void alternatingSplit(struct node* a, struct node* b)
{
    if(a==NULL || b==NULL)
        return;
    if(a->next)
        a->next=a->next->next;
    if(b->next)
        b->next=b->next->next;
    alternatingSplit(a->next,b->next);
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
    int n;
    cout<<"Enter the no. of nodes in a linked list:\n";
    cin>>n;
    cout<<"Enter the elements of linkedlist: \n";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele);
    }
    struct node *a=head,*b=head->next;
    alternatingSplit(a,b);
    printList(a);
    cout<<endl;
    printList(b);
}
