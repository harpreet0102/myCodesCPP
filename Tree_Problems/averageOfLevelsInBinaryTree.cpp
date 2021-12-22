// Average of Levels in Binary Tree

// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
// Answers within 10 - 5 of the actual answer will be accepted.

// RECURSIVE SOLUTION

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        int heightOfTree = height(root);
        vector<double> v;
        for (int i = 0; i < heightOfTree; i++)
        {
            double num = 0;
            double a = avg(num, root, i) / num;
            v.push_back(a);
        }
        return v;
    }
    int height(TreeNode *root) // Calculating height of a binary tree
    {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    double avg(double &countOfElements, TreeNode *root, int level)
    {
        double sum = 0;
        if (root == NULL)
            return 0;
        if (level == 0)
        {
            sum = root->val;
            countOfElements += 1;
            return sum;
        }
        sum = avg(countOfElements, root->left, level - 1) + avg(countOfElements, root->right, level - 1);
        return sum;
    }
};

// QUEUE SOLUTION

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> average;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            long long int sum = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            average.push_back(sum / double(size));
        }
        return average;
    }
};
