/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
// 100 % 93.78 %
class Solution
{
public:
    int length(uint num)
    {
        uint clz= 0;
        //统计前导零的个数  巧妙的做法
        if((num>>16) == 0)
        {
            clz+=16;
            num<<=16;
        }
        if ((num >> 24) == 0)
        {
            clz += 8;
            num <<= 8;
        }
        if ((num >> 28) == 0)
        {
            clz += 4;
            num <<= 4;
        }
        if ((num >> 30) == 0)
        {
            clz += 2;
            num <<= 2;
        }
        if ((num >> 31) == 0)
        {
            clz += 1;
        }
        return 32-clz;
    }

    int count(int num)
    {
        // 统计二进制数位 111 的个数 ===> 所有位的值相加的结果
        // 分治，相邻的元素之和来求解！！ 根本想不到好吧
        uint32_t M1 = 0x55555555;  // 01010101010101010101010101010101
        uint32_t M2 = 0x33333333;  // 00110011001100110011001100110011
        uint32_t M4 = 0x0f0f0f0f;  // 00001111000011110000111100001111
        uint32_t M8 = 0x00ff00ff;  // 00000000111111110000000011111111
        uint32_t M16 = 0x0000ffff; // 00000000000000001111111111111111
        num = (num & M1) + ((num>>1) & M1); 
        num = (num & M2) + ((num >> 2) & M2);
        num = (num & M4) + ((num >> 4) & M4);
        num = (num & M8) + ((num >> 8) & M8);
        num = (num & M16) + ((num >> 16) & M16);
        return num;
    }

    int numberOfSteps(int num)
    {
       return num==0?0:length(num)-1+count(num);   
    }
};
// @lc code=end
// 100 % 83.71 %
class Solution
{
public:
    int numberOfSteps(int num)
    {
        int step = 0;
        while (num != 0)
        {
            if (num % 2 == 0)
            {
                num = num / 2;
                step++;
            }
            else
            {
                num -= 1;
                step++;
            }
        }
        return step;
    }
};