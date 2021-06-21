#include <bits/stdc++.h>
using namespace std;

bool visited[100005];
vector<int> adj[100005];
void dfs(int node)
{
    visited[node] = true;
    for (int i : adj[node])
    {
        if (!visited[i])
            dfs(i);
    }
}
int main()
{
    int x, y, nodes, edges;

    cin >> nodes; //Number of nodes
    cin >> edges;
    //Number of edges

    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); //Insert y in adjacency list of x
    }

    int head;
    cin >> head;
    dfs(head);
    int ans = 0;

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
            ans++;
    }

    cout << ans;

    return 0;
}