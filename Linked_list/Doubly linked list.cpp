#include <iostream>

using namespace std;

class node
{
public:
    int data;
    int key;
    node *next;
    node *prev;
    node(int k=0 , int d=0)
    {
        key=k;
        data=k;
        next=NULL;
        prev=NULL;
    }
};
class doublylinkedlist
{
public:
    node *head;
    doublylinkedlist()
    {
        head=NULL;
    }
    doublylinkedlist(node *n)
    {
        head=n;
    }
    //check if node exists using key value
    node* checkNode(int k)
    {
        node *temp=NULL;
        node *ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->key==k)
                temp=ptr;
            ptr=ptr->next;
        }
        return temp;
    }
    //Insertlast
    void insertlast(node *n)
    {
        if(checkNode(n->key)!=NULL)
        {
            cout<<"Node is already exists";
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"APPENDED"<<endl;
            }
            else
            {
                node * ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->prev=ptr;
                cout<<"Node appended"<<endl;
            }
        }
    }
    //insertfirst
    void insertfirst(node *n)
    {
         if(checkNode(n->key)!=NULL)
        {
            cout<<"Node is already exists";
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Inserted"<<endl;
            }
            else
            {
                head->prev=n;
                n->next=head;
                head=n;
                cout<<"Node inserted"<<endl;
            }
        }
    }
    //insert a node after a particular node in a list
    void insertmiddle(int k, node *n)
    {
        node *ptr=checkNode(k);
        if(ptr==NULL)
        {
            cout<<"No node exists with key value: "<<k<<endl;
        }
        else
        {
            if(checkNode(n->key)!=NULL)
            {
                cout<<"Node with key value already exists"<<endl;
            }
            else
            {
                node *nextnode = ptr->next;
                if(nextnode==NULL)
                {
                    ptr->next=n;
                    n->prev=ptr;
                    cout<<"Node inserted"<<endl;
                }
                else
                {
                    n->next=nextnode;
                    nextnode->prev=n;
                    n->prev=ptr;
                    ptr->next=n;
                    cout<<"Node inserted"<<endl;
                }
            }
        }
    }
    //delete node by key
    void deletenode(int k)
    {
        node *ptr=checkNode(k);
        if(ptr==NULL)
        {
            cout<<"No node exists with the key value"<<endl;
        }
        else
        {
            if(head->key==k)
            {
                head=head->next;
                cout<<"Node is unlinked"<<endl;
            }
            else
            {
                node *nextnode =ptr->next;
                node *prevnode =ptr->prev;
                if(nextnode==NULL)
                {
                    prevnode->next=NULL;
                    cout<<"Node is unlinked"<<endl;
                }
                else
                {
                    prevnode->next=nextnode;
                    nextnode->prev=prevnode;
                    cout<<"Node is unlinked"<<endl;
                }
            }
        }
    }
    //update node
    void update(int k, int d)
    {
        node *ptr=checkNode(k);
        if(ptr!=NULL)
        {
            ptr->data=d;
            cout<<"Updated"<<endl;
        }
        else
        {
            cout<<"Node doesn't exist with the key value: "<<k<<endl;
        }
    }
       //printing the list
    void printlist()
    {
        if(head==NULL)
        {
            cout<<"List doesn't exist"<<endl;
        }
        else
        {
            cout<<endl<<"Doubly linked list: ";
            node *temp=head;
            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<")-->";
                temp=temp->next;
            }
        }
    }
};
int main()
{
    doublylinkedlist d;
    int option;
    int key1,k1,data1;
    while(1)
    {
        cout<<"What operation do you like to perform"<<endl;
        cout<<"\n 1.Insertlast\n 2.Insertfirst\n 3.Insertmiddle\n 4.Deletebykey\n 5.Update\n 6.Print\n 7.Exit\n";
        cin>>option;
        node *n1 =new node();
        switch(option)
        {
        case 1:
            {
                cout<<"Insertlast..\nEnter the key  and data"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.insertlast(n1);
                break;
            }
        case 2:
            {
                cout<<"Insertfirst..\nEnter the key and data"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.insertfirst(n1);
                break;
            }
        case 3:
            {
                cout<<"Insert middle..\nEnter the key of exisiting node after which you want to insert : "<<endl;
                cin>>k1;
                cout<<"Enter the key and data"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.insertmiddle(k1,n1);
                break;
            }
        case 4:
            {
                cout<<"Delete node by key operation..\nEnter key of the node to be deleted: "<<endl;
                cin>>k1;
                d.deletenode(k1);
                break;
            }
        case 5:
            {
                cout<<"updata node by key operation..\nEnter key of the node: "<<endl;
                cin>>key1;
                cout<<"Enter the new data to be updated:"<<endl;
                cin>>data1;
                d.update(key1,data1);
                break;
            }
        case 6:
            {
                d.printlist();
                break;
            }
        case 7:
            exit(1);
        default:
            {
                cout<<"Enter the valid choice"<<endl;
                break;
            }
        }
    }
}
