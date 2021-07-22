#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node*next;
}*head=NULL,*temp=NULL,*a=NULL,*b=NULL;
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

void MultipleTwo(struct node* a, struct node* b)
{
    long long num1=0,num2=0;
    while(a||b){
    if(a)
    {
        num1=(num1*10)+a->data;
        a=a->next;

        cout<<endl<<num1;
    }
    if(b)
    {
        num2=(num2*10)+b->data;
        b=b->next;
        cout<<endl<<num2;
    }
    }
    long long res = num1*num2;
    cout<<endl<<"The product of two Linked lists is "<<res;
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
    cout<<"Enter the no. of nodes in a linked list:\n";
    cin>>n>>m;
    cout<<"Enter the elements of linkedlist1: \n";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele,&a);
    }
     cout<<"Enter the elements of linkedlist2: \n";
    for(int i=0;i<m;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele,&b);
    }
    printList(a);
    cout<<endl;
    printList(b);
    MultipleTwo(a,b);
}
