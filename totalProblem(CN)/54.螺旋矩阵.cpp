/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
// 100 %  81.67 %
// 二刷 没能特别熟练！！
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int n = matrix[0].size();
        int m = matrix.size();
        int up = 0, down = m - 1, left = 0, right = n - 1;
        int curm = 0, curn = 0;
        int dir = 1;
        if (n == 1)
        {
            for (int i = 0; i < matrix.size(); i++)
                res.emplace_back(matrix[i][0]);
            return res;
        }
        while (res.size() < m * n)
        {
            res.emplace_back(matrix[curm][curn]);
            switch (dir)
            {
            case 1:
                curn++;
                break;
            case 2:
                curm++;
                break;
            case 3:
                curn--;
                break;
            case 4:
                curm--;
                break;
            }
            if (dir == 4 && curm == up && curn == left)
            {
                left++;
                dir = 1;
            }
            else if (dir == 1 && curm == up && curn == right)
            {
                up++;
                dir = 2;
            }
            else if (dir == 2 && curm == down && curn == right)
            {
                right--;
                dir = 3;
            }
            else if (dir == 3 && curm == down && curn == left)
            {
                down--;
                dir = 4;
            }
        }

        return res;
    }
};
//[[3],[2]]
//[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
// @lc code=end

// 100 %  74.02 %
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        //当前的遍历的最大宽度和最大高度
        //当向左或向右遍历结束后，最大高度-1
        //当向上或向下遍历结束后，最大宽度-1
        int curw = n, curh = m;
        //当前遍历到的位置，初始设为0，-1 后面的case 0会比较优雅
        int curm = 0, curn = -1;
        int time = 0;
        while (res.size() < m * n)
        {
            // time是次数，注意到螺旋遍历的顺序是一定的(右下左上)
            //每次遍历的时候是从下一个开始遍历，因为当前的已经在上一轮遍历完了
            switch (time % 4)
            {
            case 0: // 向右
                for (int i = curn + 1; i <= curn + curw; i++)
                    res.emplace_back(matrix[curm][i]);
                curn = curn + curw;
                curh--;
                break;
            case 1: // 向下
                for (int i = curm + 1; i <= curm + curh; i++)
                    res.emplace_back(matrix[i][curn]);
                curm = curm + curh;
                curw--;
                break;
            case 2: // 向左
                for (int i = curn - 1; i >= curn - curw; i--)
                    res.emplace_back(matrix[curm][i]);
                curn = curn - curw;
                curh--;
                break;
            case 3: // 向上
                for (int i = curm - 1; i >= curm - curh; i--)
                    res.emplace_back(matrix[i][curn]);
                curm = curm - curh;
                curw--;
                break;
            }
            time++;
        }
        return res;
    }
};