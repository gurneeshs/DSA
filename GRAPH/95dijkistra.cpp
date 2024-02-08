/*
    You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each 
    edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node 
    ‘Y’.
    Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to 
    all vertices given in the graph.
    https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

    unordered_map<int, list<pair<int,int>>> adj;
    vector<int> dist(vertices);
    // set<pair<int,int>> st;//<dist,node> pair
    set<pair<int,int> > st;

    // Create adjacency list
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // Initialize distance vector
    for(int i=0;i<vertices;i++){
        dist[i] = INT32_MAX;
    }
    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        // fetch top
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topnode = top.second;

        // remove top record
        st.erase(st.begin());

        // traverse on neighbour
        for(auto neighbour:adj[topnode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                // find already existing pair
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));           
                if(record!=st.end()){
                    st.erase(record);
                }

                // update distance
                dist[neighbour.first] = nodeDistance + neighbour.second;

                // push into set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }


    }
    return dist;
}
