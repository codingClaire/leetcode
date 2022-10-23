//10.46% 77.13%暴力即可，我服了
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++)
        {
            if(i+turn(i)==num)
                return true;
        }
        return false;
    }
     int turn(int num)//翻转
    {
        string temp=to_string(num);
        reverse(temp.begin(),temp.end());
        return stoi(temp);
    }
};