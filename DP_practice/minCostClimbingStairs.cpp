class Solution
{
public:
    int costFromStep(int idx, vector<int> &dp, vector<int> &cost)
    {
        if (idx >= cost.size())
            return 0;
        if (dp[idx] != INT_MAX)
            return dp[idx];
        dp[idx] = min(costFromStep(idx + 1, dp, cost), costFromStep(idx + 2, dp, cost)) + cost[idx];
        return dp[idx];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {

        vector<int> dp(cost.size(), INT_MAX);
        return min(costFromStep(0, dp, cost), costFromStep(1, dp, cost));
    }
};