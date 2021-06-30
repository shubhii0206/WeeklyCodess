//https : //leetcode.com/problems/minimum-domino-rotations-for-equal-row/submissions/
        class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        unordered_map<int, int> freqOfNumber;
        int dominos = tops.size();
        for (int x : tops) //3 -> 5, 1 ->1, 5->1, 2->1, 6->1, 4->1
            freqOfNumber[x]++;
        for (int x : bottoms)
            freqOfNumber[x]++;

        vector<int> possibleNumber;
        for (auto it = freqOfNumber.begin(); it != freqOfNumber.end(); it++)
        {
            if (it->second >= dominos)
                possibleNumber.push_back(it->first);
        }

        int ans = INT_MAX;
        for (int x : possibleNumber)
        {
            int top = 0, bottom = 0, a, allpresent = 0;
            for (int i = 0; i < dominos; i++)
            {
                if (tops[i] != x && bottoms[i] != x)
                    break;
                if (tops[i] == x)
                    top++;
                if (bottoms[i] == x)
                    bottom++;
                allpresent++;
            }
            if ((top == 0 && bottom == 0) || allpresent != dominos)
                continue;
            ans = min(ans, dominos - max(top, bottom));
        }

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};