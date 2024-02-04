/*
    A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

    Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex 
    ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not 
    possible if the graph is not a DAG.

    Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this 
    DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.
    https://www.codingninjas.com/studio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/


#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    unordered_map<int,list<int>> adj;
    vector<int> ans;
    queue<int> q;
    vector<int> indegree(v);

    // Prepare adjacency list
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // find indegrees
    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    // push into queue
    for(int i =0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    return ans;
    
}  