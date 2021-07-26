class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        unordered_map<int, vector<pair<int, int>>> mp;

        for (auto x : times)
        {
            int src = x[0], dst = x[1], t = x[2];
            mp[src].push_back({dst, t});
        }

        queue<pair<int, int>> pq;

        pq.push({k, 0});

        vector<int> time(n + 1, INT_MAX);
        time[0] = 0;
        time[k] = 0;

        while (!pq.empty())
        {
            auto x = pq.front();
            pq.pop();

            for (auto edge : mp[x.first])
            {
                if (time[edge.first] > x.second + edge.second)
                {
                    time[edge.first] = x.second + edge.second;
                
                pq.push({edge.first, time[edge.first]});
                }
            }
        }
        int ans = 0;
        for (int f : time)
            ans = max(f, ans);

        if (ans < INT_MAX)
            return ans;
        return -1;
    }
};