class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {

        map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            int x = it->first;
            int y = mp[x];
            if (y)
            {
                for (int i = 0; i < k; i++)
                {
                    mp[x + i] -= y;
                    if (mp[x + i] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};