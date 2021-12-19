// Binary Tree Inorder Traversal

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// 1. RECURSIVE APPROACH
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

// 2. ITERATIVE APPROACH(USING STACK)
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        iterative(root, res);
        return res;
    }
    void iterative(TreeNode *root, vector<int> &res)
    {
        stack<TreeNode *> s;

        while (root || !s.empty())
        {
            //keep moving towards left
            while (root)
            {
                s.push(root);
                root = root->left;
            }

            //backtrack and pick up most recent element
            root = s.top();
            s.pop();

            //push recent element in res
            res.push_back(root->val);

            //move towards right
            root = root->right;
        }
    }
};
