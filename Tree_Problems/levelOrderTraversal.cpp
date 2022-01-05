// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// O(n) time and O(n) space for queue usage. Here it is O(n^2) and o(n^2)----> DOUBT(ASK)

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);

        while (q.empty() == false)
        {
            vector<int> v;
            int qlen = q.size();
            for (int i = 1; i <= qlen; i++)
            {
                TreeNode *temp = q.front();
                if (temp == NULL)
                    break;
                v.push_back(temp->val);
                q.pop();
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            res.push_back(v);
        }
        return res;
    }
};