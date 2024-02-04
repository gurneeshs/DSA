/*
    /*
    https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
    You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents 
    the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

    Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed 
    graph else return false.
*/


#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adj;
    vector<int> ans;
    queue<int> q;
    vector<int> indegree(n);

    // Prepare adjacency list
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first-1;
        int v = edges[i].second-1;

        adj[u].push_back(v);
    }

    // find indegrees
    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    // push into queue
    for(int i =0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        cnt++;

        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    // if valid topological sort
    if(cnt==n){
      return false;
    }
    else{
      return true;
    } 
}