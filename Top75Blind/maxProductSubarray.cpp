//https://leetcode.com/problems/maximum-product-subarray/
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        vector<int> positivedp(nums.size(), 0);
        vector<int> negativedp(nums.size(), 0);
        positivedp[0] = nums[0];
        negativedp[0] = nums[0];
        int res = positivedp[0];

        for (int i = 1; i < nums.size(); i++)
        {
            positivedp[i] = max(max(positivedp[i - 1] * nums[i], negativedp[i - 1] * nums[i]), nums[i]);
            negativedp[i] = min(min(positivedp[i - 1] * nums[i], negativedp[i - 1] * nums[i]), nums[i]);
            res = max(res, positivedp[i]);
        }

        return res;
    }
};