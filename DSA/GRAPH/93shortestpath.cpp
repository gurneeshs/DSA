/*
    The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to 
    ‘N’ respectively and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and 
    ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house 
    from any other house via some combination of roads. Two houses are directly connected by at max one road.

    A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where 
    starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses 
    Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ 
    to ‘T’.
    https://www.codingninjas.com/studio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>> adj;
	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;

	// Prepare Adjancey List
	for(int i =0 ; i<m;i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	parent[s] = -1;
	// BFS
	q.push(s);
	visited[s] = true;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto i:adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	// prepare shortest path
	vector<int> ans;
	int currentNode = t;

	while(currentNode!=-1){
		ans.push_back(currentNode);
		currentNode = parent[currentNode];
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
