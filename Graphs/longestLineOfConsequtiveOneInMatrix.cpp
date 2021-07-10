int dfs(int i, int j, int m, int n, vector<vector<int>> &graph)
{
    if(i < 0 || i >= m || j < 0 || j >= n || graph[i][j] == 0)
    return 0;

    int p = 1 + dfs(i + 1, j, m, n, graph);
    int q = 1 + dfs(i + 1, j + 1, m, n, graph);
    int r = 1 + dfs(i + 1, j-1, m, n, graph);
    int s = 1 + dfs(i, j + 1, m, n, graph);
    return max({p, q, r, s});


}