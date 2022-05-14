/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
// [384] 打乱数组
// Fisher-Yates 96.97 % 80.9 %
class Solution
{
public:
    Solution(vector<int> &nums)
    {
        this->shuffle_nums = nums;
        this->origin_nums.resize(nums.size());
        copy(nums.begin(), nums.end(), this->origin_nums.begin());
    }

    vector<int> reset()
    {
        return this->origin_nums;
    }

    vector<int> shuffle()
    {
        int len = this->origin_nums.size();
        for (int i = 0; i < len; i++)
        {
            int j = rand() % (len - i);
            swap(this->shuffle_nums[len - i - 1], this->shuffle_nums[j]);
        }
        return shuffle_nums;
    }

private:
    vector<int> origin_nums;
    vector<int> shuffle_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

// [384] 打乱数组
// Knuth  94.65 % 99.55 %
class Solution
{
public:
    Solution(vector<int> &nums)
    {
        this->shuffle_nums = nums;
        this->origin_nums.resize(nums.size());
        copy(nums.begin(), nums.end(), this->origin_nums.begin());
    }

    vector<int> reset()
    {
        return this->origin_nums;
    }

    vector<int> shuffle()
    {
        int len = this->origin_nums.size();
        for (int i = 0; i < len; i++)
        {
            int j = rand() % (len - i);
            swap(this->shuffle_nums[i], this->shuffle_nums[j]);
        }
        return shuffle_nums;
    }

private:
    vector<int> origin_nums;
    vector<int> shuffle_nums;
};

// [384] 打乱数组
// bruteForce 86.44 % 78.02 %
class Solution
{
public:
    Solution(vector<int> &nums)
    {
        this->shuffle_nums = nums;
        this->origin_nums.resize(nums.size());
        copy(nums.begin(), nums.end(), this->origin_nums.begin());
    }

    vector<int> reset()
    {
        return this->origin_nums;
    }

    vector<int> shuffle()
    {
        vector<int> waiting(this->origin_nums);
        int len = this->origin_nums.size();
        for (int i = 0; i < len; i++)
        {
            int wa_idx = rand() % waiting.size();
            this->shuffle_nums[i] = waiting[wa_idx];
            auto it = waiting.begin();
            advance(it, wa_idx);
            waiting.erase(it);
        }
        return shuffle_nums;
    }

private:
    vector<int> origin_nums;
    vector<int> shuffle_nums;
};