// Invert Binary Tree

// Given the root of a binary tree, invert the tree, and return its root.

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        invert(root);
        return root;
    }
    void invert(TreeNode *root)
    {
        if (root == NULL)
            return;
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;
        invert(root->left);
        invert(root->right);
    }
};