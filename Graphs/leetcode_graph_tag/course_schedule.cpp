//https://leetcode.com/problems/course-schedule/submissions/
class Solution
{
public:
    void indegrees(vector<int> &indegree, vector<vector<int>> prerequisites)
    {
        for (auto x : prerequisites)
        {
            int dst = x[1];
            indegree[dst]++;
        }
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(100001);
        for (auto x : prerequisites)
        {
            int src = x[0];
            int dst = x[1];
            graph[src].push_back(dst);
        }
        vector<int> indegree(numCourses, 0);
        indegrees(indegree, prerequisites);

        vector<int> s;

        for (int i = 0; i < numCourses; i++)
        {
            cout << indegree[i] << " ";
            if (indegree[i] == 0)
                s.push_back(i);
        }

        while (!s.empty())
        {
            int x = s.back();
            s.pop_back();

            for (int xs : graph[x])
            {
                indegree[xs]--;
                if (indegree[xs] == 0)
                    s.push_back(xs);
            }
        }

        for (int x : indegree)
        {
            if (x > 0)
                return false;
        }
        return true;
    }
};