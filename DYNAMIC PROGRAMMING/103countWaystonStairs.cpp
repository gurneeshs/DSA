/*
    You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth 
    stair.
    Each time, you can climb either one step or two steps.

    You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
    https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/
#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define MOD 100000007
int solve(long long nStairs, int i){
    if(i==nStairs)
        return 1;

    if(i>nStairs)
        return 0;

    return (solve(nStairs,i+1)+solve(nStairs,i+2)) % MOD;
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    int ans = solve(nStairs,0);
    return ans;
}