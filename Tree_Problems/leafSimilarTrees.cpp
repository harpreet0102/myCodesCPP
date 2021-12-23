// Leaf - Similar Trees

// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

// Two binary trees are considered leaf - similar if their leaf value sequence is the same.
// Return true if and only if the two given trees with head nodes root1 and root2 are leaf similar.

class Solution
{
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaf1;
        vector<int> leaf2;
        leaf(leaf1, root1);
        leaf(leaf2, root2);
        // for(auto i:leaf1)
        //     cout << i << " ";
        // cout <<endl;                    // PRINTING VECTOR
        // for(auto j:leaf2)
        //     cout << j << " ";
        if (leaf1 == leaf2)
            return true;
        return false;
    }
    void leaf(vector<int> &v, TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            v.push_back(root->val);
            return;
        }
        leaf(v, root->left);
        leaf(v, root->right);
    }
};
