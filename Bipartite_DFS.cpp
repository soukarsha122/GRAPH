// NOTE: A Bipartite Graph is an UNDIRECTED graph

#include<bits/stdc++.h>
using namespace std;
const long long N=(long long)1e6;
vector<int> adj[N+1]; // Adjacency List
int color[N+1]={0};  // An array to store the colour of the nodes
bool poss=true;  // Boolean Variable to know if Bipartite graph is possible or not
int cnt;  // Variable to know the number of time we are calling dfs for a component of the graph

void cycle_using_dfs(int node) // Standard cycle detection using DFS with little modification
{
    if(cnt==1) // If the Dfs is called for the first time make the nodes colour as 1 (i.e. colour of starting node =1)
    {
        color[node]=1;
    }
   // cout<<node<<" ";
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(!color[child])  // If child is not Visited (=> not coloured) then we call dfs 
        {
            color[child]=3-color[node]; // We colour the child as 1 or 2 depending on the present nodes colour
            cnt++;
            cycle_using_dfs(child); 
        }
        else if(color[child]&&color[child]==color[node]) // If the child is already visited and has the same colour as present node
        {
            poss=false;
            return;
        }
    }
}
int main()
{
    int edges,nodes;
    cin>>edges>>nodes;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=nodes;i++)  //Checking components
    {
        if(!color[i]) 
        {
            cnt=1; // For each component cnt is initialized as 1
            cycle_using_dfs(i);
        }
        if(poss)
        {
            cout<<"Bipartite Graph";
            break;
        }
    }
    if(!poss)
    {
        cout<<"Not Bipartite";
    }

return 0 ;
}