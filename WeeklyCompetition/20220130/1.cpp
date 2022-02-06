class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int>::iterator it=nums.begin();
        int flag=0;
        int start=original;
        while(flag==0)
        {
            while(it!=nums.end())
            {
                if(*it==original)
                {
                    original=original*2;
                    flag=1;
                    break;
                }
                it++;
            }
            if(it==nums.end()&&flag==0)
            {
                return original;
            }
            flag=0;
            it=nums.begin();
        }
        return original;
    }
};