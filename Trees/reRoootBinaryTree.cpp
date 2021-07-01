//https://leetcode.ca/all/1666.html

class TreeNode{
    int val;
    TreeNode* right;
    TreeNode * left;
    TreeNode * parent;
    
}
TreeNode * flipBinaryTree(TreeNode * root, TreeNode *leaf)
{
    TreeNode * curr = leaf;
    TreeNode * newParent = nullptr;
    
    while(curr != root)
    {
       if(curr->left != nullptr)
       curr->right = curr->left;
    if(curr->parent !=  nullptr){
       curr->left = curr->parent;


       if(curr->parent->left == curr)
       curr->parent->left = nullptr;
       else
       curr->parent->right = nullptr;
    }

       curr->parent = newParent;
       newParent = curr;
       curr = curr->left;

    }

    curr->parent = newParent;
      return leaf;
    
    
    }