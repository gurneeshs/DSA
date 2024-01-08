/*
    Reverse a String using stack
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str = "babbar";
    stack<char> s;
    
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    string str2;
    for(int i=0;i<str.length();i++){
        char ap = s.top();
        s.pop();
        str2 = str2 + ap;
    }
    cout<<str2;
    return 0;
}