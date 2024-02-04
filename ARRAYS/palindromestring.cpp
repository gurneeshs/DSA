#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

bool checkPalindrome(string s)
{
    
    int st=0;
    int e=s.length()-1;
    while(st<=e){
        if(ispunct(s[st]) || isblank(s[st])){
            st++;
        }
        else if(ispunct(s[e]) || isblank(s[e])){
            e--;
        }

        else if(tolower(s[st])!=tolower(s[e])){
            return false;
        }
        else{
            st++;
            e--;
        }
    }
    return true;
}

int main(){
    string s = "N3 i&nJA?a& jnI2n";
    cout<<checkPalindrome(s);
    return 0;    
}