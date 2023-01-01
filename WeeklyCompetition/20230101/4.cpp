class Solution
{
public:
    bool isPrime(int x)
    {
        if (x == 1)
            return false;
        for (int i = 2; i <= int(sqrt(x)); i++)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> res = {-1, -1};
        int a = -1, b = -1;
        bool isa = true;
        int minlen = right - left + 1;
        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
            {
                if (isa == true)
                {
                    a = i;
                    isa = false;
                }
                else
                {
                    b = i;
                    isa = true;
                }
            }
            if (a != -1 && b != -1 && abs(a - b) < minlen)
            {
                minlen = abs(a - b);
                res[0] = min(a, b);
                res[1] = max(a, b);
            }
            if (minlen == 1)
                break;
        }
        return res;
    }
};