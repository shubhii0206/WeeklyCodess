class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int buy_price = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            profit = max(prices[i] - buy_price, profit);

            if (prices[i] - buy_price < 0)
            {
                buy_price = prices[i];
            }
        }

        return profit;
    }
};