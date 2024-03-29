好 /*
    * @lc app=leetcode.cn id=190 lang=cpp
    *
    * [190] 颠倒二进制位
    */

    // @lc code=start
    // [190] 颠倒二进制位
    // 100 %  53.41 %
    class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {
            uint32_t curbit = n & 1;
            ans = (ans<<1) + curbit; // 记得ans<<1要加括号
            //cout<<ans<<endl;
            n= n >> 1;          
        }
        return ans;
    }
};

// @lc code=end

// 位运算+分治 100 %  72.59 %
class Solution
{
private:
    const uint32_t M1 = 0x55555555;  // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333;  // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f;  // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff;  // 00000000111111110000000011111111
    const uint32_t M16 = 0x0000ffff; // 00000000000000001111111111111111
public:
    uint32_t reverseBits(uint32_t n)
    {
        //或最后运算  n >> 1 & M1 原来的偶数位到奇数位， (n & M1) << 1 原来的奇数位左移到偶数位，再把两个部分合并
        n = (n >> 1 & M1) | (n & M1) << 1;
        n = (n >> 2 & M2) | (n & M2) << 2;
        n = (n >> 4 & M4) | (n & M4) << 4;
        n = (n >> 8 & M8) | (n & M8) << 8;
        n = (n >> 16 & M16) | (n & M16) << 16;
        return n;
    }
};

// 49.49 %  5.29 %
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {

            ans = ans | (n & 1) << (31 - i);
            n = n >> 1;
        }
        return ans;
    }
};