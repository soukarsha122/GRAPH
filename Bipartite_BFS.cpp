// Graph is Bipartite if all nodes can be coloured using exactly 2 colours
// No two adjacent nodes have same colour
// NOTE: A Bipartite Graph is an UNDIRECTED graph

#include<bits/stdc++.h>
using namespace std;
const int N=(int)1e6;
vector<int> color(N+1,0); // Vector initialized with zero to show none of the nodes are coloured
vector<int> adj[N+1];
queue<int> q;
bool poss=true;   // Boolean Variable to know if graph is bipartite or not

void bfs(int node) // Standard BFS with little modification
{
    q.push(node);
    color[node]=1;
    while (!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int i=0;i<adj[curr].size();i++)
        {
            int child=adj[curr][i];
            if(color[child]==0)   // If child is not yet coloured then colour it and push it to queue for further bfs
            {
                    q.push(child);
                    color[child]=3-color[curr];  // We are colouring the childs as 1 and 2 with the starting node being 1
            }
            else
            {
                if(color[child]!=0)  // If we come across a child that is previously coloured .. i.e. there is a cycle
                {
                    if(color[curr]==color[child])  // If that child has same colour as the parent then we cannot have adj nodes of same colour
                    {
                        poss=false;
                        return;
                    }
                }
            }
        }

    }
    
}
int main()
{
    int edges,nodes;
    cin>>edges>>nodes;
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=nodes;i++)
    {
        if(!color[i])
        bfs(i);
        if(poss==true)
        {
            cout<<"Bipartite Graph";
            break;
        }
    }
    if(!poss)
    {
        cout<<"Not Bipartite";
    }
    return 0;
}