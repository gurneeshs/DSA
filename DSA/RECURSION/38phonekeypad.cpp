/*
    Given a string of phone numbers [2 - 9] ,return the combination of all the characters corresponding to phone numbers

    2->abc
    3->def
    4->ghi
    5->jkl
    6->mno
    7->pqrs
    8->tuv
    9->wxyz

    Example: Given "23"
             2 -> abc, 3 -> def
             Output {ad,ae,af,bd,be,bf,cd,ce,cf}
    
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string digits, string output, int index, vector<string>& ans, string mapping[]){
    // base case
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }

    // recurrence relation
    int index1 = digits[index] - '0';
    string value = mapping[index1];

    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,mapping);
        output.pop_back();
    }
}
vector<string> letterCombination(string digits){
    vector<string> ans;
    if(digits.length()==0){
        return ans;
    }

    string output = "";
    int index = 0;

    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,index,ans,mapping);
    return ans;
}
int main(){
    string str = "234";
    vector<string> ans = letterCombination(str);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}