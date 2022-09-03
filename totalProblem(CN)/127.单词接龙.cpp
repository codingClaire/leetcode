// 59.12 % 17.82%
class Solution
{
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;
    void addWord(string &word)
    {
        if (!wordId.count(word))
        {
            wordId[word] = nodeNum++;
            //添加空列表
            edge.emplace_back();
        }
    }

    void addEdge(string &word)
    {
        addWord(word);
        int id = wordId[word];
        for (auto &ch : word)
        {
            char tmp = ch;
            ch = '*';
            // 添加带*的单词
            addWord(word);
            int new_id = wordId[word];
            edge[new_id].emplace_back(id);
            edge[id].emplace_back(new_id);
            ch = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        for (auto &word : wordList)
            addEdge(word);
        addEdge(beginWord);
        if (!wordId.count(endWord))
            return 0;
        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord];
        int endId = wordId[endWord];
        dis[beginId] = 0;
        // BFS的模板
        queue<int> q;
        q.push(beginId);
        while (!q.empty())
        {
            int id = q.front();
            q.pop();
            if (id == endId)
                return dis[endId] / 2 + 1;
            // 遍历当前id的所有相邻的id
            for (auto &next_id : edge[id])
            {
                if (dis[next_id] == INT_MAX)
                {
                    dis[next_id] = dis[id] + 1;
                    q.push(next_id);
                }
            }
        }
        return 0;
    }
};