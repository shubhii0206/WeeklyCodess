class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(100001);
        for (auto x : prerequisites)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        vector<int> s, ans;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                s.push_back(i);
        }

        while (!s.empty())
        {
            int x = s.back();
            s.pop_back();

            ans.push_back(x);

            for (int p : graph[x])
            {
                indegree[p]--;
                if (indegree[p] == 0)
                {
                    s.push_back(p);
                }
            }
        }

        for (int x : indegree)
        {
            if (x > 0)
                return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};