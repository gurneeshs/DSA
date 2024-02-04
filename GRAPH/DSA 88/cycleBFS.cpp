/*
    https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
    You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 
    to 'N'.

    Your task is to find if the graph contains a cycle or not.

    A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called 
    a cycle.
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;
bool isCyclicBFS(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int> > &adj){
    unordered_map<int,int> parent;
    queue<int> q;

    parent[src] = -1;
    q.push(src);
    visited[src] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour:adj[front]){
            if(visited[neighbour]==true && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;

}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int> >adj;
    unordered_map<int,bool> visited;
    // prepare adjacency list
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}