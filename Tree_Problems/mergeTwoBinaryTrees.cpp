// Merge two binary trees

// You are given two binary trees root1 and root2. Imagine that when you put one of them to cover the other,
// some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree.
// The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
// Otherwise, the NOT null node will be used as the node of the new tree. Return the merged tree.

// Note: The merging process must start from the root nodes of both trees.

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return NULL;
        else if (root1 == NULL)
            return root2;
        else if (root2 == NULL)
            return root1;
        TreeNode *temp = new TreeNode(root1->val + root2->val);
        temp->left = mergeTrees(root1->left, root2->left);
        temp->right = mergeTrees(root1->right, root2->right);
        return temp;
    }
};