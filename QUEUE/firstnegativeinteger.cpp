/*
    Given a Queue and a window of size K, you have to return the first -ve integer
    of each window. Return 0 if element is not negative
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;
    
    // first window
    for(int i=0;i<K;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    // Remaining Windows;
    for(int i=K;i<N;i++){
        if(i-dq.front()>=K && !dq.empty()){
            dq.pop_front();
        }
        if(A[i]<0){
            dq.push_back(i);
        }
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
                                                 
                                                 
 }