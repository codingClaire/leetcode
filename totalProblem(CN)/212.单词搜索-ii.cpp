/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
// 9.04% 77.96%
struct TrieNode
{
    string word; // 存储叶子节点的路径转化成的
    unordered_map<char, TrieNode *> children;
    TrieNode()
    {
        this->word = "";
    }
};

void insertTrie(TrieNode *root, const string &word)
{
    TrieNode *node = root;
    // 遍历word的每一个字符
    for (auto ch : word)
    {
        // 不存在ch
        if (!node->children.count(ch))
        {
            // 增加节点
            node->children[ch] = new TrieNode();
        }
        // 类似添加链表节点
        node = node->children[ch];
    }
    // 把word存到对应的节点里
    node->word = word;
}

class Solution
{
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool DFS(vector<vector<char>> &board, int x, int y, TrieNode *root, set<string> &res)
    {
        char ch = board[x][y];
        if (!root->children.count(ch))
            return false;
        root = root->children[ch];
        if (root->word.size() > 0)
        {
            // 到叶子节点了
            res.insert(root->word);
        }
        //防止取重复，所以要改为# 结束了再改回来
        board[x][y] = '#';
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dirs[i][0];
            int next_y = y + dirs[i][1];
            if (next_x >= 0 && next_x < board.size() && next_y >= 0 && next_y < board[0].size())
            {
                if (board[next_x][next_y] != '#')
                {
                    DFS(board, next_x, next_y, root, res);
                }
            }
        }
        board[x][y] = ch;
        return true;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        // 创建新的字典树
        TrieNode *root = new TrieNode();
        set<string> res;
        vector<string> ans;
        // 将所有词插入字典树
        for (auto &word : words)
            insertTrie(root, word);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                DFS(board, i, j, root, res);
            }
        }
        for (auto &word : res)
        {
            ans.emplace_back(word);
        }
        return ans;
    }
};
// @lc code=end
