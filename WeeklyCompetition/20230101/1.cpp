class Solution
{
public:
    int countDigits(int num)
    {
        int res = 0;
        int n = num;
        while (n != 0)
        {
            int curbit = n % 10;
            if (num % curbit == 0)
                res++;
            n = n / 10;
        }
        return res;
    }
};