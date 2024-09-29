#include <iostream>
#include <stack>
using namespace std;
void insert(stack<int> & s, int element) 
{
    if(s.empty()) 
    {
        s.push(element);
        return;
    }
    int top_ele=s.top();
    s.pop();
    insert(s, element);
    s.push(top_ele);
}
void reverse(stack<int> & s) 
{
    if(s.empty()) 
    {
        return;
    }
    int top_ele=s.top();
    s.pop();
    reverse(s);
    insert(s, top_ele);
}
void print(stack<int> s) 
{
    if(s.empty()) 
    {
        return;
    }
    int top_ele=s.top();
    s.pop();
    print(s); 
    cout<<top_ele<<" "; 
}

int main() 
{
    stack<int> s;
    int n, element;
    cout<<"Enter the number of elements in the stack: ";
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++) 
    {
        cin>>element;
        s.push(element);
    }
    cout<<"Original Stack: ";
    print(s);
    cout<<endl;
    reverse(s);
    cout<<"Reversed Stack: ";
    print(s);
    cout<<endl;

    return 0;
}
