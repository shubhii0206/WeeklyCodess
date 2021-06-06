class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> mp;
        for (char ch : t)
            mp[ch]++;

        int counter = mp.size(), end = 0, begin = 0, len = INT_MAX, standard_begin = 0, standard_end = 0;

        while (end < s.size())
        {
            char c = s[end];
            if (mp.count(c) == 1)
            {
                mp[c]--;
                if (mp[c] == 0)
                    counter--;
            }
            end++;
            while (counter == 0)
            {
                if (end - begin < len)
                {
                    len = end - begin;
                    standard_begin = begin;
                    standard_end = end;
                }
                char start_char = s[begin];
                if (mp.count(start_char) == 1)
                {
                    mp[start_char]++;
                    if (mp[start_char] > 0)
                        counter++;
                }
                begin++;
            }
        }
        cout << standard_begin << " " << len;
        if (len == INT_MAX)
            return "";
        return s.substr(standard_begin, len);
    }
};