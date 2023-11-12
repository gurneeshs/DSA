/*
Reverse a String using Recursion
*/

#include <iostream>
#include <string>
using namespace std;

void reverse(int i, int j, string &str){
    //base Case
    if(i>j){
        return;
    }

    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    i++;
    j--;
    reverse(i,j,str);
}
int main(){
    string str = "Gurneesh";
    cout<<"Before Reversing:"<<str<<endl;
    reverse(0,str.size()-1,str);
    cout<<"After Reversing:"<<str<<endl;
    return 0;
}