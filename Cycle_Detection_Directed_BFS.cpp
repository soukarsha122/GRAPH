// Uses Kahns ALgorithm

#include <bits/stdc++.h>
using namespace std;
bool cycle_kahns(int nodes, vector<int> adj[], int vis[]) // Fn to execute Kahns Algorithm
{
    vector<int> topo;          // Vector to store thr topo sort
    vector<int> ind(nodes, 0); // Vector having the indegree of each node initialised to zero
    // Indegree Calculation
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            ind[adj[i][j]]++;
        }
    }
    queue<int> q;
    int cnt = 0;
    // Initial queue
    for (int i = 0; i < nodes; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        cnt++;
        q.pop();
        topo.push_back(node);
        for (int i = 0; i < adj[node].size(); i++)
        {
            ind[adj[node][i]]--;        // Freeing the child of its dependency on its parent
            if (ind[adj[node][i]] == 0) // if the child has no dependency
            {
                q.push(adj[node][i]);
            }
        }
    }
    if (cnt == nodes) // if all the nodes were processed by kahns algo=> Graph is acyclic
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ipg.txt", "r", stdin);
    freopen("opf.txt", "w", stdout);
#endif
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes];
    int vis[nodes] = {0};
    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> topo_kahns;
    if (cycle_kahns(nodes, adj, vis))
    {
        cout << "CYCLE PRESENT IN DIRECTED GRAPH";
    }
    else
    {
        cout << "CYCLE NOT PRESENT IN DIRECTED GRAPH";
    }
    return 0;
}
