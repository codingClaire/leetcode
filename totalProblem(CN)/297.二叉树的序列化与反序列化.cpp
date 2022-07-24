/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//[297] 二叉树的序列化与反序列化
// BFS
// 64.03 %  76.16 %
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int currentLevel = q.size();
            for (int i = 0; i < currentLevel; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node == NULL)
                    result += "None,";
                else
                {
                    result += to_string(node->val) + ",";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return result;
    }
    TreeNode *deBFS(list<string> &dataArray)
    {
        if (dataArray.front() == "None")
            return NULL;
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(stoi(dataArray.front()));
        q.push(root);
        dataArray.erase(dataArray.begin());
        while (!q.empty() && !dataArray.empty())
        {
            int currentLevel = q.size();
            for (int i = 0; i < currentLevel && !dataArray.empty(); i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (dataArray.front() != "None")
                {
                    TreeNode *leftnode = new TreeNode(stoi(dataArray.front()));
                    node->left = leftnode;
                    q.push(leftnode);
                }
                else
                {
                    node->left = NULL;
                }
                dataArray.erase(dataArray.begin());
                if (dataArray.front() != "None")
                {
                    TreeNode *rightnode = new TreeNode(stoi(dataArray.front()));
                    node->right = rightnode;
                    q.push(rightnode);
                }
                else
                {
                    node->right = NULL;
                }
                dataArray.erase(dataArray.begin());
            }
        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        list<string> dataArray;
        string tmp;
        for (auto &d : data)
        {
            if (d == ',')
            {
                dataArray.push_back(tmp);
                tmp.clear();
            }
            else
            {
                tmp.push_back(d);
            }
        }
        if (!tmp.empty())
        {
            dataArray.push_back(tmp);
            tmp.clear();
        }

        return deBFS(dataArray);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//[297] 二叉树的序列化与反序列化
// DFS
// 39.74 % 23.13 %
class Codec
{
public:
    void DFS(TreeNode *root, string &result)
    {
        if (root == NULL)
        {
            result += "None,"; // Remember the comma
        }
        else
        {
            result += to_string(root->val) + ",";
            DFS(root->left, result);
            DFS(root->right, result);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string result;
        DFS(root, result);
        return result;
    }

    TreeNode *deDFS(list<string> &dataArray)
    {
        if (dataArray.front() == "None")
        {
            dataArray.erase(dataArray.begin());
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = deDFS(dataArray);
        root->right = deDFS(dataArray);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        list<string> dataArray;
        string tmp;
        for (auto &d : data)
        {
            if (d == ',')
            {
                dataArray.push_back(tmp);
                tmp.clear();
            }
            else
            {
                tmp.push_back(d);
            }
        }
        if (!tmp.empty())
        {
            dataArray.push_back(tmp);
            tmp.clear();
        }
        return deDFS(dataArray);
    }
};

