/*
    Given a set of N jobs where each jobi has a deadline and profit associated with it.

    Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the 
    profit associated with job if and only if the job is completed by its deadline.

    Find the number of jobs done and the maximum profit.
    https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // sort the jobs
        sort(arr,arr+n,cmp);
        
        int maxiDeadline = INT32_MIN;
        for(int i=0;i<n;i++){
            maxiDeadline = max(maxiDeadline, arr[i].dead);
        }
        
        // schedule vector
        vector<int> schedule(maxiDeadline+1, -1);
        
        int count = 0;
        int maxProfit = 0;
        for(int i=0;i<n;i++){
            int currProfit = arr[i].profit;
            int currJob = arr[i].id;
            int currDead = arr[i].dead;
            
            for(int k = currDead;k>0;k--){
                if(schedule[k] == -1){
                    count++;
                    maxProfit += currProfit;
                    schedule[k] = currJob;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxProfit);
        return ans;
    } 
};