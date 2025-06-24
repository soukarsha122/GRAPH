// Linear ordering of vertices such that if there is an edge from u->v u comes before v in the ordering
// Only poss for DIRECTED ACYCLIC GRAPH
// If in the topo sort ith node comes before jth node it doesnt mean that an edge exists between the node (like consider two nodes from diff components)
// But if an edge exists between u to v then u will come before v in the topo sort


#include<bits/stdc++.h>
const int n=(int)1e5;
std::vector<int> adj[n];
int vis[n]={0};
std::stack<int> s; // Used to print nodes as per topo sort order
using namespace std;

void topodfs(int node) // Fn to help perform toposort
{
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(!vis[child])
        {
            topodfs(child);
        }
    }
    s.push(node);
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("ipg.txt", "r", stdin); freopen("opf.txt", "w", stdout);
    #endif
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); // Adjacency list for directed graph
    }
    //Here the nodes are 0 based
    for(int i=0;i<nodes;i++)
    {
        if(!vis[i])
        {
            topodfs(i);
        }
    }
    cout<<"TOPOLOGICAL SORT IS: "<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
