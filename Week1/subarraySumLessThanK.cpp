class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int end = 0, begin = 0, p = 1, cnt = 0;

        while (end < nums.size())
        {
            p *= nums[end];
            while (begin <= end && p >= k)
            {
                p /= nums[begin++];
            }

            if (p < k)
            {
                cnt += end - begin + 1;
                //cout<<end<<" "<<begin;
            }
            end++;
        }

        return cnt;
    }
