/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
//[380] O(1) 时间插入、删除和获取随机元素
// 19.87 %  50.54 %
class RandomizedSet
{
private:
    vector<int> nums;
    unordered_map<int, int> mp;

public:
    RandomizedSet()
    {
        srand((unsigned)time(NULL));
        //初始化随机种子,使用 time函数无从参数地来获得系统时间
    }

    bool insert(int val)
    {
        if (!mp.count(val))
        {
            nums.emplace_back(val);
            mp[val] = nums.size() - 1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int val)
    {
        if (!mp.count(val))
        {
            return false;
        }
        else
        {
            int size = nums.size();
            int index = mp[val];
            mp[nums[size - 1]] = index;        //先更新mp
            swap(nums[index], nums[size - 1]); //再交换
            nums.pop_back();
            mp.erase(val);
            return true;
        }
    }

    int getRandom()
    {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
