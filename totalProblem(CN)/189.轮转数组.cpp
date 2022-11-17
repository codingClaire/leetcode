/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
// 法二 环状替代 8.73% 67.06 %
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k%n;
        int count = gcd(k,n);
        for(int start=0;start<count;start++)
        {
            int current = start;
            int prev = nums[start];
            do
            {
                int next =(current+k)%n;
                swap(nums[next],prev);
                current = next;
            } while (start!=current); 
        }
    }
};
// @lc code=end
//法一：哈希表法
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        vector<int> newarray(len);
        for (int i = 0; i < len; i++)
        {
            // 新数组的下标是(i+k) % len，类似哈希的思想，很巧妙
            newarray[(i + k) % len] = nums[i];
        }
        nums.assign(newarray.begin(), newarray.end());
    }
};

// 法三 数组翻转法（用两只手比一比） 91.41% 55.75%
class Solution
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

/* TLE解法！！
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        while (k > len)
            k -= len;
        for (int i = len - k; i < len; i++)
        {
            nums.insert(nums.begin() + i - len + k, nums[i]);
            nums.erase(nums.begin() + i + 1);
        }
    }
};
*/