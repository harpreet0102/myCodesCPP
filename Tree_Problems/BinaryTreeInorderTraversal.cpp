// Binary Tree Inorder Traversal

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

class Solution
{
public:
    vector<int> v;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return v;
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
        return v;
    }
};
