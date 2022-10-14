/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
// 29.19 % 55.62 %
struct TrieNode{
    string word;
    unordered_map<char,TrieNode*> nexts;
    TrieNode()
    {
        this->word = "";
    }
};

class Trie
{
private:
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        
        TrieNode *cur = root;
        for (auto &ch: word)
        {
            if (!cur->nexts.count(ch))
            {
                cur->nexts[ch] = new TrieNode();
            }
            cur = cur->nexts[ch];
        }
        // 在最后添加word
        cur->word = word;
    }

    bool search(string word)
    {
        TrieNode* cur = root;
        for (auto &ch : word)
        {
            
            if (!cur->nexts.count(ch))
                return false;
            cur = cur->nexts[ch];

        }
        if(cur->word!="")
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        for (auto &ch : prefix)
        {
            if (!cur->nexts.count(ch))
                return false;
            cur = cur->nexts[ch];
            /*这样会改变unordered_map的键值 不能这样写
            cur = cur->nexts[ch];
            if(cur == nullptr)
                return false;
            */
        }
        return true;

    }
};

/*
 * ["Trie","insert","search","search","startsWith","startsWith","insert","search","startsWith","insert","search","startsWith"]
 * [[],["ab"],["abc"],["ab"],["abc"],["ab"],["ab"],["abc"],["abc"],["abc"],["abc"],["abc"]]
 *
 *Your Trie object will be instantiated and called as such : *Trie *obj = new Trie();
 *obj->insert(word);
 *bool param_2 = obj->search(word);
 *bool param_3 = obj->startsWith(prefix);
*/
    // @lc code=end
