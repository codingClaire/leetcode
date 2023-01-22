/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */

// @lc code=start
// 28.95 %  84.19 %
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int startx = coordinates[1][0] - coordinates[0][0];
        int starty = coordinates[1][1] - coordinates[0][1];
        for (int i = 1; i < coordinates.size(); i++)
        {
            int deltax = coordinates[i][0] - coordinates[0][0];
            int deltay = coordinates[i][1] - coordinates[0][1];
            if(deltax * starty != startx*deltay)
                return false;
        }
        return true;
    }
};
// @lc code=end
