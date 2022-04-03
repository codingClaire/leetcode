/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
// 100 % 30.19 %
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};

// @lc code=end

// 46.44 %  37.77 %
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};
/*
reverse函数：

template <class BidirectionalIterator>
  void reverse (BidirectionalIterator first, BidirectionalIterator last)
{
  while ((first!=last)&&(first!=--last)) {
    std::iter_swap (first,last);
    ++first;
  }
}
*/