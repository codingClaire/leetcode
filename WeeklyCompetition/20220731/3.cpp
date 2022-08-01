class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> list1(n, INT_MAX);
        vector<int> list2(n, INT_MAX);
        int curIndex = node1;
        list1[curIndex] = 0;
        while (curIndex != -1)
        {
            int prev = list1[curIndex];
            curIndex = edges[curIndex];
            if (curIndex != -1 && prev + 1 > list1[curIndex])
                break;
            if (curIndex != -1)
            {
                list1[curIndex] = prev + 1;
            }
        }
        curIndex = node2;
        list2[curIndex] = 0;
        while (curIndex != -1)
        {
            int prev = list2[curIndex];
            curIndex = edges[curIndex];
            if (curIndex != -1 && prev + 1 > list2[curIndex])
                break;
            if (curIndex != -1)
            {
                list2[curIndex] = prev + 1;
            }
        }
        int minvalue = INT_MAX;
        int minindex = -1;
        for (int i = 0; i < n; i++)
        {
            if (list1[i] != INT_MAX && list2[i] != INT_MAX)
            {
                if (max(list1[i], list2[i]) < minvalue)
                {
                    minvalue = max(list1[i], list2[i]);
                    minindex = i;
                }
            }
        }
        return minindex;
    }
};