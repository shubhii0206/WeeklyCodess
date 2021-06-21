//https://leetcode.com/problems/student-attendance-record-i/submissions/
class Solution
{
public:
    bool checkRecord(string s)
    {
        int absent = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
                absent++;
            if (s[i] == 'L')
            {
                if (i + 2 < s.size() && s[i + 1] == 'L' && s[i + 2] == 'L')
                    return false;
            }

            if (absent > 1)
                return false;
        }
        return true;
    }
};