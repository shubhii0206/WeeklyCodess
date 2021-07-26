//https://leetcode.com/problems/evaluate-division/submissions/
class Solution
{
public:
    void Dfsss(string src, string dst, unordered_map<string, vector<pair<string, double>>> &mp, unordered_map<string, int> &visited, double &ans, double temp)
    {

        // if(visited.count(src))
        //     return;
        if (src == dst)
        {
            ans = temp;
            return;
        }

        visited[src] = 1;
        for (auto x : mp[src])
        {
            if (visited[x.first] == 0)
                Dfsss(x.first, dst, mp, visited, ans, temp * x.second);
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> mp;

        for (int i = 0; i < equations.size(); i++)
        {
            string src = equations[i][0], dst = equations[i][1];

            mp[src].push_back({dst, values[i]});
            if (values[i] != 0)
                mp[dst].push_back({src, 1.0 / values[i]});
        }

        vector<double> finalans;

        for (auto x : queries)
        {
            unordered_map<string, int> visited;
            double ans = -1.0, temp = 1.0;
            if (mp.count(x[0]))
            {
                Dfsss(x[0], x[1], mp, visited, ans, temp);
            }
            finalans.push_back(ans);
        }

        return finalans;
    }
};