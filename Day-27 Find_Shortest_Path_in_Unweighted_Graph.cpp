#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int shortestPath(int V, vector<pair<int, int>> &edges, int start, int end) 
{
    vector<int> adj[V];
    for(auto edge:edges) 
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    vector<bool> visited(V, false);
    vector<int> distance(V, -1);
    queue<int> q;
    q.push(start);
    visited[start]=true;
    distance[start]=0;
    while(!q.empty()) 
    {
        int node=q.front();
        q.pop();
        for(int neighbor:adj[node]) 
        {
            if(!visited[neighbor]) 
            {
                visited[neighbor]=true;
                distance[neighbor]=distance[node]+1;
                q.push(neighbor);
                if(neighbor==end) 
                {
                    return distance[neighbor];
                }
            }
        }
    }
    return -1;
}
int main() 
{
    int V,E,start,end;
    cout<<"Enter the number of vertices (V): ";
    cin>>V;
    cout<<"Enter the number of edges (E): ";
    cin>>E;
    vector<pair<int, int>> edges;
    cout<<"Enter the edges (as pairs of vertices):"<<endl;
    for(int i=0;i<E;i++) 
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u, v});
    }
    cout<<"Enter the start node: ";
    cin>>start;
    cout<<"Enter the end node:";
    cin>>end;
    int result=shortestPath(V, edges, start, end);
    if(result!=-1) 
    {
        cout<<"The shortest path length is: "<<result<<endl;
    } 
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}
