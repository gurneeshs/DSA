/*
    Given a string str, return all the permutations of string in sorted way

    Eg: i/p: abc
        o/p: abc, acb, bac, bca, cab, cba
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void help(string str, vector<string>& str1, int index){
    if(index>=str.length()){
        cout<<"Pushing "<<str<<endl;
        str1.push_back(str);
        return;
    }

    for(int i=index;i<str.length();i++){
        swap(str[index],str[i]);
        // cout<<"Swapped"<<str<<" ";
        help(str,str1,index+1);
        swap(str[index],str[i]);
        // cout<<"Backtrack Swap"<<str<<" ";
    }
}
vector<string> permutations(string& str){
    vector<string> str1;
    help(str,str1,0);
    return str1;
}
int main(){
    string str = "abc";
    vector<string> ans = permutations(str);
    for(string itm:ans){
        cout<<itm<<" ";
    }

    return 0;
}