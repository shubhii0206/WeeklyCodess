//https://www.lintcode.com/problem/386/description
class Solution
{
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k)
    {

        unordered_map<char, int> freq;
        int begin = 0, countUnique = 0, len = 0, maxlen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (freq[s[i]] == 0)
                countUnique++;

            freq[s[i]]++;
            len++;

            if (countUnique <= k && len > maxlen)
                maxlen = len;

            if (countUnique > k)
            {
                freq[s[begin]]--;
                if (freq[s[begin++]] == 0)
                    countUnique--;
                len--;
            }
        }
        return maxlen;
        // write your code here
    }
};