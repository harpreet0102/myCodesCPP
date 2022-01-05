// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

// O(n) time O(logn) space
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        TreeNode *root1 = root, *root2 = root;
        while (root1 != NULL)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2 != NULL)
        {
            s2.push(root2);
            root2 = root2->right;
        }
        TreeNode *left1 = s1.top();
        TreeNode *right2 = s2.top();
        int curr;
        while (left1 != right2)
        {

            cout << left1->val << " " << right2->val;
            curr = left1->val + right2->val;
            if (curr == k)
                return true;
            else if (curr < k)
            {
                if (left1->right != NULL)
                {
                    left1 = left1->right;
                    s1.pop();
                    while (left1 != NULL)
                    {
                        s1.push(left1);
                        left1 = left1->left;
                    }
                }
                else
                    s1.pop();
            }
            else
            {
                if (right2->left != NULL)
                {
                    right2 = right2->left;
                    s2.pop();
                    while (right2 != NULL)
                    {
                        s2.push(right2);
                        right2 = right2->right;
                    }
                }
                else
                    s2.pop();
            }
            left1 = s1.top(), right2 = s2.top();
        }
        return false;
    }
};

// O(n) time O(n) space using unordered_set or two pointer

class Solution
{
public:
    unordered_set<int> s;
    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
            return false;
        if (s.find(k - root->val) != s.end())
            return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};