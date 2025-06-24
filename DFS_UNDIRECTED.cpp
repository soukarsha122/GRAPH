#include<bits/stdc++.h>
using namespace std;
const long long N=(long long)1e6;
vector<int> adj[N+1]; // Adjacency List
int vis[N+1]={0};  // Visited Array
void dfs(int node)
{
    vis[node]=1;
    cout<<node<<" ";
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(!vis[child])  // If child is not Visited then we call dfs 
        {
            dfs(child);
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
        dfs(i);
    }

return 0 ;
}