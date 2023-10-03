#include <iostream>
using namespace std;

int fibonacci(int n){
    int a=0 ,b=1;
    int term;

    for (int i = 2;i<=n;i++){
        term=b+a;
        a=b;
        b=term;
    }
    if(n==0){
        term = 0;
    }
    else if (n==1)
    {
        term = 1;
    }
    return term;
    
}

int main(){
    int n;
    cout<<"Enter n";
    cin>>n;

    cout<<fibonacci(n);
    return 0;

}