//https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/submissions/
class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {

        int cnt = 0;
        int start = -1, end = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= left && nums[i] <= right)
                end = i;
            else if (nums[i] > right)
            {
                start = i;
                end = i;
            }
            cnt += end - start;
        }
        return cnt;
    }
};