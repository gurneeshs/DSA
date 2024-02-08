/*
    Approach: Using Topological Sort
    T.C = O(V+E)
*/
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;


class Graph{
    public:
        unordered_map<int,list<pair<int,int>>> adj;

        void addEdge(int u, int v, int weight){
            pair<int,int> p  = make_pair(v,weight);
            adj[u].push_back(p);
        }

        void printAdj(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<"["<<j.first<<","<<j.second<<"],";
                }cout<<endl;
            }
        }

        void dfs(int node, unordered_map<int,bool> &visited, stack<int> &s ){
            visited[node] = true;
            for(auto i:adj[node]){
                int neighbour = i.first;
                if(!visited[neighbour]){
                    dfs(neighbour,visited,s);
                }
            }
            s.push(node);
        }
};

int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    // topological sort
    unordered_map<int,bool> visited;
    stack<int> s;
    int n = 6;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    // Utilize topological sort
    int src = 1;
    vector<int> dist(n);

    for(int i=0;i<n;i++){
        dist[i] = INT32_MAX;
    }

    dist[src] = 0;

    // update distance array
    while(!s.empty()){
        int top = s.top();
        s.pop();

        if(dist[top]!=INT32_MAX){
            for(auto i:g.adj[top]){
                if(dist[top] + i.second < dist[i.first]){
                    dist[i.first] = dist[top] + i.second; 
                }
            }
        }
    }

    for(auto i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    return 0;
}