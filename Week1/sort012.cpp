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

################################################################################
public:
    void sortColors(vector<int> &nums)
    {

        int start = 0, mid = 0, end = nums.size() - 1, i = 0;

        while (mid <= end)
        {
            if (nums[mid] == 0)
            {
                int t = nums[mid];
                nums[mid] = nums[start];
                nums[start] = t;
                mid++;
                start++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                int t = nums[mid];
                nums[mid] = nums[end];
                nums[end] = t;

                end--;
            }
        }
    }
};