/*
    Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates 
    in a packet. Each packet can have a variable number of chocolates. There are M students, the task is 
    to distribute chocolate packets among M students such that :
    1. Each student gets exactly one packet.
    2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.
    https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        
        sort(a.begin(),a.end());
        
        int i = 0;
        int j = m-1;
        
        int mini = INT32_MAX;
        while(j<a.size()){
            int diff = a[j] - a[i];
            
            mini = min(mini, diff);
            i++;
            j++;
        }
        return mini;
    
    }   
};