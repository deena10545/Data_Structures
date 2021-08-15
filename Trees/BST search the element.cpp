#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left=NULL;
	node *right=NULL;
}*root=NULL;
node * insert(node* root,int data)
{
	if(root==NULL)
	{
		node *newnode=new node();
		newnode->data=data;
		root=newnode;
		return root;
	}
	if(root->data>data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}
void inorder(node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
node* search(struct node* root, int key)
{
    if (root == NULL || root->data == key)
       return root;
    if (root->data < key)
       return search(root->right, key);
    return search(root->left, key);
}
int main()
{
	int ele;

	root=insert(root,10);
	insert(root,20);
	insert(root,30);
	insert(root,40);
	insert(root,50);
	insert(root,60);
	inorder(root);
		cin>>ele;
	node *temp=search(root,ele);
	
	if(temp==NULL)
		cout<<"Element is not found:";
	else
		cout<<"Element is found";
}
