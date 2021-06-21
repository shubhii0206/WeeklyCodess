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
    void flatten(TreeNode *root)
    {

        if (root == nullptr)
            return;
        stack<TreeNode *> st;

        st.push(root);

        while (!st.empty())
        {
            TreeNode *x = st.top();
            st.pop();

            if (x->right != nullptr)
            {
                st.push(x->right);
            }

            if (x->left != nullptr)
            {
                st.push(x->left);
            }

            if (!st.empty())
            {
                x->right = st.top();
            }
            x->left = nullptr;
        }
    }
};