/*Given an array of characters formed with a’s and b’s. The string is marked with
special character X which represents the middle of the list (for example:
ababa...ababXbabab baaa). Check whether the string is palindrome using stacks */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool check_palindrome(string);
int main()
{
    string a;
    getline(cin,a);
    if(check_palindrome(a))
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not palindrome"<<endl;
}
bool check_palindrome(string a)
{
    stack<char> s;
    int i=0;
    while(a[i]!='X')
    {
        s.push(a[i]);
        i++;
    }
    i++;
    while(a[i])
    {
        if(s.empty() || (s.top() != a[i]))
        {
            return false;
        }
        s.pop();
        i++;
    }
    if(s.empty())
        return true;
}
