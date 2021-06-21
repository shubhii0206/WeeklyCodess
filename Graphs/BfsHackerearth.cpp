#include <bits/stdc++.h>
using namespace std;

int nodeLevel[100005];
vector<int> adj[100005];
int bfs(int s, int level)
{
    queue<int> Q;

    vector<bool> visited(100005, false);

    Q.push(s);
    visited[s] = true;
    nodeLevel[s] = 1;
    int cnt = 0;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        for (int i = 0; i < adj[x].size(); i++)
        {
            int child = adj[x][i];
            if (!visited[child])
            {
                nodeLevel[child] = nodeLevel[x] + 1;
                Q.push(child);
                visited[child] = true;
                if (nodeLevel[child] == level)
                    cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    int x, y, nodes, edges;

    cin >> nodes; //Number of nodes
    edges = nodes - 1;
    //Number of edges
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); //Insert y in adjacency list of x
    }

    int level;
    cin >> level;

    int ans = bfs(1, level);
    cout << ans;

    return 0;
}