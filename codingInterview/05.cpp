class Solution {
public:
    string replaceSpace(string s) 
    {
        int i = 0;
        while(i<s.length())
        {
            if(s[i] ==' ')
            {
                s = s.substr(0,i) +"%20" + s.substr(i+1,s.length());
                i+=2;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};

class Solution
{
public:
    string replaceSpace(string s)
    {
        string array;
        for (auto &c : s)
        {
            if (c == ' ')
            {
                array += "%20";
            }
            else
            {
                array.push_back(c);
            }
        }
        return array;
    }
};