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
        //起始是字母的情况，直接返回0
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
/*
值得学习的评论区代码：

class Solution {
    public int myAtoi(String str) {
        str = str.trim();// 删除空格
        if (str.length() == 0) return 0; //长度为0
        // 开头是字母的情况
        if (!Character.isDigit(str.charAt(0))
            && str.charAt(0) != '-' && str.charAt(0) != '+')
            return 0;
        int ans = 0;
        //判断数字是正负号
        boolean neg = str.charAt(0) == '-';
        //如果开头有符号去除符号
        int i = !Character.isDigit(str.charAt(0)) ? 1 : 0;
        //当i是数字且小于字符串长度时
        while (i < str.length() && Character.isDigit(str.charAt(i))) {
            //负数是Integer.MIN_VALUE，正数是Integer.MIN_VALUE + 1
            int tmp = ((neg ? Integer.MIN_VALUE : Integer.MIN_VALUE + 1) + (str.charAt(i) - '0')) / 10;
            if (tmp > ans) {
                return neg ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            //当前数乘10（类似10进制的左移，再减去下一个数（因为是负数）
            ans = ans * 10 - (str.charAt(i++) - '0');
        }
        //最后正数再取反
        return neg ? ans : -ans;
    }
}


*/