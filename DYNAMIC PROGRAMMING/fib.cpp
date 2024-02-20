/*
    The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following 
    formula -
        F(n) = F(n - 1) + F(n - 2), 
        Where, F(1) = 1, F(2) = 1
    Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 
    'n' = 2 by using conditionals like if else and return what's expected.

    "Indexing is start from 1"
*/
#include<bits/stdc++.h>
#include <vector>
using namespace std;
// int fib(int n, vector<int> &dp){
        // top down approach
//         if(n<=1){
//                 return n;
//         }
//         // if solution is already present
//         if(dp[n]!=-1){
//                 return dp[n];
//         }

//         // memorization
//         dp[n] = fib(n-1,dp) + fib(n-2,dp);
//         return dp[n];
// }
int main()
{
        int n;
        cin>>n;
        // vector<int> dp(n+1);
        // for(int i=0;i<=n;i++){
        //         dp[i] = -1;
        // }

        // cout<<fib(n,dp)<<endl;
        
        // bottom up appraoch
        // dp[0] = 0;
        // dp[1] = 1;
        int prev1 = 1;
        int prev2 = 0;
        int curr = -1;
        
        for(int i=2;i<=n;i++){
                curr = prev1+prev2;
                prev2 = prev1;//space optimization
                prev1 = curr;
        }
        cout<<prev1<<endl;
        return 0;
}