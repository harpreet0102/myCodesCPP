// Range Sum of BST

// Given the root node of a binary search tree and two integers low and high,
// return the sum of values of all nodes with a value in the inclusive range [low, high].

class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return 0;
        int sum = 0, left = 0, right = 0;
        if (root->val >= low && root->val <= high)
            sum = root->val;
        left = rangeSumBST(root->left, low, high);
        right = rangeSumBST(root->right, low, high);
        return sum + left + right;
    }
};