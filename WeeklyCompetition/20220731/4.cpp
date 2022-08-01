class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        int length = 0;
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            int curIndex = i;
            // cout<<"Situation:"<<i<<endl;
            if (edges[curIndex] != -1)
            {
                int start = curIndex;
                int k = 0;
                while (curIndex != -1)
                {
                    // cout<<curIndex<<" "<<edges[curIndex]<<endl;
                    curIndex = edges[curIndex];

                    k++;
                    if (k > n)
                        break;
                    if (curIndex == start)
                    {
                        int tmp = start;
                        for (int j = 0; j < k; j++)
                        {
                            int next = edges[tmp];
                            edges[tmp] = -1;
                            tmp = next;
                        }

                        length = max(length, k);
                        break;
                    }
                }
            }
        }
        return length == 0 ? -1 : length;
    }
};