class Solution
{
public:
    int minOperations(int n)
    {
        queue<int> q;
        unordered_set<int> visited;
        int res = 0;
        q.push(n);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                if (curr == 0)
                {
                    return res;
                }
                // 遍历小于curr的每一位的2^k
                for (int k = 0; (1 << k) <= curr; k++)
                {
                    
                    int next2 = curr - (1 << k);
                    if (visited.count(next2) == 0)
                    {
                        q.push(next2);
                        visited.insert(next2);
                    }
                    
                    
                    int next1 = curr + (1 << k);
                    if(curr + (1 << k) > 2*n)
                        continue;
                    if (visited.count(next1) == 0)
                    {
                        q.push(next1);
                        visited.insert(next1);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};