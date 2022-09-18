/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        deque<TreeNode *> q;
        q.emplace_back(root);
        bool reverse = false;
        while (!q.empty())
        {
            int curSize = q.size();
            vector<int> level;
            for (int i = 0; i < curSize; i++)
            {
                if (reverse == true) // reverse
                {
                    TreeNode *node = q.front();
                    q.pop_front();
                    level.emplace_back(node->val);
                    if (node->right != NULL)
                        q.emplace_back(node->right);
                    if (node->left != NULL)
                        q.emplace_back(node->left);
                }
                else
                { // normal
                    TreeNode *node = q.back();
                    q.pop_back();
                    level.emplace_back(node->val);
                    if (node->left != NULL)
                        q.emplace_front(node->left);
                    if (node->right != NULL)
                        q.emplace_front(node->right);
                }
            }
            res.emplace_back(level);
            reverse = !reverse;
        }
        return res;
    }

    // addNode()

    TreeNode *reverseOddLevels(TreeNode *root)
    {
        vector<vector<int>> res = zigzagLevelOrder(root);
        TreeNode *newNode = new TreeNode(root->val);
        queue<TreeNode *> q;
        q.push(newNode);
        int curLevel = 1;
        while (curLevel<res.size() && !q.empty())
        {
            for(int i=0;i<res[curLevel].size();i+=2)
            {
                TreeNode *node = q.front();
                q.pop();
                node->left = new TreeNode(res[curLevel][i]);
                node->right = new TreeNode(res[curLevel][i+1]);
                q.push(node->left);
                q.push(node->right);
            }
            curLevel++;
        }
        return newNode;
    }
};