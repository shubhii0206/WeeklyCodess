class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        int begin = 0, end = nums.size() - 1, ones = 0, twos = 0, zeros = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zeros++;
            else if (nums[i] == 1)
                ones++;
            else
                twos++;
        }

        for (int i = 0; i < zeros; i++)
            nums[i] = 0;
        for (int i = zeros; i < zeros + ones; i++)
            nums[i] = 1;
        for (int i = zeros + ones; i < zeros + ones + twos; i++)
            nums[i] = 2;
    }
};