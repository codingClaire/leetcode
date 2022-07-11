/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
//[347] 前 K 个高频元素
// 85.16 % 5.56 %
class Solution {
public:
    void quicksort(vector<pair<int, int>> v, int left, int right, vector<int> &res, int k)
    {
        // [left,right]区间的随机数
        int picked = rand() % (right - left + 1) + left;
        // 先把选择的中间的元素放到最左侧
        swap(v[picked], v[left]);                        
        int pivot = v[left].second;
        int index = left;
        // 找到所有大于该元素的值
        for (int i = left + 1; i <= right; i++)
        {
            if (v[i].second >= pivot)
            {
                swap(v[index + 1], v[i]);
                index++;
            }
        }
        //再把中间元素换回去，这样左侧的所有值都是大于pivot的了
        swap(v[left], v[index]); 
        if (k < index - left)
        { // 左侧元素的个数已经超过k个，继续在左区间找，进行剔除
            quicksort(v, left, index - 1, res, k);
        }
        else
        { //左侧元素的个数还不到k个，需要先保存当前的index，再在右区间找，进行添加
            for (int i = left; i <= index; i++)
            {
                res.emplace_back(v[i].first);
            }
            if (k > index - left + 1)
                quicksort(v, index + 1, right, res, k - (index - left + 1));
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> kvlist;
        for (auto &kv : mp)
            kvlist.emplace_back(kv);
        vector<int> res;
        quicksort(kvlist, 0, kvlist.size() - 1, res, k);
        return res;
    }
};
// @lc code=end

