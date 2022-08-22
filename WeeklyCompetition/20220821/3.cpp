// 无语了，周赛没注释输出导致TLE了最后一个
//我还以为是什么边界条件呢...
class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> mp;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();

                q.pop();
                if (node->left)
                {
                    mp[node->val].emplace_back(node->left->val);
                    mp[node->left->val].emplace_back(node->val);
                    q.push(node->left);
                }
                if (node->right)
                {
                    mp[node->val].emplace_back(node->right->val);
                    mp[node->right->val].emplace_back(node->val);
                    q.push(node->right);
                }
            }
        }
        // BFS again
        queue<int> graphq;
        graphq.push(start);
        int res = -1;
        bool isvisited[1000000] = {0};
        while (!graphq.empty() && mp.size() > 0)
        {
            int size = graphq.size();
            res++;
            for (int i = 0; i < size; i++)
            {
                auto node = graphq.front();
                isvisited[node] = 1;

                graphq.pop();
                for (int j = 0; j < mp[node].size(); j++)
                {
                    if (isvisited[mp[node][j]] == 0)
                    {
                        graphq.push(mp[node][j]);
                    }
                }
            }
        }
        return res == -1 ? 0 : res;
    }
};
