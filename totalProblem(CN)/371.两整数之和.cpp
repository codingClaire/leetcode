// 【371. 两整数之和】
//  100.00% 82.75 %
class Solution
{
public:
    int getSum(int a, int b)
    {
        //while循环里，每一次的carry存储的是上一次加上b之后产生的新的进位
        //b是上一次的carry
        //这个写法巧妙又简洁，值得学习
        while (b != 0)
        {
            //所有a和b的进位结果，与后右移（就像加法竖式进位是在当前侧左侧写一个小1）
            unsigned int carry = (unsigned int)(a & b) << 1;
            // a 和 b 的无进位加法结果
            // 第一次已经异或了完整的b
            //之后，b就会充当carry，每次异或b都是当前的a加上carry的末尾
            cout << carry << " " << a << " " << b << endl;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};