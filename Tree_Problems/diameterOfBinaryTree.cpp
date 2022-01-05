// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

// O(n)

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        rec(root, d);
        return d;
    }

    int rec(TreeNode *root, int &d)
    {
        if (root == NULL)
            return 0;
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d = max(d, ld + rd);
        return max(ld, rd) + 1;
    }
};

//  O(n^2)

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftSubtreeHeight = height(root->left);
        int rightSubtreeHeight = height(root->right);
        int present = leftSubtreeHeight + rightSubtreeHeight;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        return max(present, max(left, right));
    }
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
