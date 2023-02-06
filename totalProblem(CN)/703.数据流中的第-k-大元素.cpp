/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest
{
public:
    vector<int> current;
    int times;
    KthLargest(int k, vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](const auto &num1, const auto &num2)
             { return num1 > num2; });
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp++;
            current.emplace_back(nums[i]);
            if (tmp == k)
                break;
        }
        times = k;
    }

    int add(int val)
    {
        bool modify = false;
        int tmp = val;
        for (int i = 0; i < current.size(); i++)
        {
            if (modify == false)
            {
                if (val > current[i])
                {
                    modify = true;
                    tmp = current[i];
                    current[i] = val;
                }
            }
            else
            {
                swap(tmp, current[i]);
            }
        }
        // cout<<tmp<<" size:"<<current.size()<<endl;
        if (current.size() < times)
            current.emplace_back(tmp);
        return current[current.size() - 1];
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
