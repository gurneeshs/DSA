/*
    There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] 
    is start time of meeting i and end[i] is finish time of meeting i.
    What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting 
    can be held in the meeting room at a particular time?

    Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
    https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        // make vector
        vector<pair<int,int> > v;
        
        for(int i=0;i<n;i++){
            pair<int,int> p = make_pair(start[i],end[i]);
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int count = 1;
        int ansEnd = v[0].second;
        
        for(int i = 1;i<n;i++){
            if(v[i].first > ansEnd){
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }
};