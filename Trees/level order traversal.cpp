#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left=NULL;
    struct node* right=NULL;
}*root=NULL;
node* insertnode(struct node* root, int ele)
{
    if(root==NULL)
    {
        node* newnode=new node();
        newnode->data=ele;
        root=newnode;
        return root;
    }
    else
    {
        if(ele<root->data)
            root->left=insertnode(root->left,ele);
        else if(ele>root->data)
            root->right=insertnode(root->right,ele);
    }
    return root;
}
void levelorder(node* root)
{
    if(!root)
        return;
    queue<node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}
int main()
{
    root=insertnode(root,10);
    insertnode(root,8);
    insertnode(root,15);
    insertnode(root,9);
    insertnode(root,20);
    insertnode(root,14);
    insertnode(root,7);
    levelorder(root);
}
