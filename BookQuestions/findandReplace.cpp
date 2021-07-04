//https://leetcode.com/problems/find-and-replace-in-string/
class Solution
{
public:
    string findReplaceString(string s, vector<int> &indeces, vector<string> &sources, vector<string> &targets)
    {

        map<int, pair<int, string>, greater<int>> mp;

        for (int i = 0; i < indeces.size(); i++)
        {
            string x = s.substr(indeces[i], sources[i].size());
            if (x.compare(sources[i]) == 0)
                mp[indeces[i]] = {sources[i].size(), targets[i]};
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            int pos = it->first, len = it->second.first;
            string str = it->second.second;
            s.replace(pos, len, str);
        }

        return s;
    }
};