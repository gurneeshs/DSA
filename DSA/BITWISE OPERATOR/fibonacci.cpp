#include <iostream>
using namespace std;

int main()
{
    int a=0, b=1,n;
    cout<<"Enter The Range";
    cin>>n;
    cout<<a<<" "<<b<<" ";
    for (int i=2;i<n;i++){
        int next = a+b;
        cout<<next<<" ";
        a=b;
        b=next;
        
    }
}