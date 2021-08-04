//https://leetcode.com/problems/top-k-frequent-elements/
//O(nlogk)
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int n : nums)
            mp[n]++;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push({it->second, it->first});

            while (pq.size() > k)
                pq.pop();
        }

        vector<int> res;

        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
