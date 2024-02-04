#include <iostream>
using namespace std;

int main(){
    int a = 5;
    int *p = &a;
    int *q = p;
    cout<<p<<" "<<*p<<endl;
    cout<<q<<" "<<*q<<endl;
    (*q)++;
    cout<<a<<endl;
    cout<<p<<" "<<*p<<endl;
    cout<<q<<" "<<*q<<endl;

    return 0;
}