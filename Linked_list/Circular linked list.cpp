#include <iostream>

using namespace std;

class node
{
public:
    int data;
    int key;
    node *next;
    node(int k=0 , int d=0)
    {
        key=k;
        data=k;
        next=NULL;
    }
};
class circularlinkedlist
{
public:
     node *head;
    circularlinkedlist()
    {
        head=NULL;
    }
    //check if node exists using key value
    node* checkNode(int k)
    {
        node *temp=NULL;
        node *ptr=head;
        if(ptr==NULL)
            return temp;
        do
        {
            if(ptr->key==k)
                temp=ptr;
            ptr=ptr->next;
        }while(ptr!=head);
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
                n->next=head;
                cout<<"APPENDED"<<endl;
            }
            else
            {
                node * ptr=head;
                while(ptr->next!=head)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->next=head;
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
                n->next=head;
                cout<<"Inserted"<<endl;
            }
            else
            {
                node *ptr=head;
                while(ptr->next!=head)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
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
                if(ptr->next==head)
                {
                    n->next=head;
                    ptr->next=n;
                    cout<<"Node inserted"<<endl;
                }
                else
                {
                    n->next=ptr->next;
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
            if(ptr==head)
            {
                if(head->next==head)
                {
                    head=NULL;
                    cout<<"Node is unlinked"<<endl;
                }
                else
                {
                    node *ptr1=head;
                    while(ptr1->next!= head)
                        ptr1=ptr1->next;
                    ptr1->next = head->next;
                    head = head->next;
                    cout<<"Node is unlinked"<<endl;
                }
            }
            else
            {
                node *temp=NULL;
                node *prevptr=head;
                node *currentptr=head->next;
                while(currentptr!=head)
                {
                    if(currentptr->key==k)
                    {
                        temp=currentptr;
                        currentptr=NULL;
                    }
                    else
                    {
                        prevptr=prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                prevptr->next=temp->next;
                cout<<"Node is unlinked"<<endl;
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
            cout<<endl<<"circular linked list: ";
             cout<<"Head address"<<head<<endl;
            node *temp=head;
            do
            {
                cout<<"("<<temp->key<<","<<temp->data<<","<<temp->next<<")-->";
                temp=temp->next;
            } while(temp!=head);
        }
    }
};
int main()
{
    circularlinkedlist c;
    int option;
    int key1,k1,data1;
    while(1)
    {
        cout<<endl<<"What operation do you like to perform"<<endl;
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
                c.insertlast(n1);
                break;
            }
        case 2:
            {
                cout<<"Insertfirst..\nEnter the key and data"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                c.insertfirst(n1);
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
                c.insertmiddle(k1,n1);
                break;
            }
        case 4:
            {
                cout<<"Delete node by key operation..\nEnter key of the node to be deleted: "<<endl;
                cin>>k1;
                c.deletenode(k1);
                break;
            }
        case 5:
            {
                cout<<"updata node by key operation..\nEnter key of the node: "<<endl;
                cin>>key1;
                cout<<"Enter the new data to be updated:"<<endl;
                cin>>data1;
                c.update(key1,data1);
                break;
            }
        case 6:
            {
                c.printlist();
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
