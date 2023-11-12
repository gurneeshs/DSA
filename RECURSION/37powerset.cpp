/*
    Given a set A = {1,2,3}, return the power set of array i.e
    {{},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3}}
*/

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<int> out, int index, vector<vector<int>>& ans){
    // base case
    if(index>=nums.size()){
        ans.push_back(out);
        return;
    }

    // exclusion
    solve(nums,out,index+1,ans);

    // inclusion
    int element = nums[index];
    out.push_back(element);
    solve(nums,out,index+1,ans);
}

int main(){
    
    vector<int> A = {1,2,3,4};
    
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(A,output,index,ans);
    for(int i=0;i<ans.size();i++){
        cout<<"{ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"} ";

    }
    // cout<<ans[0][1];
    return 0;
}