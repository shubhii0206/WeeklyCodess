class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), profit = 0, buy = 0, sell = 0, i = 0;
        while (i + 1 < n)
        {
            while (i + 1 < n && prices[i] >= prices[i + 1])
            {
                i++;
            }
            buy = prices[i];

            while (i + 1 < n && prices[i] <= prices[i + 1])
            {
                i++;
            }
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
    }
};