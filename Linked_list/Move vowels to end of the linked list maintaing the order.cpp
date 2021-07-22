#include <iostream>   //maintaining order is not done.....
using namespace std;

struct node
{
    char data;
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
void moveVowels(struct node*head)
{
    if(head==NULL)
        return;
    int count=0;
    struct node*headnode=NULL,*pnode=NULL;
    struct node * lastnode=head;
    while(lastnode->next!=NULL)
    {
        count++;
        lastnode=lastnode->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(count<0)
            break;
        count--;
        bool isvowel=false;
        switch(temp->data)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': isvowel=true;
                    break;
        default:
            isvowel=false;
            break;
        }
        if(isvowel)
        {
            if(pnode==NULL)
            {
                lastnode->next=temp;
                temp=temp->next;
                lastnode=lastnode->next;
                lastnode->next=NULL;
            }
            else
            {
                pnode->next=temp->next;
                lastnode->next=temp;
                lastnode=lastnode->next;
                lastnode->next=NULL;
                temp=pnode->next;
            }
        }
        else
        {
            if(headnode==NULL)
                headnode=temp;
            pnode=temp;
            temp=temp->next;
        }
    }
    head=headnode;
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
        char ele;
        cin>>ele;
        insertnode(ele);
    }
    moveVowels(head);
    print(head);
}
