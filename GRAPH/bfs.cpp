#include <bits/stdc++.h> 
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

void prepareAdjList(unordered_map<int, list<int> > &adjList,vector<pair<int, int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);//since undirected graph
    }
}
void bfs(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited,vector<int> &traversal, int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        traversal.push_back(frontNode);

        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here

    // STEP 1:
    unordered_map<int, list<int> > adjList;
    vector<int> traversal;
    unordered_map<int, bool> visited;

    // STEP: 2: Prepare Adjacency List
    prepareAdjList(adjList, edges);

    // STEP: 3: Traverse All Components of a graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList, visited, traversal, i);
        }
    }
    return traversal;
}