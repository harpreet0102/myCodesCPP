// Sum of Root To Leaf Binary Numbers

// You are given the root of a binary tree where each node has a value 0 or 1.
//Each root - to - leaf path represents a binary number starting with the most significant bit.
// For example, if the path is 0->1->1->0->1, then this could represent 01101 in binary, which is 13.
// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
// Return the sum of these numbers.The answer is guaranteed to fit in a 32 - bits integer.

class Solution
{
public:
    int total = 0;
    int sumRootToLeaf(TreeNode *root)
    {
        sumRTL(root, 0);
        return total;
    }
    void sumRTL(TreeNode *root, int sum)
    {
        if (root == NULL)
            return;
        sum = sum * 2 + root->val; // converting binary to decimal.
        if (root->left == NULL && root->right == NULL)
            total += sum;
        sumRTL(root->left, sum);
        sumRTL(root->right, sum);
    }
};