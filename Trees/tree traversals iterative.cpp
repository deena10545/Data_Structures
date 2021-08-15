#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node* left=NULL;
    node* right=NULL;
}*root=NULL;

node* insertnode(int ele)
{
    node * newnode=new node();
    newnode->data=ele;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void inorder(node* root)
{
    stack<node* > s;
    if(root==NULL)
        return;
    node* temp=root;
    while(temp!=NULL || s.empty()==false)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
void preorder(node* root)
{
    if(root==NULL)
        return;
    stack<node* > s;
    s.push(root);
    while(s.empty()==false)
    {
        node * temp= s.top();
        cout<<temp->data<<" ";
        s.pop();
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }
}
void postorder(node* root)
{
    if(root==NULL)
        return;
    stack<int> out;
    stack<node*> s;
    s.push(root);
    while(!s.empty())
    {
        node* temp=s.top();
        s.pop();
        out.push(temp->data);
        if(temp->left)
            s.push(temp->left);
        if(temp->right)
            s.push(temp->right);
    }
    while(!out.empty())
    {
        cout<<out.top()<<" ";
        out.pop();
    }
}
int main()
{
    root=insertnode(10);
    root->left=insertnode(15);
    root->right=insertnode(20);
    root->left->right=insertnode(25);
    root->left->left=insertnode(12);
    root->right->left=insertnode(11);
    root->right->right=insertnode(32);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
}
