class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        vector<vector<int>> res;
        for(int i=0;i<grid.size()-2;i++)
        {
            vector<int> tmp;
            for(int j=0;j<grid[0].size()-2;j++)
            {
                //find max
                int maxv = INT_MIN;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(grid[k][l]>maxv)
                            maxv = grid[k][l];
                    }
                }
                tmp.emplace_back(maxv);
            }
            res.emplace_back(tmp);            
        }
        return res;
    }
};