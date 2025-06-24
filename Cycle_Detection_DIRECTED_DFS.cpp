#include<bits/stdc++.h>
using namespace std;
const int N=(int)1e6;
vector<int> adj[N+1];
vector<int>  vis(N+1,0);
vector<int> dfsvis(N+1,0);
bool cycle=false;
void iscycle(int node,int parent)
{
    vis[node]=1;
    dfsvis[node]=1;
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(!vis[child])
        {
            iscycle(child,node);
        }
        else
        {
            if(dfsvis[child]==1 && child!=parent)
            {
                cycle=true;
            }
        }
    }
    dfsvis[node]=0;
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
        //adj[v].push_back(u);
    }
    for(int i=1;i<=nodes;i++)  //Checking components
    {
        if(!vis[i])
        iscycle(i,i);
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