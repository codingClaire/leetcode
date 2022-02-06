class Solution
{
public:
    long long smallestNumber(long long num)
    {
        int flag = num < 0 ? 1 : 0;
        string str;
        // long long to string
        ostringstream os;
        os << num;
        istringstream is(os.str());
        is >> str;
        // str to vector<char>
        vector<char> ch(str.size());
        if (num < 0)
            copy(str.begin() + 1, str.end(), ch.begin());
        else
            copy(str.begin(), str.end(), ch.begin());
        // sort
        sort(ch.begin(), ch.end());
        long long res;
        if (num > 0)
        {
            vector<char>::iterator it = ch.begin();
            int spot = 0;
            while (*it == '0')
            {
                it++;
                spot++;
            }
            swap(ch[0], ch[spot]);
            // vector<char> to string
            string tmp = "";
            for (it = ch.begin(); it != ch.end(); it++)
            {
                tmp += *it;
            }
            res = atoll(tmp.c_str());
        }
        else if (num < 0)
        {
            string tmp = "-";
            for (int i = ch.size() - 1; i >= 0; i--)
            {
                tmp += ch[i];
            }
            res = atoll(tmp.c_str());
        }
        else if (num == 0)
        {
            res = num;
        }
        return res;
    }
};