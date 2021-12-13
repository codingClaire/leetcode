class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int len = plants.size();
        int totalnum = 0;
        int curA = capacityA, curB = capacityB;
        for (int i = 0; i <= len / 2; i++)
        {
            if (i == len - i - 1)
            {
                if (curA >= curB)
                {
                    if (plants[i] > curA)
                    {
                        curA = capacityA;
                        totalnum++;
                    }
                    curA -= plants[i];
                }
                else
                {
                    if (plants[i] > curB)
                    {
                        curB = capacityB;
                        totalnum++;
                    }
                    curB -= plants[i];
                }
            }
            else if (len - i - 1 - i >= 1)
            {
                if (plants[i] > curA)
                {
                    curA = capacityA;
                    totalnum++;
                }
                curA -= plants[i];
                if (plants[len - i - 1] > curB)
                {
                    curB = capacityB;
                    totalnum++;
                }
                curB -= plants[len - i - 1];
            }
        }
        return totalnum;
    }
};