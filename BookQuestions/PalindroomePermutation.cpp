//https://www.lintcode.com/problem/palindrome-permutation-ii/description
brute force soln approach(n^2 * n!), tc - O(__cpp_nsdmi)
bool isPalindrome(string s)
{
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
void allPermutations(string str, string prefix, unordered_set<string> &ans)
{
    if (str.size() == 0)
    {
        ans.insert(prefix);
    }
    else
        for (int i = 0; i < str.size(); i++)
        {
            string rem = str.substr(0, i) + str.substr(i + 1);
            allPermutations(rem, prefix + str[i], ans);
        }
}
vector<string> generatePalindromes(string &s)
{
    vector<string> palindromes;
    unordered_set<string> ans;

    allPermutations(s, "", ans);

    for (string x : ans)
    {
        cout << x << " ";
        if (isPalindrome(x))
            palindromes.push_back(x);
    }

    return palindromes;
}
