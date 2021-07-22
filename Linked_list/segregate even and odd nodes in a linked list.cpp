#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node*next;
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
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void segregate_odd_even(struct node**head)
{
   struct node* even_start=NULL,*even_end=NULL,*odd_start=NULL,*odd_end=NULL;
   temp=*head;
   while(temp!=NULL)
   {
       if(temp->data%2==0)
       {
           if(even_start==NULL)
           {
               even_start=temp;
               even_end=even_start;
           }
           else
           {
               even_end->next=temp;
               even_end=even_end->next;
           }
       }
       else
       {
           if(odd_start==NULL)
           {
               odd_start=temp;
               odd_end=odd_start;
           }
           else
           {
               odd_end->next=temp;
               odd_end=odd_end->next;
           }
       }

        temp=temp->next;
   }

       if(even_start==NULL || odd_start==NULL)
            return;
       even_end->next=odd_start;
       odd_end->next=NULL;
       *head=even_start;
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
    segregate_odd_even(&head);
    print(head);
}
