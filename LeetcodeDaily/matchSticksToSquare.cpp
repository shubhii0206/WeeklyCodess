class Solution
{
public:
    bool dfs(vector<int> &matchsticks, int idx, int currSum, int side_sum, bitset<16> &visited, int sides_left)
    {
        if (sides_left == 1)
            return true;
        if (currSum == side_sum)
            return dfs(matchsticks, 0, 0, side_sum, visited, sides_left - 1);
        if (idx >= matchsticks.size())
            return false;
        for (int i = idx; i < matchsticks.size(); i++)
        {
            if (!visited[i] && currSum + matchsticks[i] <= side_sum)
            {
                visited[i] = true;
                if (dfs(matchsticks, idx + 1, currSum + matchsticks[i], side_sum, visited, sides_left))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        int s = 0;
        for (int num : matchsticks)
            s += num;

        if (s % 4 != 0)
            return false;
        int side_sum = s / 4;

        bitset<16> visited;
        int idx = 0;
        int currSum = 0;

        return dfs(matchsticks, idx, currSum, side_sum, visited, 4);
    }
};