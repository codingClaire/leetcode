//C solution
/*
int searchInsert(int* nums, int numsSize, int target) 
{
	int po;
    for(int i=0;i<numsSize;i++)
    {
    	if(target<*nums) 
		{
			po=0;	
			break;
		}
		if(target>*(nums+numsSize-1))
		{
			po=numsSize;
			break;
		}
		if(*(nums+i)==target)
    	{
    		po=i;
    		break;
		}
		else if((*(nums+i-1))<target&&(*(nums+i))>target)
		{
			po=i;
		}
	}
	return po;
}
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int searchInsert(vector<int> &nums, int target)
	{
		auto l = lower_bound(nums.begin(), nums.end(), target);
		int leftidx = distance(nums.begin(), l);
		return leftidx;
	}
};

int main()
{
	Solution A;
	vector<int> nums{2, 2};
	int target = 3;
	int l = A.searchInsert(nums, target);
	cout << l << " ";
	return 0;
}