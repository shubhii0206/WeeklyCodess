//https://leetcode.com/problems/number-of-matching-subsequences/submissions/

class Solution


{
public:
    int find(vector<int> arr, int idx, string s)
    {
        int l = 0, h = arr.size() - 1;
        int ans = s.size();
        while (l <= h)
        {
            int mid = (l + h) / 2;

            if (arr[mid] <= idx)
            {
                l = mid + 1;
            }
            else
            {
                ans = arr[mid];
                h = mid - 1;
            }
        }
        if (ans == s.size())
            return -1;
        else
            return arr[l];
    }
    int numMatchingSubseq(string s, vector<string> &words)
    {

        unordered_map<char, vector<int>> mp;
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }

        for (string word : words)
        {
            int idx = -1;

            for (char ch : word)
            {
                idx = find(mp[ch], idx, s);
                cout << idx << " ";
                if (idx == -1)
                    break;
            }

            cout << endl;

            if (idx != -1)
                ans++;
        }

        return ans;
    }
};
