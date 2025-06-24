#include<bits/stdc++.h>
using namespace std;
const long long N=(long long)1e6;
vector<int> adj[N+1]; // Adjacency List
int vis[N+1]={0};  // Visited Array
bool cycle=false;  // Boolean Variable to know if cycle is present or not
void cycle_using_dfs(int node,int parent)
{ 
    vis[node]=1;
   // cout<<node<<" ";
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(!vis[child])  // If child is not Visited then we call dfs 
        {
            cycle_using_dfs(child,node); // Present node becomes the new parent
        }
        else if(vis[child]&&child!=parent) // If the child which is not the parent is already visited then cycle is present
        {
            cycle=true;
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
        if(!vis[i])
        cycle_using_dfs(i,i);
        if(cycle)
        {
            cout<<"Cycle is present in the undirected graph";
            break;
        }
    }
    if(!cycle)
    {
        cout<<"Cycle is not present in the undirected graph";
    }

return 0 ;
}