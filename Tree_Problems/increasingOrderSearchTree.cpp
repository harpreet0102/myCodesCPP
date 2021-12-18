// Increasing Order Search Tree

// Given the root of a binary search tree, rearrange the tree in in - order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *dummy = new TreeNode(-1);
        TreeNode *previous = dummy;
        inorder(previous, root);
        previous->left = NULL;
        previous->right = NULL;
        return dummy->right;
    }
    void inorder(TreeNode *&previous, TreeNode *current)
    {
        if (current == NULL)
            return;
        inorder(previous, current->left);
        previous->left = NULL;
        previous->right = current;
        previous = current;
        inorder(previous, current->right);
    }
};