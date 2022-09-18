class Solution
{
private:
    int son[1010][26]; //存储Trie树中的子节点
    vector<int> cnt=vector<int>(1010); //存储的是以当前结尾的字符串有多少个
    int idx=0; //idx存储当前用到的那个下标（下标是0的点，既是根节点，又是空节点）

    void insert(string str)
    {
        int p=0;//根节点
        for(int i=0;i<str.length();i++)//判断是不是走到最后
        {
            int u=str[i]-'a';//当前字母子节点的编号
            if(!son[p][u])  
                son[p][u]=++idx;//如果当前子节点不存在就创造一个点来存储子节点
            p=son[p][u];//让p走到子节点的位置
        }
        cnt[p]++;//结尾是p的字符串个数加加
    }

    int query(string str)
    {
        int p=0;//根节点
        for(int i=0;i<str.length();i++)//判断是不是走到最后
        {
            int u=str[i]-'a';//当前字母子节点的编号
            if(!son[p][u])  
                return 0;//如果当前字符不存在那么直接返回0
            p=son[p][u];//让p走到子节点的位置
        }
        return cnt[p];//最后返回以p结尾的字符串个数
    }

public:
    vector<int> sumPrefixScores(vector<string> &words)
    {

        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i]);
        }
        vector<int> res;
        for (int i = 0; i < words.size(); i++)
        {
            int tmp = 0;
            for (int j = 1; j <= words[i].length(); j++)
            {
                string qstr = words[i].substr(0, j);
                //cout<<qstr<<" "<<query(qstr)<<endl;
                tmp += query(qstr);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
////////////////////////////////////////////////////
// TLE
class Solution
{
private:
    unordered_map<string, int> mp;

public:
    vector<int> sumPrefixScores(vector<string> &words)
    {

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 1; j <= words[i].length(); j++)
            {
                mp[words[i].substr(0, j)] += 1;
            }
        }
        vector<int> res;
        for (int i = 0; i < words.size(); i++)
        {
            int tmp = 0;
            for (int j = 1; j <= words[i].length(); j++)
            {
                tmp += mp[words[i].substr(0, j)];
            }
            res.emplace_back(tmp);
        }

        return res;
    }
};