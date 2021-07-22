#include <iostream>

using namespace std;

class node
{
public:
    int key;
    int data;
    node *next;
    node()
    {
        key=0;
        data=0;
        next=NULL;
    }
    node(int k, int d)
    {
        key=k;
        data=d;
    }
};

class singlylinkedlist
{
public:
    node *head;
    singlylinkedlist()
    {
        head=NULL;
    }
    singlylinkedlist(node *n)
    {
        head=n;
    }
    //check if node exists using key....
    node* nodeexists(int k)
    {
        node* temp=NULL;
        node* ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->key==k)
                temp=ptr;
            ptr=ptr->next;
        }
        return temp;
    }

    // append a node to the list
    void insertlast(node *n)
    {
        if(nodeexists(n->key)!=NULL)
        {
            cout<<"Node already exists"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node appended"<<endl;
            }
            else
            {
                node* ptr=head;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next=n;
                cout<<"Node appended"<<endl;
            }
        }
    }
    //prepand mode
    void insertfirst(node *n)
    {
        if(nodeexists(n->key)!=NULL)
        {
            cout<<"Node already exists"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node appended"<<endl;
            }
            else
            {
                n->next=head;
                head=n;
                cout<<"Node appended"<<endl;
            }
        }
    }
    //insert middle in the node
    void insertmiddle(int k, node *n)
    {
        node *ptr= nodeexists(k);
        if(ptr==NULL)
            cout<<"No node exists"<<endl;
        else
        {
            if(nodeexists(n->key)!=NULL)
            {
                cout<<"Node already exists"<<endl;
            }
            else
            {
                n->next=ptr->next;
                ptr->next=n;
                cout<<"Node inserted"<<endl;
            }
        }
    }
    //delete the node
    void deletenode(int k)
    {
        if(head==NULL)
        {
            cout<<"List is emtpy"<<endl;
        }
        else if(head !=NULL)
        {
            if(head->key==k)
            {
                head=head->next;
                cout<<"Node is unliked"<<endl;
            }
            else
            {
                node *temp=NULL;
                node *prevptr=head;
                node * currentptr=head->next;
                while(currentptr!=NULL)
                {
                    if(currentptr->key==k)
                    {
                        temp=currentptr;
                        currentptr=NULL;
                    }
                    else
                    {
                        prevptr=prevptr->next;
                        currentptr=currentptr->next;
                    }
                }
                if(temp!=NULL)
                {
                    prevptr->next=temp->next;
                    cout<<"Node is unlinked"<<endl;
                }
                else
                    cout<<"Node doesn't exist with the key value"<<endl;
            }
        }
    }
    //update node
    void update(int k, int d)
    {
        node *ptr=nodeexists(k);
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
            cout<<endl<<"Singly linked list";
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
    singlylinkedlist s;
    int option;
    int key1,k1,data1;
    while(1)
    {
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
                s.insertlast(n1);
                break;
            }
        case 2:
            {
                cout<<"Insertfirst..\nEnter the key and data"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.insertfirst(n1);
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
                s.insertmiddle(k1,n1);
                break;
            }
        case 4:
            {
                cout<<"Delete node by key operation..\nEnter key of the node to be deleted: "<<endl;
                cin>>k1;
                s.deletenode(k1);
                break;
            }
        case 5:
            {
                cout<<"updata node by key operation..\nEnter key of the node: "<<endl;
                cin>>key1;
                cout<<"Enter the new data to be updated:"<<endl;
                cin>>data1;
                s.update(key1,data1);
                break;
            }
        case 6:
            {
                s.printlist();
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
