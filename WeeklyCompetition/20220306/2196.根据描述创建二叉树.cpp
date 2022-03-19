class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        set<int> children; //子节点的id,除了根节点的id，所有的id都在这里
        unordered_map<int, TreeNode *> tree; //整个树，key是节点的value，因为题目说value各不相同
        for (int i = 0; i < descriptions.size(); i++)
        {
            int father_id = descriptions[i][0], son_id = descriptions[i][1], flag = descriptions[i][2];
            TreeNode *son;
            TreeNode *fa;
            //父节点
            if (tree.count(father_id) == 0)
            {
                fa = new TreeNode(father_id);
                tree.insert(make_pair(father_id, fa));
            }
            else
            {
                //父节点存在时，fa指向父节点
                fa = tree[father_id];
            }
            //子节点
            if (tree.count(son_id) == 0)
            {
                son = new TreeNode(son_id);
                tree.insert(make_pair(son_id, son));
            }
            else
            {
                //子节点存在时，fa指向子节点
                son = tree[son_id];
            }
            //建立左右节点的关系
            if (flag == 0)
            {
                fa->right = son;
            }
            else
            {
                fa->left = son;
            }
            children.insert(son_id); //保存子节点id
        }
        //确定根节点
        TreeNode *root;
        for (unordered_map<int, TreeNode *>::iterator iter = tree.begin(); iter != tree.end(); iter++)
        {
            if (children.count(iter->first) == 0)
            {
                root = iter->second;
                break;
            }
        }
        return root;
    }
};

/* TLE解法
class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        vector<TreeNode *> root_candidate;
        vector<TreeNode *> tree;
        for (int i = 0; i < descriptions.size(); i++)
        {
            TreeNode *son;
            TreeNode *fa;
            if (tree.size() == 0)
            {
                fa = new TreeNode(descriptions[0][0]);
                son = new TreeNode(descriptions[0][1]);
                tree.emplace_back(fa);
                tree.emplace_back(son);
            }
            for (int j = 0; j < tree.size(); j++)
            {
                if (tree[j]->val == descriptions[i][0])
                { // father exist
                    fa = tree[j];
                }
                else
                { // father doesn't exist
                    fa = new TreeNode(descriptions[i][0]);
                    tree.emplace_back(fa);
                }

                if (tree[j]->val == descriptions[i][1])
                {
                    son = tree[j];
                }
                else
                {
                    son = new TreeNode(descriptions[i][1]);
                    tree.emplace_back(son);
                }
            }
            if (descriptions[i][2] == 0)
            {
                fa->right = son;
            }
            else
            {
                fa->left = son;
            }
            root_candidate.emplace_back(fa);
            for (vector<TreeNode *>::iterator it = root_candidate.begin(); it != root_candidate.end(); it++)
            {
                if (*it == son)
                {
                    root_candidate.erase(it);
                    break;
                }
            }
            break;
        }
        return root_candidate[0];
    }
};
*/