#include <iostream>
#include <map>
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
void print(node* root, int level, map<int, int> &mp)
{
    if(root==NULL)
        return;

        mp[level]=root->data;
    print(root->left,level+1,mp);
    print(root->right,level+1,mp);
}
void printleft(node* root)
{
    map<int, int> mp;
    print(root,1,mp);
    map<int, int> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->second<<" ";
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
    printleft(root);
}
