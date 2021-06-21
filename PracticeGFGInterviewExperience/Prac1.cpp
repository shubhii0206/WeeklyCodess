//https://www.geeksforgeeks.org/amazon-interview-experience-sde-1-amazon-wow-2020/?ref=rp

//Q1.https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/

bool isSubset(vector<int> arr, vector<int> brr)
{
   int n = arr.size(), m = brr.size();
   unordered_set<int> s;

   for(int x: arr)
   s.insert(x);

   for(int x: brr)
    if(s.find(x) == s.end())
       return false;

   return true;

}

bool isSubset(vector<int> arr, vector<int> brr)
{


    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    int n = arr.size(), m = brr.size();

   int i =0, j =0;
    while(i < n && j < m)
    {

        if(arr[i] == brr[j])
        {
            i++; j++;
        }
        else if(arr[i] < brr[j])
        i++;
        else
        return false;

    }
    if(i < m)
       return false;

    return true;
}


//Q2 Number of Bomb blasts similar to number of connected islands, dfs
//https : //leetcode.com/problems/number-of-islands/submissions/

        class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        if (i == -1 || j == -1 || j == m || i == n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i, j - 1, m, n);
    }
    int numIslands(vector<vector<char>> &grid)
    {

        int n = grid.size(), m = grid[0].size(), islands = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return islands;
    }
};


//Q4 max level sum
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {

        if (root == nullptr)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int level = -1, currlevel = 0, maxSum = INT_MIN;

        while (!q.empty())
        {
            int n = q.size();
            int x = 0;
            currlevel++;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                x += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (x > maxSum)
            {
                maxSum = x;
                level = currlevel;
            }
        }

        return level;
    }
};

//Q4https://leetcode.com/problems/find-k-closest-elements/submissions/

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {

        int low = 0, high = arr.size() - k;

        while (low < high)
        {
            int mid = (low + high) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                low = mid + 1;
            else
                high = mid;
        }

        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};


//Sort linked list


