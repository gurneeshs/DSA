/*
Check if the given string is palindrome or not using Recursion
*/

#include <iostream>
#include <string>
using namespace std;


bool checkPalindrome(string str, int i, int j){
    if(i>j)
        return true;
    
    if(str[i]!=str[j])
        return false;
    else{
        return checkPalindrome(str,i+1,j-1);
    }
}

int main(){
    string str = "abccdba";
    if(checkPalindrome(str,0,str.size()-1)){
        cout<<"It is a palindrome string"<<endl;
    }
    else{
        cout<<"It is not a palindrome string"<<endl;
    }
    return 0;
}
