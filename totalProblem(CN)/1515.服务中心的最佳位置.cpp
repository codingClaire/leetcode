/*
 * @lc app=leetcode.cn id=1515 lang=cpp
 *
 * [1515] 服务中心的最佳位置
 */

// @lc code=start
// 梯度下降法 35.95 % 15.73 %
class Solution
{
public:
    double getMinDistSum(vector<vector<int>> &positions)
    {
        double eps = 1e-7;
        double alpha = 1;
        double decay = 1e-3;
        int n = positions.size();
        int batchsize = n;
        // x,y是所有节点的平均值
        double x = 0.0, y = 0.0;
        for(const auto& pos: positions)
        {
            x+=pos[0];
            y+=pos[1];
        }
        x/=n;
        y/=n;

        auto getDist = [&](double xc, double yc)
        {
            double ans = 0;
            for(const auto& pos: positions)
            {
                ans += sqrt((pos[0] - xc) * (pos[0] - xc) + (pos[1] - yc) * (pos[1] - yc));
            }
            return ans;
        };

        mt19937 gen{random_device{}()}; // 随机数算法

        while(true)
        {
            shuffle(positions.begin(), positions.end(), gen);
            double xprev = x;
            double yprev = y;
            for(int i=0;i<n;i+=batchsize)
            {
                int j = min(i+batchsize, n);
                double dx = 0.0, dy =0.0;
                for(int k=i;k<j;k++)
                {
                    const auto& pos = positions[k];
                    dx += (x - pos[0]) / (sqrt((x - pos[0]) * (x - pos[0]) + (y - pos[1]) * (y - pos[1])) + eps);
                    dy += (y - pos[1]) / (sqrt((x - pos[0]) * (x - pos[0]) + (y - pos[1]) * (y - pos[1])) + eps);
                }
                x-= alpha*dx;
                y-=alpha *dy;
                alpha *=(1-decay);
            }
            if(sqrt(x-xprev)*(x-xprev)+(y-yprev)*(y-yprev)<eps)
                break;
        }
        return getDist(x,y);
    }
};
// @lc code=end
