/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
//[76] 最小覆盖子串
// 24.46 % 73.17 %
class Solution
{
public:
    unordered_map<char, int> ori,cnt;
    //cnt是一个记录当前滑动窗口内字符数量的map
    bool check()
    {
        for(const auto &p: ori)
        {
            //当前字母作为cnt的键得到的值
            // 小于t要求的该字母的频数的情况
            if(cnt[p.first]<p.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        for (int i = 0; i < t.length(); i++)
        {
            ++ori[t[i]];
        }
        int minleft = -1, minright = -1;
        int minlen = INT_MAX;
        int l = 0, r = -1;
        // 一个疑问： 为什么这里必须用int(s.length())呢？
        while (r < int(s.length()))
        {
            if(ori.find(s[++r])!=ori.end())
            {// 逐个累计s中的字母出现频数
                ++cnt[s[r]];
            }
            //右移，直到check为真才会进入以下的代码
            while(check()&&l<=r)
            { //开始滑动窗口左移
                if(r-l+1<minlen)
                {//此时还满足，那么就更新minleft和minlen
                    minlen = r - l + 1;
                    minleft = l;
                }
                //左移之后，如果是t要求的字符
                if(ori.find(s[l])!=ori.end())
                {//那么就将当前的减少1个
                    --cnt[s[l]];
                }
                l++;
            }
        }

        return minlen == INT_MAX? string():s.substr(minleft, minlen);
    }
};
// @lc code=end
