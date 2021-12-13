class Solution
{
public:
    int countPoints(string rings)
    {
        int len = rings.length();
        unordered_map<char, int> mp = {{'R', 0}, {'G', 1}, {'B', 2}};
        int maxN = 10;
        vector<string> res(maxN, "000");
        int res_num = 0;
        for (int i = 0; i < len - 1; i += 2)
        {
            int c = mp[rings[i]];
            int r = int(rings[i + 1] - '0');
            //cout<<c<<" "<<r<<" "<<rings[i+1]<<endl;
            res[r][c] = '1';
        }
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == "111")
                res_num++;
        }
        return res_num;
    }
};