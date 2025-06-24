// Linear ordering of vertices such that if there is an edge from u->v u comes before v in the ordering
// Only poss for DIRECTED ACYCLIC GRAPH
// u->v ==== v is dependent on u

#include<bits/stdc++.h>
using namespace std;
vector<int> kahns(int nodes,vector<int> adj[],int vis[]) // Function to execute Kahns Algorithm
{
    vector<int> topo; //Vector to store thr topo sort
    vector<int> ind(nodes,0); // Vector having the indegree of each node initialised to zero
    // Indegree Calculation
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            ind[adj[i][j]]++;
        }
    }
    queue<int> q;
    // Initial queue
    for(int i=0;i<nodes;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            ind[adj[node][i]]--; // Freeing the child of its dependency on its parent
            if(ind[adj[node][i]]==0) // if the child has no dependency
            {
                q.push(adj[node][i]);
            }
        }
    }
    return topo;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("ipg.txt", "r", stdin); freopen("opf.txt", "w", stdout);
    #endif
    int nodes,edges;
    cin>>nodes>>edges;
    vector<int> adj[nodes];
    int vis[nodes]={0};
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> topo_kahns;
    topo_kahns=kahns(nodes,adj,vis);
    cout<<"TOPO SORT USING KAHNS ALGO IS:"<<endl;
    for(int i=0;i<topo_kahns.size();i++)
    {
        cout<<topo_kahns[i]<<" ";
    }
    
}

