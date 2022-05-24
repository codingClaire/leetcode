/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
//[204] 计数质数
//线性筛
// 5.27 % 5.45 %
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> primeList(n, 1);
        vector<int> primes;
        for (int i = 2; i < n; ++i)
        {
            if (primeList[i])
            {
                primes.emplace_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; j++)
            {
                primeList[i * primes[j]] = 0;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }
};
// @lc code=end

//埃氏筛
// 44.74 % 38.55 %
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> primeList(n, 1);
        int res = 0;
        for (int i = 2; i < n; ++i)
        {
            if (primeList[i])
            {
                res += 1;
                if ((long long)i * i < n)
                {
                    for (int j = i * i; j < n; j += i)
                    {
                        primeList[j] = 0;
                    }
                }
            }
        }
        return res;
    }
};

// TLE Solution
class Solution
{
public:
    bool isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        // 就算这样写，也会TLE:for (int i = 2; i*i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int countPrimes(int n)
    {
        int res = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime(i))
                res++;
        }
        return res;
    }
};