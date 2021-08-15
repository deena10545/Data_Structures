#include <iostream>

using namespace std;
class treenode
{
public:
    int data;
    treenode *left;
    treenode *right;
    treenode(int v=0)
    {
        data=v;
        left=NULL;
        right=NULL;
    }
};
class BST
{
public:
    treenode *root=NULL;
    bool isempty()
    {
        if(root==NULL)
            return true;
        else
            return false;
    }
    void insertnode(treenode * newnode)
    {
    	if(root==NULL)
    	{
    		root=newnode;
    		return;
		}
		else
		{
			treenode * temp =root;
			while(temp!=NULL)
			{
				if(temp->data==newnode->data)
					return;
				else if(temp->data>newnode->data && temp->left==NULL)
				{
						temp->left=newnode;
						break;
				}
				else if(temp->data>newnode->data)
				{
					temp=temp->left;
				}	
				else if(temp->data<newnode->data && temp->right==NULL)
				{
					temp->right=newnode;
					break;
				}
				else
					temp=temp->right;
			}
		}
	}
	treenode* searchnode(int val)
	{
		if(root==NULL)
			return root;
		else
		{
			treenode * temp=root;
			while(temp!=NULL)
			{
				if(temp->data==val)
					return temp;
				else if(temp->data>val)
					temp=temp->left;
				else
					temp=temp->right;
			}
		}
	}
	void preorder(treenode* root)
	{
		if(root)
		{
			cout<<root->data<<" ";
			preorder(root->left);
			preorder(root->right);
		}
	}
	int height(treenode *root)
	{
		if(root==NULL)
			return -1;
		else
		{
			int lheight=height(root->left);
			int rheight=height(root->right);
			if(lheight>rheight)
				return (lheight+1);
			else
				return (rheight+1);
		}
	}
	void printlevel(treenode *root, int level)
	{
		if(root==NULL)
			return;
		else if(level==0)
			cout<<root->data<<" ";
		else
		{
			printlevel(root->left,level-1);
			printlevel(root->right,level-1);
		}
	}
	treenode* deletenode(treenode*root, int value)
	{
		treenode* temp;
		if(root==NULL)
			return root;
		 if(value<root->data)
			root->left=deletenode(root->left,value);
		else if(value>root->data)
			root->right=deletenode(root->right,value);
		else
		{
			if(root->left==NULL)
			{
				temp=root->right;
				delete root;
				return temp;
			}
			else if(root->right==NULL)
			{
				temp=root->left;
				delete root;
				return temp;
			}
			else
			{
				temp=minRight(root->right);
				root->data=temp->data;
				root->right=deletenode(root->right, temp->data);
			}
		}
		return root;
	}
	treenode* minRight(treenode* node)
	{
		treenode* current=node;
		while(current->left!=NULL)
		{
			current=current->left;
		}
		return current;
	}
};
int main()
{
    int option,val,k;
	BST t;
    while(1)
    {
        cout<<"\nEnter the operation to perform:";
        cout<<"\n1.insertion\n2.searching\n3.delete node\n4.print\n5.height\n6.BST\n7.exit\n";
        cout<<"Enter your choice: ";
        cin>>option;
        treenode* newnode= new treenode();
        switch(option)
        {
        case 1:
        	cout<<"Enter the value: ";
        	cin>>val;
        	newnode->data=val;
        	t.insertnode(newnode);
            break;
        case 2:
        	cout<<"Enter the value to search";
        	cin>>val;
        	treenode* search;
        	search = t.searchnode(val);
        	if(search!=NULL)
        		cout<<"The element is found";
        	else
        		cout<<"The element is not found";
            break;
        case 3:
        	cout<<"Enter the node to be deleted";
        	cin>>val;
        	treenode* dlt;
        	dlt=t.deletenode(t.root,val);
        	if(!dlt)
        	cout<<"Node is not in the tree";
        	else
        	cout<<"Node is deleted";
        case 4:
        	t.preorder(t.root);
            break;
        case 5:
        	cout<<"The height of the tree is "<<t.height(t.root)<<endl; 
        	break;
        case 6:
        	cout<<"BST of the tree is\n";
        	k=t.height(t.root);
        	for(int i=0;i<=k;i++)
        		t.printlevel(t.root,i);
        case 7:
            exit(1);
        default:
            cout<<"Enter the valid choice";
        }
    }
}
