/*
Take two variables from user a and b, Return a^b
using recursion

a^b --> a^b/2 x a^b/2, if b is even
    --> a x (a^b/2 x a^b/2), if b is odd
*/

#include <iostream>
using namespace std;

int findPower(int a, int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }

    int ans = findPower(a, b/2);

    if(b%2==0){
        // b is even
        return ans * ans;
    }
    else{
        // b is odd
        return a * ans *ans;
    }

}
int main(){
    int a,b;
    cout<<"Enter the value of a:";
    cin>>a;
    cout<<"Enter the value of b:";
    cin>>b;
    cout<<"a^b = "<<findPower(a,b)<<endl;
    return 0;
}