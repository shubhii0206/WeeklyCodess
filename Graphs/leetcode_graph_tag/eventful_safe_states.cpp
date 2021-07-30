//https://leetcode.com/problems/find-eventual-safe-states/submissions/
class Solution
{
public:
    bool backEdge(int u, vector<int> &color, vector<vector<int>> &graph)
    {
        color[u] = 1;

        for (auto it : graph[u])
        {
            if (color[it] == 0 && backEdge(it, color, graph))
                return true;
            if (color[it] == 1)
                return true;
        }
        color[u] = 2;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> ans;
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!backEdge(i, color, graph))
                ans.push_back(i);
        }
        return ans;
    }
};