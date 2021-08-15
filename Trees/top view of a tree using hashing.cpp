#include <iostream>
#include <map>
using namespace std;

struct node
{
    int data;
    struct node* left=NULL;
    struct node* right=NULL;
}*root=NULL;

node* insertnode(int ele)
{
        node * newnode=new node();
        newnode->data=ele;
        newnode->left=newnode->right=NULL;
        return newnode;
}

void print(node* root, int dist, int level,map<int, pair<int, int> >& mp)
{
    if(root==NULL)
        return;
    if(mp.find(dist)== mp.end() ||level < mp[dist].second)
    {
        mp[dist]={root->data, level};
    }
    print(root->left,dist-1,level+1,mp);
    print(root->right,dist+1,level+1,mp);
}
void printbottom(node* root)
{
    map<int, pair<int, int> > mp;
    print(root,0,0,mp);
    map<int, pair<int, int> > :: iterator it;
    for(it=mp.begin(); it!=mp.end();it++)
    {
        cout<<it->second.first<<" ";
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
    printbottom(root);
}
