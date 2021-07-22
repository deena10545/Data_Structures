#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node* next;
}*top;
void push(int ele)
{
    node* newnode;
    newnode=new node();
    if(!newnode)
        return;
    newnode->data=ele;
    newnode->next=top;
    top=newnode;
}
void pop()
{
    node*temp;
    if(top==NULL)
    {
        cout<<"stack underflow";
        return;
    }
    temp=top;
    top=top->next;
    temp->next=NULL;
    delete(temp);

}
void display()
{
    node* temp;
    if(top==NULL)
    {
        cout<<"Stack underflow";
        return;
    }
    temp=top;
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
        push(ele);
    }
    display();
    pop();
    pop();
    display();

}
