#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node*next;
}*head=NULL,*temp=NULL;
void insertnode(int ele,struct node **head)
{
    node* newnode=new node();
    if(*head==NULL)
    {
        newnode->data=ele;
        newnode->next=NULL;
        *head=newnode;
    }
    else
    {
        newnode->data=ele;
        newnode->next=NULL;
        temp= *head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void sumOfThree(struct node *a,struct node *b,struct node *c,int number)
{
    struct node *a1=a;
    while(a1!=NULL)
    {
        struct node *b1=b,*c1=c;
        while(b1!=NULL && c1!=NULL)
        {
            int sum=a1->data+b1->data+c1->data;
            if(sum == number)
            {
                cout<<"Triplet is found: "<<a1->data<<" "<<b1->data<<" "<<c1->data;
                return;
            }
            else if(sum<number)
                b1=b1->next;
            else
                c1=c1->next;
        }
        a1=a1->next;
    }
    cout<<"No triplet found";
    return;
}
void printList(struct node** head)
{
    temp= *head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        if(temp->next!=NULL)
            cout<<"-->";
        temp=temp->next;
    }
}

int main()
{
    int n;
    cout<<"Enter the no. of nodes in three linked list(assume the size is same for all):\n";
    cin>>n;
    cout<<"Enter the elements of list 1: \n";
    struct node *a=head,*b=head,*c=head;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele,&a);
    }
     cout<<"Enter the elements of list 2: \n";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele,&b);
    }
     cout<<"Enter the elements of list 3: \n";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insertnode(ele,&c);
    }
    printList(&a);
    cout<<endl;
    printList(&b);
    cout<<endl;
    printList(&c);
    int givenNumber=20;
    sumOfThree(a,b,c,givenNumber);
}
