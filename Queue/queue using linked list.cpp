#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node* next;
}*frontt=NULL,*rear=NULL;
void enqueue(int ele)
{
    node* newnode;
    newnode=new node();
    if(!newnode)
        return;
    newnode->data=ele;
    newnode->next=NULL;
    if(rear==NULL)
        frontt=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    node*temp;
    if(frontt==NULL)
    {
        return;
    }
    temp=frontt;
    frontt=frontt->next;
    temp->next=NULL;
    if(frontt==NULL)
        rear=NULL;
    delete(temp);

}
void display()
{
    node* temp;
    if(frontt==NULL)
    {
        return;
    }
    temp=frontt;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
        if(temp!=NULL)
            cout<<"-->";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the number of nodes in a list :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        enqueue(ele);
    }
    display();
    dequeue();
    dequeue();
    display();
}
