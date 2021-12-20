//TLE解法，看起来好像很简单，但是时间复杂度在insert函数
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int len = spaces.size();
        for (int i = len - 1; i >= 0; i--)
        {
            int tmp = spaces[i];
            s.insert(tmp, " ");
        }
        return s;
    }
};

// 官方题解思路
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int blen = spaces.size(); // blank length
        int slen = s.size();      // string length
        string ans;
        ans.reserve(blen + slen);
        // 2 pointer: i and j
        int j = 0;
        for (int i = 0; i < slen; i++)
        {
            if (j < blen && spaces[j] == i) //先后顺序不能写反
            {
                ans.push_back(' ');
                j++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
