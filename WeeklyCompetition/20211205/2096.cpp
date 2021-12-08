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
//官方题解
class Solution
{
public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        unordered_map<TreeNode *, TreeNode *> fa; // 父节点哈希表
        TreeNode *s = nullptr;                    // 起点节点
        TreeNode *t = nullptr;                    // 终点节点

        // 深度优先搜索维护哈希表与起点终点
        function<void(TreeNode *)> dfs = [&](TreeNode *curr)
        {
            if (curr->val == startValue)
            {
                s = curr;
            }
            if (curr->val == destValue)
            {
                t = curr;
            }
            if (curr->left)
            {
                fa[curr->left] = curr;
                dfs(curr->left);
            }
            if (curr->right)
            {
                fa[curr->right] = curr;
                dfs(curr->right);
            }
        };

        dfs(root);

        // 求出根节点到对应节点的路径字符串
        function<string(TreeNode *)> path = [&](TreeNode *curr)
        {
            string res;
            while (curr != root)
            {
                TreeNode *par = fa[curr];
                if (curr == par->left)
                {
                    res.push_back('L');
                }
                else
                {
                    res.push_back('R');
                }
                curr = par;
            }
            reverse(res.begin(), res.end());
            return res;
        };

        string path1 = path(s);
        string path2 = path(t);
        // 计算最长公共前缀并删去对应部分，同时将 path_1 逐字符修改为 'U'
        int l1 = path1.size(), l2 = path2.size();
        int i = 0;
        while (i < min(l1, l2))
        {
            if (path1[i] == path2[i])
            {
                ++i;
            }
            else
            {
                break;
            }
        }
        string finalpath(l1 - i, 'U'); // 最短路径对应字符串
        finalpath.append(path2.substr(i, l2 - i));
        return finalpath;
    }
};
//改写，但是这个版本会TLE
//官方题解的时间空间复杂度都挺高的
class Solution
{
public:
    TreeNode *s = nullptr; // start point
    TreeNode *t = nullptr;// destination point
    unordered_map<TreeNode *, TreeNode *> fa; //father dict

    void DFS(TreeNode *current, int startValue, int destValue)
    {
        if (current->val == startValue)
            s = current;
        if (current->val == destValue)
            t = current;
        if (current->left != NULL)
        {
            fa[current->left] = current;
            DFS(current->left, startValue, destValue);
        }
        if (current->right != NULL)
        {
            fa[current->right] = current;
            DFS(current->right, startValue, destValue);
        }
    }

    string getPath(TreeNode *root,TreeNode *current)
    {//从root到current的路径，自底向上地增加方向，最后需要反转路径
        string path="";
        while(current!=root){
            TreeNode * father=fa[current];
            if(father->left ==current)
                path.push_back('L');
            if(father->right ==current)
                path.push_back('R');
            current=father;
        }
        reverse(path.begin(), path.end());
        return path; 
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        DFS(root, startValue, destValue); // 维护start dest和father dict
        string path1 = getPath(root,s);
        string path2 = getPath(root,t);
        int l1 = path1.size(), l2 = path2.size();
        int prenum = 0;
        while (prenum < min(l1, l2))
        {
            if (path1[prenum] == path2[prenum])
                prenum++;
        }
        string finalpath(l1 - prenum, 'U');
        finalpath.append(path2.substr(prenum, l2 - prenum)); //从prenum开始的l2-prenum个字符
        return finalpath;
    }
};