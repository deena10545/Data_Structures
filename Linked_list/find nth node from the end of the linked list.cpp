#include <iostream>
#include <forward_list>
using namespace std;

int nthnode(forward_list<int> &l , int n)
{

    forward_list<int> :: iterator itr=l.begin();
    forward_list<int> :: iterator itr1=l.begin();
    int count=0;
    if(itr!=l.end())
    {
        while(count<n)
        {
            itr1++;
            count++;
        }
        while(itr1!=l.end())
        {
            itr++;
            itr1++;
        }
    }
    return *itr;
}
int main()
{
    forward_list<int> l={10,20,30,40,50};
    int flag=0;
    for( int i:l)
       {
        cout<<i<<" ";
        flag++;
       }
    int n;
    cout<<"Enter the nth node number"<<endl;
    cin>>n;
    if(flag<n)
    {
        cout<<"Lesser nodes";
    }
    else
    {
    int nth=nthnode(l,n);
    cout<<nth<<" ";
    }
}
