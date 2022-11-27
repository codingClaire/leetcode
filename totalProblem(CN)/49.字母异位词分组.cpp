/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
//[49] 字母异位词分组
// 77.55 % 78.11 %
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> unordered_mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(),key.end());
            unordered_mp[key].emplace_back(strs[i]);        
        }
        for (auto it = unordered_mp.begin(); it != unordered_mp.end(); it++)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

// @lc code=end
// 92.37 % 14.83 %
//官方题解的理解，结合了评论区大佬的注释，虽然理解了但也没理解，后续慢慢理解吧
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 自定义对 array<int, 26> 类型的哈希函数
        // fn是一个函数: [捕获列表](参数列表)->返回类型-{函数主体}
        auto arrayHash = [fn = hash<int>{}](const array<int, 26> &arr) -> size_t
        {
            // accumulate是一个泛型函数： 从零开始累加arr
            //第四个参数项是一个匿名函数， [&](){ } 表示一个匿名函数，是一个lambda表达式
            // 定义如何进行累加，默认是正常的累加
            //要传入一个二元操作(BinaryOperation)规则，告诉它如何将当前元素与累积量做操作
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num)
                              { return (acc << 1) ^ fn(num); }); // hash运算结果移位相加
        };
        // decltype : 获取表达式的类型。在编译时推导出一个表达式的类型，并且不会计算表达式的值
        /*
            由于key的类型是array<int, 26>，属于用户自定义的一个数据类型
            编译器无法针对用户自定义的数据类型做两个元素是否相等的判断(map容器)
            所以，要告诉unordered_map你是如何确定key与key之间是否冲突(或者是否相等)的
            第三个参数项传入运算规则的函数的类型
            隐式类型（lambda表达式）：借助于decltype获得arrayHash的type
        */
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string &str : strs)
        {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i)
            {
                counts[str[i] - 'a']++;
            }
            // mp[counts]过程就会调用arrayHash计算counts的hash值
            //在哈希表中寻找对应哈希值的键，将对应哈希值的vector<string>加入对应的str
            //这样，map的值就是一个有相同哈希值的字母异位词数组
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

// 5.14 % 5.02 %
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> unordered_mp;
        for (int i = 0; i < strs.size(); i++)
        {
            map<char, int> mp;
            for (int j = 0; j < 26; j++)
                mp.insert(make_pair('a' + j, 0));
            for (int j = 0; j < strs[i].length(); j++)
                mp[strs[i][j]]++;
            string hash = "";
            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                for (int t = 0; t < it->second; t++)
                    hash.append(1, it->first);
            }
            if (unordered_mp.find(hash) == unordered_mp.end())
            {
                vector<int> tmp;
                tmp.emplace_back(i);
                unordered_mp.insert(make_pair(hash, tmp));
            }
            else
            {
                unordered_mp[hash].emplace_back(i);
            }
        }
        for (auto it = unordered_mp.begin(); it != unordered_mp.end(); it++)
        {
            vector<string> tmp;
            for (int i = 0; i < it->second.size(); i++)
            {
                tmp.emplace_back(strs[it->second[i]]);
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};



//二刷  92.51% 15.10%
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        auto arrayHash = [fn= hash<int>{}](const array<int,26>& arr) ->size_t
        {
            return accumulate(arr.begin(),arr.end(),0u, [&](size_t acc,int num)
            {
                return (acc<<1)^fn(num);
            });
        };

       
        unordered_map<array<int,26>,vector<string>,decltype(arrayHash)> mp(0,arrayHash);
        for(auto &str: strs)
        {
            array<int, 26> counts{};
            for(auto &ch: str)
            {
                counts[ch-'a']++;
            }
            mp[counts].emplace_back(str);
        }

        vector<vector<string>> res;
        for(auto it = mp.begin(); it!=mp.end() ;it++)
            res.emplace_back(it->second);
        return res;
        
    }
};