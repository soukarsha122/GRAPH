#include<bits/stdc++.h>
using namespace std;
const int N=(int)1e6;
int vis[N];
vector<int>adj[N+1];
queue<int> q;
vector<int>Bfs;
void bfs(int node)
{
    q.push(node);
    vis[node]=1;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        Bfs.push_back(curr); // Pushing the current element to the Bfs vector as this vector stores the search sequence
        for(int i=0;i<adj[curr].size();i++)  // Pushing the adjacent elements of the current node which are not yet visited to the queue
        {
            int child=adj[curr][i];
            if(!vis[child])
            {
                vis[child]=1;
                q.push(child);
            }
        }
    }
    for(int i=0;i<Bfs.size();i++)
    {
        cout<<Bfs[i]<<" ";
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
        if(!vis[i])
        bfs(i);
    }
}
