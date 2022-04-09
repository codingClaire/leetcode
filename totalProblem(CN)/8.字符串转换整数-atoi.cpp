/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
// 67.09% 64.01%
class Solution
{
public:
    long strToNum(string s, long num)
    {
        long ret_num = 0;
        int final_num = 0;
        if (s.length() > 10 && num == 1)
            final_num = INT_MAX;
        else if (s.length() > 10 && num == -1)
            final_num = INT_MIN;
        else
        {
            long n = 1;
            for (int i = s.length() - 1; i >= 0; i--)
            {
                ret_num += (s[i] - '0') * n;
                n *= 10;
            }
            ret_num = num * ret_num;
            if (ret_num > INT_MAX)
                final_num = INT_MAX;
            else if (ret_num < INT_MIN)
                final_num = INT_MIN;
            else
                final_num = int(ret_num);
        }
        return final_num;
    }

    bool isNum(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    int myAtoi(string s)
    {
        int res = 0;
        int idx = 0;
        long num;
        //起始是字符的情况，直接返回0
        if (!isNum(s[idx]) && s[idx] != ' ' && s[idx] != '+' && s[idx] != '-')
            return res;
        //删除空格
        while (s[idx] == ' ')
        {
            idx++;
        }
        //判断正负号
        if (s[idx] == '-')
        {
            num = -1;
            idx++;
        }
        else 
        {
            num = 1;
            if (s[idx] == '+')
                idx++;
        }
        //前导0删除
        while (s[idx] == '0')
            idx++;
        //无符号的不含前导零开始的字符串
        string tmp = s.substr(idx, s.length() - idx);
        //删除后续字符串
        idx = 0;
        while (isNum(tmp[idx]))
        {
            idx++;
        }
        string nums = tmp.substr(0, idx);
        res = strToNum(nums, num);
        return res;
    }
};

// @lc code=end
// 18.22% 23.19%
class Solution
{
public:
    long strToNum(string s, long num)
    {
        long ret_num = 0;
        if (s.length() > 10 && num == 1)
            ret_num = INT_MAX;
        else if (s.length() > 10 && num == -1)
            ret_num = INT_MIN;
        else
        {
            long n = 1;
            for (int i = s.length() - 1; i >= 0; i--)
            {
                ret_num += (s[i] - '0') * n;
                n *= 10;
            }
            ret_num = num * ret_num;
        }
        return ret_num;
    }

    bool isNum(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    int myAtoi(string s)
    {
        int res = 0;
        int idx = 0;
        long num;
        if (!isNum(s[idx]) && s[idx] != ' ' && s[idx] != '+' && s[idx] != '-')
            return res;
        while (s[idx] == ' ')
        {
            idx++;
        }
        if (s[idx] == '-')
        {
            num = -1;
            idx++;
        }
        else if (s[idx] == '+')
        {
            num = 1;
            idx++;
        }
        else
        {
            num = 1;
        }
        while (s[idx] == '0')
        {
            idx++;
        }
        string tmp = s.substr(idx, s.length() - idx);
        idx = 0;
        while (isNum(tmp[idx]))
        {
            idx++;
        }
        string nums = tmp.substr(0, idx);
        num = strToNum(nums, num);
        if (num > INT_MAX)
            res = INT_MAX;
        else if (num < INT_MIN)
            res = INT_MIN;
        else
            res = int(num);
        return res;
    }
};

/*
值得学习的评论区代码：

class Solution {
    public int myAtoi(String str) {
        str = str.trim();
        if (str.length() == 0) return 0;
        if (!Character.isDigit(str.charAt(0))
            && str.charAt(0) != '-' && str.charAt(0) != '+')
            return 0;
        int ans = 0;
        boolean neg = str.charAt(0) == '-';
        int i = !Character.isDigit(str.charAt(0)) ? 1 : 0;
        while (i < str.length() && Character.isDigit(str.charAt(i))) {
            int tmp = ((neg ? Integer.MIN_VALUE : Integer.MIN_VALUE + 1) + (str.charAt(i) - '0')) / 10;
            if (tmp > ans) {
                return neg ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            ans = ans * 10 - (str.charAt(i++) - '0');
        }
        return neg ? ans : -ans;
    }
}


*/