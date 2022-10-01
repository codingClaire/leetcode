/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
// 方法三： 二分查找 91.68 % 66.46 %
// 这个真的利用了所有的条件，而且也是效率更高的情况！
class Solution
{
public:
    bool check(vector<vector<int>> &matrix, int mid, int k, int n)
    {
        // 从左下角开始
        int i = n - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < n)
        {
            // 当前数更小就向右，当前数更大就向上
            if (matrix[i][j] <= mid)
            {
                // num用于统计左侧有多少个元素
                num += i + 1;
                j++;
            }
            else
            {
                i--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        // 这个二分有点类似于猜数字然后直到猜中恰好是第k小的数字停止
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

// 方法二： 优先队列&小顶堆 26.38 % 61.49 %
//看成n给有序的一维数组，进而采取归并，利用一个最小堆来优化
// 其实只用到了列递增的条件，行递增其实没差别
// link到第23题的方法三
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        struct point
        {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y){};
            bool operator>(const point &a) const
            {
                return this->val > a.val;
            }
        };
        // priority_queue默认的是降序大顶堆或第三个参数是 less<point> 从大到小
        // 如果要升序小顶堆的话，需要写成greater<point> 从小到大
        priority_queue<point, vector<point>, greater<point>>
            que;
        int n = matrix.size();
        // 放入第一列的元素
        for (int i = 0; i < n; i++)
            que.emplace(matrix[i][0], i, 0);
        // 会pop k次，到第k个数就停止了
        for (int i = 0; i < k - 1; i++)
        {
            // pop当前堆中最小的
            point cur = que.top();
            // cout << cur.val<<" ";
            que.pop();
            // 选择下一列的元素作为候选元素加入队列
            if (cur.y != n - 1)
            {
                que.emplace(matrix[cur.x][cur.y + 1], cur.x, cur.y + 1);
            }
        }
        return que.top().val;
    }
};

// 方法一 排序法： 71.15 % 6.18 %
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        vector<int> seq;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                seq.emplace_back(matrix[i][j]);
            }
        }
        sort(seq.begin(), seq.end());
        return seq[k - 1];
    }
};