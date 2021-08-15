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
void rightview(node* root)
{
    if(!root)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        int t=n-1;
        while(n--)
        {
            node*temp=q.front();
            q.pop();
            if(n==t)
                cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
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
    insertnode(root,6);
    insertnode(root,22);
    rightview(root);
}
