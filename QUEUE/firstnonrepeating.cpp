/*
    Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
*/

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int n = A.length();
		    string ans = "";
		    queue<char> q;
		    unordered_map<char,int> count;
		    
		    for (int i=0;i<n;i++){
		        count[A[i]]++;
		        
		        q.push(A[i]);
		        
		        while(!q.empty()){
                    // Repeating Character
		            if(count[q.front()]>1){
		                q.pop();
		            }

                    // Non-repeating Character
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
                
		        // Empty Queue
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};