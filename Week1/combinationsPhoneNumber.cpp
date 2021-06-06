class Solution
{
public:
    void Comb(string digits, vector<string> &ans, string combination, vector<string> keyPad)
    {
        if (digits.size() == 0)
        {
            ans.push_back(combination);

            return;
        }

        char ch = digits[0];
        string ros = digits.substr(1);

        string p = keyPad[ch - '0'];
        //cout<<ros<<" ";
        for (char chcode : p)
        {

            Comb(ros, ans, combination + chcode, keyPad);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> keyPad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        if (digits == "")
            return ans;
        string combination = "";
        Comb(digits, ans, combination, keyPad);

        return ans;
    }
};