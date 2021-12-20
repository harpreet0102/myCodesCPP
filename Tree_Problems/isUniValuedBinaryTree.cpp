//  Univalued Binary Tree

// A binary tree is uni-valued if every node in the tree has the same value.

// Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        int val = root->val;
        return isUnival(root, val);
    }
    bool isUnival(TreeNode *root, int val)
    {
        if (root == NULL)
            return true;
        if (root->val != val)
            return false;
        bool a = isUnival(root->left, val);
        bool b = isUnival(root->right, val);
        return a && b;
    }
};