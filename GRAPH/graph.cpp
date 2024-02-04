#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph{
    public:
        // adjency list representation 
        unordered_map<int, list<int> > adj;

        void addEdge(int u, int v, bool direction){
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph

            // edge from u to v
            adj[u].push_back(v);

            if(direction==0){
                // edge from v to u
                adj[v].push_back(u);
            }
        }

        void printAdjlist(){
            for(auto i:adj){
                cout<< i.first << "->";
                for(auto j:i.second){
                    cout << j << " ";
                }
                cout<<endl;
            }
        }
};
int main(){

    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph g;

    for(int i=0;i<m;i++){
        cout<<"Enter Node";
        int u, v;
        cin>> u;
        cout<<"Enter edge connected";
        cin>>v;
        g.addEdge(u,v,0);
        cout<<endl;
    }

    g.printAdjlist();
    return 0;
}