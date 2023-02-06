/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
// 29.92% 82.55% 顺利地写出来的
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<vector<int>> dir = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dindex = 0; // left
        int tmp = 1;
        int curx = 0, cury = -1;
        while (tmp <= n * n)
        {
            int tmpx = curx + dir[dindex][0];
            int tmpy = cury + dir[dindex][1];
            if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < n && res[tmpx][tmpy] == 0)
            {
                curx = tmpx;
                cury = tmpy;
                res[curx][cury] = tmp;
                tmp++;
            }
            else
            { // 转向
                dindex = (dindex + 1) % 4;
            }
        }
        return res;
    }
};
// @lc code=end
// 100% 24.28%
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int t = 0;     // top
        int b = n - 1; // bottom
        int l = 0;     // left
        int r = n - 1; // right
        vector<vector<int>> ans(n, vector<int>(n));
        int k = 1;
        while (k <= n * n)
        {
            for (int i = l; i <= r; ++i, ++k)
                ans[t][i] = k;
            t++;
            for (int i = t; i <= b; ++i, ++k)
                ans[i][r] = k;
            r--;
            for (int i = r; i >= l; --i, ++k)
                ans[b][i] = k;
            b--;
            for (int i = b; i >= t; --i, ++k)
                ans[i][l] = k;
            l++;
        }
        return ans;
    }
};