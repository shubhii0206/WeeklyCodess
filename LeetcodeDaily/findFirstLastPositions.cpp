//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int start = 0, end = nums.size() - 1;
        vector<int> v(2);
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }

        if (nums[start] == target)
            v[0] = start;
        else
            return {-1, -1};

        end = nums.size() - 1;

        while (start < end)
        {
            int mid = (start + end) / 2 + 1;
            if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid;
        }

        v[1] = end;
        return v;
    }
};